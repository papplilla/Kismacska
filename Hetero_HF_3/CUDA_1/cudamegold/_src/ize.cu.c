#include <stdio.h>   
#include "time.h"
#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"
#include "func.h"
#include "cuda_runtime.h"
#include "cuda.h"
#include "device_launch_parameters.h"
#include "cuda_runtime_api.h"
#include <device_functions.h>

__global__ void kernel_conv_sh_float_float(unsigned char* gInput, unsigned char*
	gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;

	int out_pix = (row*imgWidth + col) * 3;
	float pix_data[3][25] = { 0.0f, 0.0f, 0.0f };

	__shared__ float in_shmem[20][20][3];
	int thid_1d = threadIdx.y*blockDim.x + threadIdx.x;
	int ld_rgba = thid_1d % 3;
	int ld_col = (thid_1d / 3) % 20;
	int ld_row = thid_1d / 60;
	int ld_base = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x *
		blockDim.x) * 3 + (ld_row * 3 * imgWidthF);
	if (thid_1d < 3 * 20 * 4)
	{
#pragma unroll
		for (int ld = 0; ld < 5; ld++)
		{
			in_shmem[ld_row + ld * 4][ld_col][ld_rgba] =
				(float)(gInput[ld_base + (thid_1d % 60)]);
			ld_base = ld_base + imgWidthF * 3 * 4;
		}
	}
	__syncthreads();
#pragma unroll 5
	for (int fy = 0; fy < 5; fy++)
	{
#pragma unroll 5
		for (int fx = 0; fx < 5; fx++)
		{
			16
#pragma unroll
				for (int rgba = 0; rgba < 3; rgba++)
				{
					//float pix = in_shmem[threadIdx.y + fy][threadIdx.x+fx][rgba];
					pix_data[rgba][fy * 5 + fx] = in_shmem[threadIdx.y + fy][threadIdx.x + fx][rgba];
				}
		}
	}
}

void cudaMain(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF,
	int imgFOfssetH, int imgFOfssetW,
	unsigned char *imgSrc, unsigned char *imgDst)
{
	double s0, e0;
	double d0;

	int size_in = imgWidthF * imgHeightF * sizeof(unsigned char) * 3;
	int size_out = imgWidth * imgHeight * sizeof(unsigned char) * 3;

	unsigned char *gInput, *gOutput;
	cudaMalloc((void**)&gInput, size_in);
	cudaMalloc((void**)&gOutput, size_out);

	dim3 thrBlock(16, 16);
	dim3 thrGrid(imgWidth / 16, imgHeight / 16);

	dim3 thrBlock2(32, 8);
	dim3 thrGrid2(imgWidth / 32, imgHeight / 8);


	cudaMemcpy(gInput, imgSrc, size_in, cudaMemcpyHostToDevice);
	cudaDeviceSetCacheConfig(cudaFuncCachePreferShared);

	s0 = time_measure(1);

	kernel_conv_sh_float_float << <thrGrid, thrBlock >> > (gInput, gOutput,imgWidth, imgWidthF);

	cudaThreadSynchronize();

		e0 = time_measure(2);
	cudaMemcpy(imgDst, gOutput, size_out, cudaMemcpyDeviceToHost);
	cudaFree(gInput); cudaFree(gOutput);
	cudaDeviceReset();
	d0 = (double)(e0 - s0) / (CLOCKS_PER_SEC*KERNEL_RUNS);
	double mpixel = (imgWidth*imgHeight / d0) / 1000000;
	printf("CUDA single kernel time: %4.4f\n", d0);
	printf("CUDA Mpixel/s: %4.4f\n", mpixel);
}