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


__constant__ int filter_laplace[5][5] = {-1, -1, -1, -1, -1,
                                         -1, -1, -1, -1, -1,
                                         -1, -1, 24, -1, -1,
                                         -1, -1, -1, -1, -1,
                                         -1, -1, -1, -1, -1};

__constant__ float filter_laplace_f[5][5] = {-1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                             -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                             -1.0f, -1.0f, 24.0f, -1.0f, -1.0f,
                                             -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
                                             -1.0f, -1.0f, -1.0f, -1.0f, -1.0f};


// Globális memóriát használó (triviális) megoldás
__global__ void kernel_conv_global(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  
  int out_pix = (row*imgWidth+col)*3;
  int pix_data[3] = {0, 0, 0};

  int in_pix = (row*imgWidthF + col)*3;
  #pragma unroll 5
  for (int fy=0; fy<5; fy++)
  {
      #pragma unroll 5
      for (int fx=0; fx<5; fx++)
      {
          #pragma unroll
          for (int rgba=0; rgba<3; rgba++)
          {
              pix_data[rgba] = pix_data[rgba] + (gInput[in_pix+rgba]*filter_laplace[fy][fx]);
          }
          in_pix=in_pix+3;
      }
      in_pix = in_pix + 3*imgWidthF - 5*1*3;
  }

  for (int rgba=0; rgba<3; rgba++)
  {
      pix_data[rgba] = min(pix_data[rgba], 255);
      pix_data[rgba] = max(pix_data[rgba],   0);
      gOutput[out_pix+rgba] = (unsigned char)(pix_data[rgba]);
  }
}

// Shared memóriát használó megoldás (1.)
// Shared memória adattípus: unsigned char
// Számítás adattípusa: integer
__global__ void kernel_conv_sh_uchar_int(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  
  int out_pix = (row*imgWidth+col)*3;
  int pix_data[3] = {0, 0, 0};

  __shared__ unsigned char in_shmem[20][20][3];

  int thid_1d = threadIdx.y*blockDim.x + threadIdx.x;
  int ld_rgba = thid_1d%3;
  int ld_col  = (thid_1d/3)%20;
  int ld_row  = thid_1d / 60;
  int ld_base = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x * blockDim.x) * 3 + (ld_row * 3 * imgWidthF);
  if (thid_1d<(3*20*4))
  {
	  #pragma unroll
	  for (int ld=0; ld<5; ld++)
	  {
		  in_shmem[ld_row + ld * 4][ld_col][ld_rgba] = gInput[ld_base + (thid_1d % 60)];
		  ld_base = ld_base + imgWidthF*3*4;
	  }
  }
__syncthreads();

  #pragma unroll 5
  for (int fy=0; fy<5; fy++)
  {
      #pragma unroll 5
      for (int fx=0; fx<5; fx++)
      {
		  int coeff =  filter_laplace[fy][fx];
          #pragma unroll 3
          for (int rgba=0; rgba<3; rgba++)
          {
			  int pix = (int)(in_shmem[threadIdx.y+fy][threadIdx.x+fx][rgba]);
              pix_data[rgba] = pix_data[rgba] + (coeff * pix);
          }
      }
  }

  for (int rgba=0; rgba<3; rgba++)
  {
      pix_data[rgba] = min(pix_data[rgba], 255);
      pix_data[rgba] = max(pix_data[rgba],   0);
	  gOutput[out_pix + rgba] = (unsigned char)(pix_data[rgba]);
  }
}

// Shared memóriát használó megoldás (2.)
// Shared memória adattípus: unsigned char
// Számítás adattípusa: float
// A töltés tömb indexelés helyett pointer + offset megoldással
__global__ void kernel_conv_sh_uchar_float(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;

	int out_pix = (row*imgWidth + col) * 3;
	float pix_data[3] = { 0.0f, 0.0f, 0.0f };

	__shared__ unsigned char in_shmem[20][20][3];

	int thid_1d = threadIdx.y*blockDim.x + threadIdx.x;
	int ld_row = thid_1d / 60;
	int ld_addr = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x * blockDim.x) * 3 + (ld_row * 3 * imgWidthF) + (thid_1d % 60);
	int smem_addr = thid_1d;
	unsigned char *smem_base_addr = &in_shmem[0][0][0];
	if (thid_1d<3 * 20 * 4)
	{
#pragma unroll
		for (int ld = 0; ld<5; ld++)
		{
			
			*(smem_base_addr + smem_addr) = gInput[ld_addr];
			ld_addr = ld_addr + imgWidthF * 3 * 4;
			smem_addr = smem_addr + 4 * 60;
		}
	}
__syncthreads();

#pragma unroll 5
	for (int fy = 0; fy<5; fy++)
	{
#pragma unroll 5
		for (int fx = 0; fx<5; fx++)
		{
			float coeff = filter_laplace_f[fy][fx];
#pragma unroll 3
			for (int rgba = 0; rgba<3; rgba++)
			{
				float pix = (float)(in_shmem[threadIdx.y + fy][threadIdx.x + fx][rgba]);
				pix_data[rgba] = pix_data[rgba] + (coeff * pix);
			}
		}
	}

	for (int rgba = 0; rgba<3; rgba++)
	{
		pix_data[rgba] = min(pix_data[rgba], 255.0f);
		pix_data[rgba] = max(pix_data[rgba], 0.0f);
		gOutput[out_pix + rgba] = (unsigned char)(pix_data[rgba]);
	}
}

// Shared memóriát használó megoldás (3.)
// Shared memória adattípus: float
// Számítás adattípusa: float
__global__ void kernel_conv_sh_float_float(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;

	int out_pix = (row*imgWidth + col) * 3;
	float pix_data[3] = { 0.0f, 0.0f, 0.0f };

	__shared__ float in_shmem[20][20][3];

	int thid_1d = threadIdx.y*blockDim.x + threadIdx.x;
	int ld_rgba = thid_1d % 3;
	int ld_col = (thid_1d / 3) % 20;
	int ld_row = thid_1d / 60;
	int ld_base = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x * blockDim.x) * 3 + (ld_row * 3 * imgWidthF);
	if (thid_1d<3 * 20 * 4)
	{
#pragma unroll
		for (int ld = 0; ld<5; ld++)
		{
			in_shmem[ld_row + ld * 4][ld_col][ld_rgba] = (float)(gInput[ld_base + (thid_1d % 60)]);
			ld_base = ld_base + imgWidthF * 3 * 4;
		}
	}
	__syncthreads();

#pragma unroll 5
	for (int fy = 0; fy<5; fy++)
	{
#pragma unroll 5
		for (int fx = 0; fx<5; fx++)
		{
			float coeff = filter_laplace_f[fy][fx];
#pragma unroll
			for (int rgba = 0; rgba<3; rgba++)
			{
				float pix = in_shmem[threadIdx.y + fy][threadIdx.x + fx][rgba];
				pix_data[rgba] = pix_data[rgba] + (coeff * pix);
			}
		}
	}

	for (int rgba = 0; rgba<3; rgba++)
	{
		pix_data[rgba] = min(pix_data[rgba], 255.0f);
		pix_data[rgba] = max(pix_data[rgba], 0.0f);
		gOutput[out_pix + rgba] = (unsigned char)(pix_data[rgba]);
	}
}

// Ugyanaz mint az elõbb, módosított blokk méretekkel (32x8) az olvasási shared memory bank konfliktus elkerüléséhez
__global__ void kernel_conv_sh_float_float_nbc(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;

	int out_pix = (row*imgWidth + col) * 3;
	float pix_data[3] = { 0.0f, 0.0f, 0.0f };

	__shared__ float in_shmem[8+4][32+4][3];

	int thid_1d = threadIdx.y*blockDim.x + threadIdx.x;
	int ld_rgba = thid_1d % 3;
	int ld_col = (thid_1d / 3) % (32+4);
	int ld_row = thid_1d / (3*(32+4));
	int ld_base = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x * blockDim.x) * 3 + (ld_row * 3 * imgWidthF);
	if (thid_1d<(2*3*(32+4)))
	{
#pragma unroll
		for (int ld = 0; ld<6; ld++)
		{
			in_shmem[ld_row + ld * 2][ld_col][ld_rgba] = (float)(gInput[ld_base + (thid_1d % (3 * (32 + 4)))]);
			ld_base = ld_base + imgWidthF * 3 * 2;
		}
	}
	__syncthreads();

#pragma unroll 5
	for (int fy = 0; fy<5; fy++)
	{
#pragma unroll 5
		for (int fx = 0; fx<5; fx++)
		{
			float coeff = filter_laplace_f[fy][fx];
#pragma unroll
			for (int rgba = 0; rgba<3; rgba++)
			{
				float pix = in_shmem[threadIdx.y + fy][threadIdx.x + fx][rgba];
				pix_data[rgba] = pix_data[rgba] + (coeff * pix);
			}
		}
	}

	for (int rgba = 0; rgba<3; rgba++)
	{
		pix_data[rgba] = min(pix_data[rgba], 255.0f);
		pix_data[rgba] = max(pix_data[rgba], 0.0f);
		gOutput[out_pix + rgba] = (unsigned char)(pix_data[rgba]);
	}
}



void cudaMain(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF,
			  int imgFOfssetH, int imgFOfssetW,
			  unsigned char *imgSrc, unsigned char *imgDst)

{
    double s0, e0;
    double d0;


    int size_in  = imgWidthF*imgHeightF*sizeof(unsigned char) * 3;
	int size_out = imgWidth*imgHeight*sizeof(unsigned char) * 3;

    unsigned char *gInput, *gOutput;
	cudaMalloc((void**)&gInput, size_in);
	cudaMalloc((void**)&gOutput, size_out);

	dim3 thrBlock(16, 16);
    dim3 thrGrid(imgWidth/16, imgHeight/16);

	dim3 thrBlock2(32, 8);
	dim3 thrGrid2(imgWidth / 32, imgHeight / 8);

	cudaMemcpy(gInput, imgSrc, size_in, cudaMemcpyHostToDevice); 

	cudaDeviceSetCacheConfig(cudaFuncCachePreferShared);
	s0 = time_measure(1);
	for (int i = 0; i < KERNEL_RUNS; i++)
	{
		//kernel_conv_global << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		//kernel_conv_sh_uchar_int << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		//kernel_conv_sh_uchar_float << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		//kernel_conv_sh_float_float << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		kernel_conv_sh_float_float_nbc << <thrGrid2, thrBlock2 >> >(gInput, gOutput, imgWidth, imgWidthF);
	}
	cudaThreadSynchronize();
	e0 = time_measure(2);

    cudaMemcpy(imgDst, gOutput, size_out, cudaMemcpyDeviceToHost);
	
    cudaFree(gInput); cudaFree(gOutput);

	cudaDeviceReset();

    d0 = (double)(e0-s0)/(CLOCKS_PER_SEC*KERNEL_RUNS);
	double mpixel = (imgWidth*imgHeight / d0) / 1000000;
    printf("CUDA single kernel time: %4.4f\n", d0);
	printf("CUDA Mpixel/s: %4.4f\n", mpixel);
}