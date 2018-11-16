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



void mergeSort(float * arr);

/*
inline void cmpswap2(int a, int b, float * arr)
{
float buf1 = arr[a];
float buf2 = arr[b];
arr[a] = std::max(buf1, buf2);
arr[b] = std::min(buf1, buf2);
}*/


#define PIXEL_COMPARE_AND_SWAP(x, y) if(arr[(x)] > arr[(y)]) { tmp = arr[(y)];arr[(y)] = arr[(x)];arr[(x)] = tmp;	}	


//__inline__ __device__ void mergeSort(unsigned char * arr)
__inline__ __device__ void mergeSort(float * arr)
{
	float tmp;
	// 4x4
	PIXEL_COMPARE_AND_SWAP(0, 1);
	PIXEL_COMPARE_AND_SWAP(2, 3);
	PIXEL_COMPARE_AND_SWAP(0, 2);
	PIXEL_COMPARE_AND_SWAP(1, 3);
	PIXEL_COMPARE_AND_SWAP(1, 2);
	//printf("Hello");
	PIXEL_COMPARE_AND_SWAP(4, 5);
	PIXEL_COMPARE_AND_SWAP(6, 7);
	PIXEL_COMPARE_AND_SWAP(4, 6);
	PIXEL_COMPARE_AND_SWAP(5, 7);
	PIXEL_COMPARE_AND_SWAP(5, 6);

	PIXEL_COMPARE_AND_SWAP(0, 4);
	PIXEL_COMPARE_AND_SWAP(1, 5);
	PIXEL_COMPARE_AND_SWAP(2, 6);
	PIXEL_COMPARE_AND_SWAP(3, 7);

	PIXEL_COMPARE_AND_SWAP(2, 4);
	PIXEL_COMPARE_AND_SWAP(3, 5);

	PIXEL_COMPARE_AND_SWAP(1, 2);
	PIXEL_COMPARE_AND_SWAP(3, 4);
	PIXEL_COMPARE_AND_SWAP(5, 6);

	// 4x4	
	PIXEL_COMPARE_AND_SWAP(8, 9);
	PIXEL_COMPARE_AND_SWAP(10, 11);
	PIXEL_COMPARE_AND_SWAP(8, 10);
	PIXEL_COMPARE_AND_SWAP(9, 11);
	PIXEL_COMPARE_AND_SWAP(9, 10);

	PIXEL_COMPARE_AND_SWAP(12, 13);
	PIXEL_COMPARE_AND_SWAP(14, 15);
	PIXEL_COMPARE_AND_SWAP(12, 14);
	PIXEL_COMPARE_AND_SWAP(13, 15);
	PIXEL_COMPARE_AND_SWAP(13, 14);

	PIXEL_COMPARE_AND_SWAP(8, 12);
	PIXEL_COMPARE_AND_SWAP(9, 13);
	PIXEL_COMPARE_AND_SWAP(10, 14);
	PIXEL_COMPARE_AND_SWAP(11, 15);

	PIXEL_COMPARE_AND_SWAP(10, 12);
	PIXEL_COMPARE_AND_SWAP(11, 13);

	PIXEL_COMPARE_AND_SWAP(9, 10);
	PIXEL_COMPARE_AND_SWAP(11, 12);
	PIXEL_COMPARE_AND_SWAP(13, 14);


	PIXEL_COMPARE_AND_SWAP(0, 8);
	PIXEL_COMPARE_AND_SWAP(1, 9);
	PIXEL_COMPARE_AND_SWAP(2, 10);
	PIXEL_COMPARE_AND_SWAP(3, 11);
	PIXEL_COMPARE_AND_SWAP(4, 12);
	PIXEL_COMPARE_AND_SWAP(5, 13);
	PIXEL_COMPARE_AND_SWAP(6, 14);
	PIXEL_COMPARE_AND_SWAP(7, 15);


	PIXEL_COMPARE_AND_SWAP(4, 8);
	PIXEL_COMPARE_AND_SWAP(5, 9);
	PIXEL_COMPARE_AND_SWAP(6, 10);
	PIXEL_COMPARE_AND_SWAP(7, 11);

	PIXEL_COMPARE_AND_SWAP(2, 4);
	PIXEL_COMPARE_AND_SWAP(3, 5);
	PIXEL_COMPARE_AND_SWAP(6, 8);
	PIXEL_COMPARE_AND_SWAP(7, 9);
	PIXEL_COMPARE_AND_SWAP(10, 12);
	PIXEL_COMPARE_AND_SWAP(11, 13);

	PIXEL_COMPARE_AND_SWAP(1, 2);
	PIXEL_COMPARE_AND_SWAP(3, 4);
	PIXEL_COMPARE_AND_SWAP(5, 6);
	PIXEL_COMPARE_AND_SWAP(7, 8);
	PIXEL_COMPARE_AND_SWAP(9, 10);
	PIXEL_COMPARE_AND_SWAP(11, 12);
	PIXEL_COMPARE_AND_SWAP(13, 14);

	// Eddig 8x8-as (16 bemenet)

	//4x4
	PIXEL_COMPARE_AND_SWAP(16, 17);
	//PIXEL_COMPARE_AND_SWAP(18, 19);
	//PIXEL_COMPARE_AND_SWAP(20, 21);
	//PIXEL_COMPARE_AND_SWAP(22, 23);

	PIXEL_COMPARE_AND_SWAP(16, 18);
	//PIXEL_COMPARE_AND_SWAP(20, 22);
	PIXEL_COMPARE_AND_SWAP(17, 19);
	//PIXEL_COMPARE_AND_SWAP(21, 23);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	//PIXEL_COMPARE_AND_SWAP(21, 22);


	PIXEL_COMPARE_AND_SWAP(16, 20);
	PIXEL_COMPARE_AND_SWAP(17, 21);
	//PIXEL_COMPARE_AND_SWAP(18, 22);
	//PIXEL_COMPARE_AND_SWAP(19, 23);

	//PIXEL_COMPARE_AND_SWAP(18, 20);
	//PIXEL_COMPARE_AND_SWAP(19, 21);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	//PIXEL_COMPARE_AND_SWAP(19, 20);
	//PIXEL_COMPARE_AND_SWAP(21, 22);


	PIXEL_COMPARE_AND_SWAP(16, 24);

	//PIXEL_COMPARE_AND_SWAP(20, 24);

	//PIXEL_COMPARE_AND_SWAP(18, 20);
	//PIXEL_COMPARE_AND_SWAP(19, 21);
	//PIXEL_COMPARE_AND_SWAP(22, 24);

	//cmpswap(19, 21);
	PIXEL_COMPARE_AND_SWAP(17, 18);
	//PIXEL_COMPARE_AND_SWAP(19, 20);
	//PIXEL_COMPARE_AND_SWAP(21, 22);
	//PIXEL_COMPARE_AND_SWAP(23, 24);
	//Eddig egy 8x8-as (De ez csak 9 bemenet)

	// 16x16 
	PIXEL_COMPARE_AND_SWAP(0, 16);
	PIXEL_COMPARE_AND_SWAP(1, 17);
	PIXEL_COMPARE_AND_SWAP(2, 18);
	PIXEL_COMPARE_AND_SWAP(3, 19);
	PIXEL_COMPARE_AND_SWAP(4, 20);
	PIXEL_COMPARE_AND_SWAP(5, 21);
	PIXEL_COMPARE_AND_SWAP(6, 22);
	PIXEL_COMPARE_AND_SWAP(7, 23);
	PIXEL_COMPARE_AND_SWAP(8, 24);


	PIXEL_COMPARE_AND_SWAP(8, 16);
	PIXEL_COMPARE_AND_SWAP(9, 17);
	PIXEL_COMPARE_AND_SWAP(10, 18);
	PIXEL_COMPARE_AND_SWAP(11, 19);
	PIXEL_COMPARE_AND_SWAP(12, 20);
	PIXEL_COMPARE_AND_SWAP(13, 21);
	//PIXEL_COMPARE_AND_SWAP(14, 22);
	//PIXEL_COMPARE_AND_SWAP(15, 23);


	PIXEL_COMPARE_AND_SWAP(4, 8);
	PIXEL_COMPARE_AND_SWAP(5, 9);
	PIXEL_COMPARE_AND_SWAP(6, 10);
	PIXEL_COMPARE_AND_SWAP(7, 11);

	PIXEL_COMPARE_AND_SWAP(12, 16);
	PIXEL_COMPARE_AND_SWAP(13, 17);
	//PIXEL_COMPARE_AND_SWAP(14, 18);
	//PIXEL_COMPARE_AND_SWAP(15, 19);

	PIXEL_COMPARE_AND_SWAP(20, 21);


	PIXEL_COMPARE_AND_SWAP(2, 4);
	PIXEL_COMPARE_AND_SWAP(3, 5);
	PIXEL_COMPARE_AND_SWAP(6, 8);
	PIXEL_COMPARE_AND_SWAP(7, 9);
	PIXEL_COMPARE_AND_SWAP(10, 12);
	PIXEL_COMPARE_AND_SWAP(11, 13);



	PIXEL_COMPARE_AND_SWAP(1, 2);
	PIXEL_COMPARE_AND_SWAP(3, 4);
	PIXEL_COMPARE_AND_SWAP(5, 6);
	PIXEL_COMPARE_AND_SWAP(7, 8);
	PIXEL_COMPARE_AND_SWAP(9, 10);
	PIXEL_COMPARE_AND_SWAP(11, 12);
}

__inline__ __device__ void mergeSort(unsigned char * arr)
{
	float tmp;
	// 4x4
	PIXEL_COMPARE_AND_SWAP(0, 1);
	PIXEL_COMPARE_AND_SWAP(2, 3);
	PIXEL_COMPARE_AND_SWAP(0, 2);
	PIXEL_COMPARE_AND_SWAP(1, 3);
	PIXEL_COMPARE_AND_SWAP(1, 2);
	//printf("Hello");
	PIXEL_COMPARE_AND_SWAP(4, 5);
	PIXEL_COMPARE_AND_SWAP(6, 7);
	PIXEL_COMPARE_AND_SWAP(4, 6);
	PIXEL_COMPARE_AND_SWAP(5, 7);
	PIXEL_COMPARE_AND_SWAP(5, 6);

	PIXEL_COMPARE_AND_SWAP(0, 4);
	PIXEL_COMPARE_AND_SWAP(1, 5);
	PIXEL_COMPARE_AND_SWAP(2, 6);
	PIXEL_COMPARE_AND_SWAP(3, 7);

	PIXEL_COMPARE_AND_SWAP(2, 4);
	PIXEL_COMPARE_AND_SWAP(3, 5);

	PIXEL_COMPARE_AND_SWAP(1, 2);
	PIXEL_COMPARE_AND_SWAP(3, 4);
	PIXEL_COMPARE_AND_SWAP(5, 6);

	// 4x4	
	PIXEL_COMPARE_AND_SWAP(8, 9);
	PIXEL_COMPARE_AND_SWAP(10, 11);
	PIXEL_COMPARE_AND_SWAP(8, 10);
	PIXEL_COMPARE_AND_SWAP(9, 11);
	PIXEL_COMPARE_AND_SWAP(9, 10);

	PIXEL_COMPARE_AND_SWAP(12, 13);
	PIXEL_COMPARE_AND_SWAP(14, 15);
	PIXEL_COMPARE_AND_SWAP(12, 14);
	PIXEL_COMPARE_AND_SWAP(13, 15);
	PIXEL_COMPARE_AND_SWAP(13, 14);

	PIXEL_COMPARE_AND_SWAP(8, 12);
	PIXEL_COMPARE_AND_SWAP(9, 13);
	PIXEL_COMPARE_AND_SWAP(10, 14);
	PIXEL_COMPARE_AND_SWAP(11, 15);

	PIXEL_COMPARE_AND_SWAP(10, 12);
	PIXEL_COMPARE_AND_SWAP(11, 13);

	PIXEL_COMPARE_AND_SWAP(9, 10);
	PIXEL_COMPARE_AND_SWAP(11, 12);
	PIXEL_COMPARE_AND_SWAP(13, 14);


	PIXEL_COMPARE_AND_SWAP(0, 8);
	PIXEL_COMPARE_AND_SWAP(1, 9);
	PIXEL_COMPARE_AND_SWAP(2, 10);
	PIXEL_COMPARE_AND_SWAP(3, 11);
	PIXEL_COMPARE_AND_SWAP(4, 12);
	PIXEL_COMPARE_AND_SWAP(5, 13);
	PIXEL_COMPARE_AND_SWAP(6, 14);
	PIXEL_COMPARE_AND_SWAP(7, 15);


	PIXEL_COMPARE_AND_SWAP(4, 8);
	PIXEL_COMPARE_AND_SWAP(5, 9);
	PIXEL_COMPARE_AND_SWAP(6, 10);
	PIXEL_COMPARE_AND_SWAP(7, 11);

	PIXEL_COMPARE_AND_SWAP(2, 4);
	PIXEL_COMPARE_AND_SWAP(3, 5);
	PIXEL_COMPARE_AND_SWAP(6, 8);
	PIXEL_COMPARE_AND_SWAP(7, 9);
	PIXEL_COMPARE_AND_SWAP(10, 12);
	PIXEL_COMPARE_AND_SWAP(11, 13);

	PIXEL_COMPARE_AND_SWAP(1, 2);
	PIXEL_COMPARE_AND_SWAP(3, 4);
	PIXEL_COMPARE_AND_SWAP(5, 6);
	PIXEL_COMPARE_AND_SWAP(7, 8);
	PIXEL_COMPARE_AND_SWAP(9, 10);
	PIXEL_COMPARE_AND_SWAP(11, 12);
	PIXEL_COMPARE_AND_SWAP(13, 14);

	// Eddig 8x8-as (16 bemenet)

	//4x4
	PIXEL_COMPARE_AND_SWAP(16, 17);
	//PIXEL_COMPARE_AND_SWAP(18, 19);
	//PIXEL_COMPARE_AND_SWAP(20, 21);
	//PIXEL_COMPARE_AND_SWAP(22, 23);

	PIXEL_COMPARE_AND_SWAP(16, 18);
	//PIXEL_COMPARE_AND_SWAP(20, 22);
	PIXEL_COMPARE_AND_SWAP(17, 19);
	//PIXEL_COMPARE_AND_SWAP(21, 23);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	//PIXEL_COMPARE_AND_SWAP(21, 22);


	PIXEL_COMPARE_AND_SWAP(16, 20);
	PIXEL_COMPARE_AND_SWAP(17, 21);
	//PIXEL_COMPARE_AND_SWAP(18, 22);
	//PIXEL_COMPARE_AND_SWAP(19, 23);

	//PIXEL_COMPARE_AND_SWAP(18, 20);
	//PIXEL_COMPARE_AND_SWAP(19, 21);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	//PIXEL_COMPARE_AND_SWAP(19, 20);
	//PIXEL_COMPARE_AND_SWAP(21, 22);


	PIXEL_COMPARE_AND_SWAP(16, 24);

	//PIXEL_COMPARE_AND_SWAP(20, 24);

	//PIXEL_COMPARE_AND_SWAP(18, 20);
	//PIXEL_COMPARE_AND_SWAP(19, 21);
	//PIXEL_COMPARE_AND_SWAP(22, 24);

	//cmpswap(19, 21);
	PIXEL_COMPARE_AND_SWAP(17, 18);
	//PIXEL_COMPARE_AND_SWAP(19, 20);
	//PIXEL_COMPARE_AND_SWAP(21, 22);
	//PIXEL_COMPARE_AND_SWAP(23, 24);
	//Eddig egy 8x8-as (De ez csak 9 bemenet)

	// 16x16 
	PIXEL_COMPARE_AND_SWAP(0, 16);
	PIXEL_COMPARE_AND_SWAP(1, 17);
	PIXEL_COMPARE_AND_SWAP(2, 18);
	PIXEL_COMPARE_AND_SWAP(3, 19);
	PIXEL_COMPARE_AND_SWAP(4, 20);
	PIXEL_COMPARE_AND_SWAP(5, 21);
	PIXEL_COMPARE_AND_SWAP(6, 22);
	PIXEL_COMPARE_AND_SWAP(7, 23);
	PIXEL_COMPARE_AND_SWAP(8, 24);


	PIXEL_COMPARE_AND_SWAP(8, 16);
	PIXEL_COMPARE_AND_SWAP(9, 17);
	PIXEL_COMPARE_AND_SWAP(10, 18);
	PIXEL_COMPARE_AND_SWAP(11, 19);
	PIXEL_COMPARE_AND_SWAP(12, 20);
	PIXEL_COMPARE_AND_SWAP(13, 21);
	//PIXEL_COMPARE_AND_SWAP(14, 22);
	//PIXEL_COMPARE_AND_SWAP(15, 23);


	PIXEL_COMPARE_AND_SWAP(4, 8);
	PIXEL_COMPARE_AND_SWAP(5, 9);
	PIXEL_COMPARE_AND_SWAP(6, 10);
	PIXEL_COMPARE_AND_SWAP(7, 11);

	PIXEL_COMPARE_AND_SWAP(12, 16);
	PIXEL_COMPARE_AND_SWAP(13, 17);
	//PIXEL_COMPARE_AND_SWAP(14, 18);
	//PIXEL_COMPARE_AND_SWAP(15, 19);

	PIXEL_COMPARE_AND_SWAP(20, 21);


	PIXEL_COMPARE_AND_SWAP(2, 4);
	PIXEL_COMPARE_AND_SWAP(3, 5);
	PIXEL_COMPARE_AND_SWAP(6, 8);
	PIXEL_COMPARE_AND_SWAP(7, 9);
	PIXEL_COMPARE_AND_SWAP(10, 12);
	PIXEL_COMPARE_AND_SWAP(11, 13);



	PIXEL_COMPARE_AND_SWAP(1, 2);
	PIXEL_COMPARE_AND_SWAP(3, 4);
	PIXEL_COMPARE_AND_SWAP(5, 6);
	PIXEL_COMPARE_AND_SWAP(7, 8);
	PIXEL_COMPARE_AND_SWAP(9, 10);
	PIXEL_COMPARE_AND_SWAP(11, 12);
}



__inline__ __device__  void cmpswap(int a, int b, unsigned char * arr) {
	unsigned char buf;
	if (arr[a] > arr[b]) {
		buf = arr[b];
		arr[b] = arr[a];
		arr[a] = buf;
	}
}

/*__device__ void cmpswap2(int a, int b, float * arr) {
	float buf1 = arr[a];
	float buf2 = arr[b];
	arr[a] = std::max(buf1, buf2);
	arr[b] = std::min(buf1, buf2);
}*/


/*
// Globális memóriát használó (triviális) megoldás
__global__ void medfilter_global(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  
  int out_pix = (row*imgWidth+col)*3;
  unsigned char pix_data[25];

  int in_pix = (row*imgWidthF + col)*3;


  for (int rgb = 0; rgb < 3; rgb++)
  {
	  #pragma unroll 5
	  for (int medianY = 0; medianY < 5; medianY++)
	  {
		  #pragma unroll 5
		  for (int medianX = 0; medianX < 5; medianX++)
		  {

				pix_data[medianY * 5 + medianX] = gInput[in_pix + medianY*imgWidthF*3 + medianX*3 + rgb];

				//in_pix = in_pix + 3;
		  }
		  //in_pix = in_pix + 3 * imgWidthF - 5 * 1 * 3;
	  }
 
	  oddeven(pix_data);



		  gOutput[out_pix + rgb] = pix_data[12];
 
  }
}

*/

#define MEDIAN 12

// Shared memóriát használó megoldás (1.)
// Shared memória adattípus: unsigned char
// Számítás adattípusa: unsignde char, NEM integer
__global__ void kernel_conv_sh_uchar_int(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
  int row = blockIdx.y * blockDim.y + threadIdx.y;
  int col = blockIdx.x * blockDim.x + threadIdx.x;
  
  int out_pix = (row*imgWidth+col)*3;
  //unsigned char arr[31]; 
  unsigned char arr[25]; 

  __shared__ unsigned char in_shmem[20][20][3];

  int th1D = threadIdx.y*blockDim.x + threadIdx.x;						// thread ID
  int ld_rgba = th1D%3;
  int ld_col  = (th1D/3)%20;
  int ld_row  = th1D / 60;
  //int ld_base = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x * blockDim.x) * 3 + (ld_row * 3 * imgWidthF);
  int ld_base = ((blockIdx.y * blockDim.y) * imgWidthF + (blockIdx.x * blockDim.x)  + (ld_row  * imgWidthF)) * 3;
 
  if (th1D < 240)
  {
	  #pragma unroll
	  for (int ld=0; ld<5; ld++)
	  {
		  in_shmem[ld_row + ld * 4][ld_col][ld_rgba] = 
			  gInput[ld_base + (th1D % 60)];
		  ld_base = ld_base + imgWidthF*12;						// 
	  }
  }
__syncthreads();

	for (int rgb = 0; rgb<3; rgb++)
	{
	  //#pragma unroll 5
	  for (int medianY=0; medianY<5; medianY++)
		 {
		  //#pragma unroll 5
		  for (int medianX=0; medianX<5; medianX++)
		  {
			  //#pragma unroll 3
              arr[medianY*5 + medianX] = in_shmem[threadIdx.y + medianY][threadIdx.x + medianX][rgb];
          }
		}

	  mergeSort(arr);
	  gOutput[out_pix + rgb] = arr[MEDIAN];
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
	//unsigned char arr[31]; 
	//unsigned char arr[25];
	float arr[25];


	//__shared__ unsigned char in_shmem[20][20][3];
	__shared__ float in_shmem[20][20][3];

	int th1D = threadIdx.y*blockDim.x + threadIdx.x;						// thread ID
	int ld_rgba = th1D % 3;
	int ld_col = (th1D / 3) % 20;
	int ld_row = th1D / 60;
	//int ld_base = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x * blockDim.x) * 3 + (ld_row * 3 * imgWidthF);
	int ld_base = ((blockIdx.y * blockDim.y) * imgWidthF + (blockIdx.x * blockDim.x) + (ld_row  * imgWidthF)) * 3;

	if (th1D < 240)
	{
#pragma unroll
		for (int ld = 0; ld<5; ld++)
		{
			in_shmem[ld_row + ld * 4][ld_col][ld_rgba] = (float)gInput[ld_base + (th1D % 60)];
			ld_base = ld_base + imgWidthF * 12;					
		}
	}
	__syncthreads();

	for (int rgb = 0; rgb<3; rgb++)
	{
		//#pragma unroll 5
		for (int medianY = 0; medianY<5; medianY++)
		{
			//#pragma unroll 5
			for (int medianX = 0; medianX<5; medianX++)
			{
				//#pragma unroll 3
				arr[medianY * 5 + medianX] = in_shmem[threadIdx.y + medianY][threadIdx.x + medianX][rgb];
			}
		}

		mergeSort(arr);
		gOutput[out_pix + rgb] = (unsigned char)(arr[MEDIAN]);			// ??? tipuskonverrzio 
	}
}




// ----- úJ
// Shared memóriát használó megoldás (1.)
// Shared memória adattípus: unsigned char
// Számítás adattípusa: unsignde char, NEM integer
__global__ void kernel_conv_sh_uchar_int(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
	int row = blockIdx.y * blockDim.y + threadIdx.y;
	int col = blockIdx.x * blockDim.x + threadIdx.x;

	//int out_pix = (row*imgWidth + col) * 3;
	//unsigned char arr[31]; 
	unsigned char arr[25];

	__shared__ unsigned char in_shmem[20][60];

	int th1D = threadIdx.y*blockDim.x + threadIdx.x;	// thread ID 1D
	int rx = blockIdx.x * blockDim.x;
	int ry = blockIdx.y * blockDim.y;
	int base = (ry*imgWidthF + rx) * 3;

	int wr_x, int wr_y;
	

	//int ld_rgba = th1D % 3;
	//int ld_col = (th1D / 3) % 20;
	//int ld_row = th1D / 60;
	//int ld_base = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x * blockDim.x) * 3 + (ld_row * 3 * imgWidthF);
	//int ld_base = ((blockIdx.y * blockDim.y) * imgWidthF + (blockIdx.x * blockDim.x) + (ld_row  * imgWidthF)) * 3;

	if (th1D < 240)
	{
#pragma unroll
		for (int i = 0; i<5; i++)
		{
			wr_y = 4 * i + th1D / 60;
			wr_x = th1D % 60;

			in_shmem[wr_y][wr_x] = gInput[ base + wr_y * imgWidthF * 3 + wr_x];
			//base += imgWidthF * 12;				// ???
			//ld_base = ld_base + imgWidthF * 12;						// 
		}
	}
	__syncthreads();

	
		//#pragma unroll 5
		for (int medianY = 0; medianY<5; medianY++)
		{
			//#pragma unroll 5
			for (int medianX = 0; medianX<5; medianX++)
			{
				//#pragma unroll 3
				for (int rgb = 0; rgb < 3; rgb++)
				{
					
					arr[medianY * 5 + medianX] = in_shmem[threadIdx.y + medianY][(threadIdx.x + medianX)*3 + rgb];
				}
			}
		}

		mergeSort(arr);
		gOutput[out_pix + rgb] = arr[MEDIAN];
	}
}

// Új
// Shared memóriát használó megoldás (3.)
// Shared memória adattípus: float
// Számítás adattípusa: float
__global__ void kernel_conv_sh_float_float(unsigned char* gInput, unsigned char* gOutput, int imgWidth, int imgWidthF)
{
int row = blockIdx.y * blockDim.y + threadIdx.y;
int col = blockIdx.x * blockDim.x + threadIdx.x;

//int out_pix = (row*imgWidth + col) * 3;
//unsigned char arr[31]; 
float arr[25];

__shared__ unsigned char in_shmem[20][60];

int th1D = threadIdx.y*blockDim.x + threadIdx.x;	// thread ID 1D
int rx = blockIdx.x * blockDim.x;
int ry = blockIdx.y * blockDim.y;
int base = (ry*imgWidthF + rx) * 3;

int wr_x, int wr_y;


//int ld_rgba = th1D % 3;
//int ld_col = (th1D / 3) % 20;
//int ld_row = th1D / 60;
//int ld_base = (blockIdx.y * blockDim.y) * 3 * imgWidthF + (blockIdx.x * blockDim.x) * 3 + (ld_row * 3 * imgWidthF);
//int ld_base = ((blockIdx.y * blockDim.y) * imgWidthF + (blockIdx.x * blockDim.x) + (ld_row  * imgWidthF)) * 3;

if (th1D < 240)
{
#pragma unroll
	for (int i = 0; i<5; i++)
	{
		wr_y = 4 * i + th1D / 60;
		wr_x = th1D % 60;

		in_shmem[wr_y][wr_x] = (float)gInput[base + wr_y * imgWidthF * 3 + wr_x];
		//base += imgWidthF * 12;				// ???
		//ld_base = ld_base + imgWidthF * 12;						// 
	}
}
__syncthreads();


//#pragma unroll 5
for (int medianY = 0; medianY<5; medianY++)
{
	//#pragma unroll 5
	for (int medianX = 0; medianX<5; medianX++)
	{
		//#pragma unroll 3
		for (int rgb = 0; rgb < 3; rgb++)
		{

			arr[medianY * 5 + medianX] = in_shmem[threadIdx.y + medianY][(threadIdx.x + medianX) * 3 + rgb];
		}
	}
}

mergeSort(arr);
gOutput[out_pix + rgb] = (unsigned char)arr[MEDIAN];
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
		kernel_conv_sh_uchar_int << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
		//kernel_conv_sh_float_float << <thrGrid, thrBlock >> >(gInput, gOutput, imgWidth, imgWidthF);
	
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