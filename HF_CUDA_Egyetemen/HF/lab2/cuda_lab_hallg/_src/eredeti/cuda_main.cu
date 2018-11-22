#include <stdio.h>   
#include "time.h"
#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"
#include "func.h"

#include <cuda_runtime.h>

__constant__ int filter_laplace[5][5] = { -1, -1, -1, -1, -1,
										 -1, -1, -1, -1, -1,
										 -1, -1, 24, -1, -1,
										 -1, -1, -1, -1, -1,
										 -1, -1, -1, -1, -1 };

__constant__ float filter_laplace_f[5][5] = { -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
											 -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
											 -1.0f, -1.0f, 24.0f, -1.0f, -1.0f,
											 -1.0f, -1.0f, -1.0f, -1.0f, -1.0f,
											 -1.0f, -1.0f, -1.0f, -1.0f, -1.0f };


// Glob�lis mem�ri�t haszn�l� (trivi�lis) megold�s
__global__ void kernel_conv_global(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;

	int rd_base = (row * imgWidthF  +col)*3;
	int wr_base = (row*imgWidth+col) * 3;

	short fval[3] = { 0,0,0 };
	int rd_offset = 0;
	for (int fy = 0; fy<FILTER_H; fy++)
	{
		for (int fx = 0; fx<FILTER_W; fx++)									
		{
			for (int rgba = 0; rgba<3; rgba++)									// szinek
			{
				int pixel_src = rd_base + rd_offset;
				fval[rgba] = fval[rgba] + filter_laplace[fy][fx] * (short)(*(gInput + pixel_src + rgba));
				
			}
			rd_offset = rd_offset + 3;
		}
		rd_offset = rd_offset - 5 * 3 + imgWidthF * 3;

	}

	for (int rgba = 0; rgba<3; rgba++)
	{
		if (fval[rgba]>255)
			fval[rgba] = 255;
		else if (fval[rgba]<0)  
			fval[rgba] = 0;
	}

	for (int rgba = 0; rgba<3; rgba++)
	{
		*(gOutput + wr_base + rgba) = (unsigned char)(fval[rgba]);
	}



}

// Shared mem�ri�t haszn�l� megold�s (1.)
// Shared mem�ria adatt�pus: unsigned char
// Sz�m�t�s adatt�pusa: integer
__global__ void kernel_conv_sh_uchar_int(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  

  int th1D = threadIdx.y * blockDim.x + threadIdx.x;		// sz�l sz�ma
  int rx = blockIdx.x * blockDim.x;
  int ry = blockIdx.y * blockDim.y;

  int base = (ry*imgWidthF + rx) * 3;

  int wr_x, int wr_y;
  

  __shared__ unsigned char tomb[20][60];

 
	 
	// bet�lt�s
	  if (th1D < 240)
	  {
		  for (int i = 0; i < 5; i++)
		  {
			  wr_y = 4 * i + th1D / 60;
			  wr_x = th1D % 60;
			  tomb[wr_y][wr_x] = *(gInput + base + wr_y*imgWidthF + wr_x);
		  }
	  }

	  // sz�lak szinkroniz�l�sa
	  __syncthreads();


	  // konvol�ci�
	  //int rd_base = (row * imgWidthF + col) * 3;
	  int wr_base = (row*imgWidth + col) * 3;

	  short fval[3] = { 0,0,0 };
	  int rd_offset = 0;

	  for (int fy = 0; fy<FILTER_H; fy++)
	  {
		  for (int fx = 0; fx<FILTER_W; fx++)
		  {
			  for (int rgba = 0; rgba<3; rgba++)									// szinek
			  {
				  //int pixel_src = rd_base + rd_offset;
				  //fval[rgba] = fval[rgba] + filter_laplace[fy][fx] * (short)(*(gInput + pixel_src + rgba));

				  //fval[rgba] = fval[rgba] + filter_laplace[fy][fx] * (short)(*(tomb + pixel_src + rgba));
				  fval[rgba] = fval[rgba] + tomb[threadIdx.y + fy][threadIdx.x*3 + rgba + fx] * filter_laplace[fy][fx];
			  }
			  rd_offset = rd_offset + 3;
		  }
		  rd_offset = rd_offset - 5 * 3 + imgWidthF * 3;

	  }

	  for (int rgba = 0; rgba<3; rgba++)
	  {
		  if (fval[rgba]>255)
			  fval[rgba] = 255;
		  else if (fval[rgba]<0)
			  fval[rgba] = 0;
	  }

	  for (int rgba = 0; rgba<3; rgba++)
	  {
		  *(gOutput + wr_base + rgba) = (unsigned char)(fval[rgba]);
	  }

}


// Shared mem�ri�t haszn�l� megold�s (2.)
// Shared mem�ria adatt�pus: unsigned char
// Sz�m�t�s adatt�pusa: float
// A t�lt�s t�mb indexel�s helyett pointer + offset megold�ssal
__global__ void kernel_conv_sh_uchar_float(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;

}

// Shared mem�ri�t haszn�l� megold�s (3.)
// Shared mem�ria adatt�pus: float
// Sz�m�t�s adatt�pusa: float
__global__ void kernel_conv_sh_float_float(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;






}

// Ugyanaz mint az el�bb, m�dos�tott blokk m�retekkel (32x8) az olvas�si shared memory bank konfliktus elker�l�s�hez
__global__ void kernel_conv_sh_float_float_nbc(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;






}



void cudaMain(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF,
	          unsigned char *imgSrc, unsigned char *imgDst)

{
    double s0, e0;
    double d0;

	unsigned char *gInput, *gOutput;
	// GPU global memory foglal�s a bemeneti (kiterjesztett) k�pnek
    int size_in  = imgWidthF*imgHeightF*sizeof(unsigned char) * 3;
	cudaMalloc((void**)&gInput, size_in);
	// GPU global memory foglal�s a kimeneti (nem kiterjesztett) k�pnek
	int size_out = imgWidth*imgHeight*sizeof(unsigned char) * 3;
	cudaMalloc((void**)&gOutput, size_out);
    
	// 16x16 sz�las thread block
	dim3 thrBlock(16, 16);
    dim3 thrGrid(imgWidth/16, imgHeight/16);

	// 32x8 sz�las thread block
	dim3 thrBlock2(32, 8);
	dim3 thrGrid2(imgWidth / 32, imgHeight / 8);


	// bemeneti k�p m�sol�sa host --> GPU
	cudaMemcpy(gInput, imgSrc, size_in, cudaMemcpyHostToDevice); 

	// L1/Shared memory konfigur�ci�: sok cache
	cudaDeviceSetCacheConfig(cudaFuncCachePreferL1);
	
	// L1/Shared memory konfigur�ci�: sok cache
	//cudaDeviceSetCacheConfig(cudaFuncCachePreferShared);
	
	s0 = time_measure(1);
	for (int i = 0; i < KERNEL_RUNS; i++)
	{
		//kernel_conv_global << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		kernel_conv_sh_uchar_int << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		//kernel_conv_sh_uchar_float << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		//kernel_conv_sh_float_float << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		//kernel_conv_sh_float_float_nbc << <thrGrid2, thrBlock2 >> >(gInput, gOutput, imgWidth, imgWidthF);
	}
	cudaThreadSynchronize();
	e0 = time_measure(2);

	// Kimenet m�sol�s: GPU --> host
    cudaMemcpy(imgDst, gOutput, size_out, cudaMemcpyDeviceToHost);
	
	// GPU mem�ri�k felszabad�t�sa
    cudaFree(gInput); cudaFree(gOutput);

	// Reset (profiler miatt)
	cudaDeviceReset();

    d0 = (double)(e0-s0)/(CLOCKS_PER_SEC*KERNEL_RUNS);
	double mpixel = (imgWidth*imgHeight / d0) / 1000000;
    printf("CUDA single kernel time: %4.4f\n", d0);
	printf("CUDA Mpixel/s: %4.4f\n", mpixel);
}