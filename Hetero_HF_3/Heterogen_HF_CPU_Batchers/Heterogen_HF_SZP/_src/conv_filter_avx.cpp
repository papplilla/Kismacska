#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"

#include <stdlib.h>

#include <algorithm>

void mergeSortAVX(__m128 * arr);
void mergeSortFullAVX(__m128 * arr);




inline void pixelCompareAndSwap(int little, int big, __m128 * arr) {
	__m128 tmpMin = arr[little];
	__m128 tmpMax = arr[big];
	arr[little]	 = _mm_min_ps(tmpMin, tmpMax);
	arr[big]	 = _mm_max_ps(tmpMin, tmpMax);
}


//#define pixelCompareAndSwap(x, y) if (arr[(x)] > arr[(y)]) { tmp = arr[(y)];arr[(y)] = arr[(x)];arr[(x)] = tmp;	}	
	

void mergeSortAVX(__m128 * arr)
{
	float tmp;
	// 4x4
	pixelCompareAndSwap(0, 1, arr);
	pixelCompareAndSwap(2, 3, arr);
	pixelCompareAndSwap(0, 2, arr);
	pixelCompareAndSwap(1, 3, arr);
	pixelCompareAndSwap(1, 2, arr);
	//printf("Hello", arr);
	pixelCompareAndSwap(4, 5, arr);
	pixelCompareAndSwap(6, 7, arr);
	pixelCompareAndSwap(4, 6, arr);
	pixelCompareAndSwap(5, 7, arr);
	pixelCompareAndSwap(5, 6, arr);

	pixelCompareAndSwap(0, 4, arr);
	pixelCompareAndSwap(1, 5, arr); 
	pixelCompareAndSwap(2, 6, arr);
	pixelCompareAndSwap(3, 7, arr);

	pixelCompareAndSwap(2, 4, arr); 
	pixelCompareAndSwap(3, 5, arr);

	pixelCompareAndSwap(1, 2, arr);
	pixelCompareAndSwap(3, 4, arr);
	pixelCompareAndSwap(5, 6, arr);

	// 4x4	
	pixelCompareAndSwap(8, 9, arr);
	pixelCompareAndSwap(10, 11, arr);
	pixelCompareAndSwap(8, 10, arr);
	pixelCompareAndSwap(9, 11, arr);
	pixelCompareAndSwap(9, 10, arr);

	pixelCompareAndSwap(12, 13, arr);
	pixelCompareAndSwap(14, 15, arr);
	pixelCompareAndSwap(12, 14, arr);
	pixelCompareAndSwap(13, 15, arr);
	pixelCompareAndSwap(13, 14, arr);

	pixelCompareAndSwap(8, 12, arr);
	pixelCompareAndSwap(9, 13, arr); 
	pixelCompareAndSwap(10, 14, arr);
	pixelCompareAndSwap(11, 15, arr);

	pixelCompareAndSwap(10, 12, arr); 
	pixelCompareAndSwap(11, 13, arr);

	pixelCompareAndSwap(9, 10, arr);
	pixelCompareAndSwap(11, 12, arr);
	pixelCompareAndSwap(13, 14, arr);


	pixelCompareAndSwap(0, 8, arr); 
	pixelCompareAndSwap(1, 9, arr); 
	pixelCompareAndSwap(2, 10, arr); 
	pixelCompareAndSwap(3, 11, arr); 
	pixelCompareAndSwap(4, 12, arr); 
	pixelCompareAndSwap(5, 13, arr); 
	pixelCompareAndSwap(6, 14, arr); 
	pixelCompareAndSwap(7, 15, arr); 


	pixelCompareAndSwap(4, 8, arr); 
	pixelCompareAndSwap(5, 9, arr); 
	pixelCompareAndSwap(6, 10, arr); 
	pixelCompareAndSwap(7, 11, arr); 

	pixelCompareAndSwap(2, 4, arr); 
	pixelCompareAndSwap(3, 5, arr); 
	pixelCompareAndSwap(6, 8, arr);
	pixelCompareAndSwap(7, 9, arr);
	pixelCompareAndSwap(10, 12, arr); 
	pixelCompareAndSwap(11, 13, arr); 

	pixelCompareAndSwap(1, 2, arr); 
	pixelCompareAndSwap(3, 4, arr); 
	pixelCompareAndSwap(5, 6, arr); 
	pixelCompareAndSwap(7, 8, arr); 
	pixelCompareAndSwap(9, 10, arr); 
	pixelCompareAndSwap(11, 12, arr); 
	pixelCompareAndSwap(13, 14, arr); 

// Eddig 8x8-as (16 bemenet)

	//4x4
	pixelCompareAndSwap(16, 17, arr);
	//pixelCompareAndSwap(18, 19, arr);
	//pixelCompareAndSwap(20, 21, arr);
	//pixelCompareAndSwap(22, 23, arr);

	pixelCompareAndSwap(16, 18, arr);
	//pixelCompareAndSwap(20, 22, arr);
	pixelCompareAndSwap(17, 19, arr);
	//pixelCompareAndSwap(21, 23, arr);

	pixelCompareAndSwap(17, 18, arr);
	//pixelCompareAndSwap(21, 22, arr);


	pixelCompareAndSwap(16, 20, arr);
	pixelCompareAndSwap(17, 21, arr);
	//pixelCompareAndSwap(18, 22, arr);
	//pixelCompareAndSwap(19, 23, arr);

	//pixelCompareAndSwap(18, 20, arr);
	//pixelCompareAndSwap(19, 21, arr);

	pixelCompareAndSwap(17, 18, arr);
	//pixelCompareAndSwap(19, 20, arr);
	//pixelCompareAndSwap(21, 22, arr);


	pixelCompareAndSwap(16, 24, arr);

	//pixelCompareAndSwap(20, 24, arr);

	//pixelCompareAndSwap(18, 20, arr);
	//pixelCompareAndSwap(19, 21, arr);
	//pixelCompareAndSwap(22, 24, arr);

	//cmpswap(19, 21, arr);
	pixelCompareAndSwap(17, 18, arr);
	//pixelCompareAndSwap(19, 20, arr);
	//pixelCompareAndSwap(21, 22, arr);
	//pixelCompareAndSwap(23, 24, arr);
	//Eddig egy 8x8-as (De ez csak 9 bemenet)

// 16x16 
	pixelCompareAndSwap(0, 16, arr);
	pixelCompareAndSwap(1, 17, arr);
	pixelCompareAndSwap(2, 18, arr);
	pixelCompareAndSwap(3, 19, arr);
	pixelCompareAndSwap(4, 20, arr);
	pixelCompareAndSwap(5, 21, arr);
	pixelCompareAndSwap(6, 22, arr);
	pixelCompareAndSwap(7, 23, arr);
	pixelCompareAndSwap(8, 24, arr);


	pixelCompareAndSwap(8, 16, arr);
	pixelCompareAndSwap(9, 17, arr);
	pixelCompareAndSwap(10, 18, arr);
	pixelCompareAndSwap(11, 19, arr);
	pixelCompareAndSwap(12, 20, arr);
	pixelCompareAndSwap(13, 21, arr);
	//pixelCompareAndSwap(14, 22, arr);
	//pixelCompareAndSwap(15, 23, arr);


	pixelCompareAndSwap(4, 8, arr);
	pixelCompareAndSwap(5, 9, arr);
	pixelCompareAndSwap(6, 10, arr);
	pixelCompareAndSwap(7, 11, arr);

	pixelCompareAndSwap(12, 16, arr);
	pixelCompareAndSwap(13, 17, arr);
	//pixelCompareAndSwap(14, 18, arr);
	//pixelCompareAndSwap(15, 19, arr);

	pixelCompareAndSwap(20, 21, arr);


	pixelCompareAndSwap(2, 4, arr);
	pixelCompareAndSwap(3, 5, arr);
	pixelCompareAndSwap(6, 8, arr);
	pixelCompareAndSwap(7, 9, arr);
	pixelCompareAndSwap(10, 12, arr);
	pixelCompareAndSwap(11, 13, arr);



	pixelCompareAndSwap(1, 2, arr);
	pixelCompareAndSwap(3, 4, arr);
	pixelCompareAndSwap(5, 6, arr);
	pixelCompareAndSwap(7, 8, arr);
	pixelCompareAndSwap(9, 10, arr);
	pixelCompareAndSwap(11, 12, arr);
}

void mergeSortFullAVX(__m128 * arr)
{
	// 4x4
	pixelCompareAndSwap(0, 1, arr);
	pixelCompareAndSwap(2, 3, arr);
	pixelCompareAndSwap(0, 2, arr);
	pixelCompareAndSwap(1, 3, arr);
	pixelCompareAndSwap(1, 2, arr);
	//printf("Hello", arr);
	pixelCompareAndSwap(4, 5, arr);
	pixelCompareAndSwap(6, 7, arr);
	pixelCompareAndSwap(4, 6, arr);
	pixelCompareAndSwap(5, 7, arr);
	pixelCompareAndSwap(5, 6, arr);

	pixelCompareAndSwap(0, 4, arr);
	pixelCompareAndSwap(1, 5, arr);
	pixelCompareAndSwap(2, 6, arr);
	pixelCompareAndSwap(3, 7, arr);

	pixelCompareAndSwap(2, 4, arr);
	pixelCompareAndSwap(3, 5, arr);

	pixelCompareAndSwap(1, 2, arr);
	pixelCompareAndSwap(3, 4, arr);
	pixelCompareAndSwap(5, 6, arr);

	// 4x4	
	pixelCompareAndSwap(8, 9, arr);
	pixelCompareAndSwap(10, 11, arr);
	pixelCompareAndSwap(8, 10, arr);
	pixelCompareAndSwap(9, 11, arr);
	pixelCompareAndSwap(9, 10, arr);

	pixelCompareAndSwap(12, 13, arr);
	pixelCompareAndSwap(14, 15, arr);
	pixelCompareAndSwap(12, 14, arr);
	pixelCompareAndSwap(13, 15, arr);
	pixelCompareAndSwap(13, 14, arr);

	pixelCompareAndSwap(8, 12, arr);
	pixelCompareAndSwap(9, 13, arr);
	pixelCompareAndSwap(10, 14, arr);
	pixelCompareAndSwap(11, 15, arr);

	pixelCompareAndSwap(10, 12, arr);
	pixelCompareAndSwap(11, 13, arr);

	pixelCompareAndSwap(9, 10, arr);
	pixelCompareAndSwap(11, 12, arr);
	pixelCompareAndSwap(13, 14, arr);


	pixelCompareAndSwap(0, 8, arr);
	pixelCompareAndSwap(1, 9, arr);
	pixelCompareAndSwap(2, 10, arr);
	pixelCompareAndSwap(3, 11, arr);
	pixelCompareAndSwap(4, 12, arr);
	pixelCompareAndSwap(5, 13, arr);
	pixelCompareAndSwap(6, 14, arr);
	pixelCompareAndSwap(7, 15, arr);


	pixelCompareAndSwap(4, 8, arr);
	pixelCompareAndSwap(5, 9, arr);
	pixelCompareAndSwap(6, 10, arr);
	pixelCompareAndSwap(7, 11, arr);

	pixelCompareAndSwap(2, 4, arr);
	pixelCompareAndSwap(3, 5, arr);
	pixelCompareAndSwap(6, 8, arr);
	pixelCompareAndSwap(7, 9, arr);
	pixelCompareAndSwap(10, 12, arr);
	pixelCompareAndSwap(11, 13, arr);

	pixelCompareAndSwap(1, 2, arr);
	pixelCompareAndSwap(3, 4, arr);
	pixelCompareAndSwap(5, 6, arr);
	pixelCompareAndSwap(7, 8, arr);
	pixelCompareAndSwap(9, 10, arr);
	pixelCompareAndSwap(11, 12, arr);
	pixelCompareAndSwap(13, 14, arr);

	// Eddig 8x8-as (16 bemenet)

	//4x4
	pixelCompareAndSwap(16, 17, arr);
	pixelCompareAndSwap(18, 19, arr);
	pixelCompareAndSwap(20, 21, arr);
	pixelCompareAndSwap(22, 23, arr);

	pixelCompareAndSwap(16, 18, arr);
	pixelCompareAndSwap(20, 22, arr);
	pixelCompareAndSwap(17, 19, arr);
	pixelCompareAndSwap(21, 23, arr);

	pixelCompareAndSwap(17, 18, arr);
	pixelCompareAndSwap(21, 22, arr);


	pixelCompareAndSwap(16, 20, arr);
	pixelCompareAndSwap(17, 21, arr);
	pixelCompareAndSwap(18, 22, arr);
	pixelCompareAndSwap(19, 23, arr);

	pixelCompareAndSwap(18, 20, arr);
	pixelCompareAndSwap(19, 21, arr);

	pixelCompareAndSwap(17, 18, arr);
	pixelCompareAndSwap(19, 20, arr);
	pixelCompareAndSwap(21, 22, arr);


	pixelCompareAndSwap(16, 24, arr);

	pixelCompareAndSwap(20, 24, arr);

	pixelCompareAndSwap(18, 20, arr);
	pixelCompareAndSwap(19, 21, arr);
	pixelCompareAndSwap(22, 24, arr);

	//cmpswap(19, 21, arr);
	pixelCompareAndSwap(17, 18, arr);
	pixelCompareAndSwap(19, 20, arr);
	pixelCompareAndSwap(21, 22, arr);
	pixelCompareAndSwap(23, 24, arr);
	//Eddig egy 8x8-as (De ez csak 9 bemenet)

	// 16x16 
	pixelCompareAndSwap(0, 16, arr);
	pixelCompareAndSwap(1, 17, arr);
	pixelCompareAndSwap(2, 18, arr);
	pixelCompareAndSwap(3, 19, arr);
	pixelCompareAndSwap(4, 20, arr);
	pixelCompareAndSwap(5, 21, arr);
	pixelCompareAndSwap(6, 22, arr);
	pixelCompareAndSwap(7, 23, arr);
	pixelCompareAndSwap(8, 24, arr);


	pixelCompareAndSwap(8, 16, arr);
	pixelCompareAndSwap(9, 17, arr);
	pixelCompareAndSwap(10, 18, arr);
	pixelCompareAndSwap(11, 19, arr);
	pixelCompareAndSwap(12, 20, arr);
	pixelCompareAndSwap(13, 21, arr);
	pixelCompareAndSwap(14, 22, arr);
	pixelCompareAndSwap(15, 23, arr);


	pixelCompareAndSwap(4, 8, arr);
	pixelCompareAndSwap(5, 9, arr);
	pixelCompareAndSwap(6, 10, arr);
	pixelCompareAndSwap(7, 11, arr);

	pixelCompareAndSwap(12, 16, arr);
	pixelCompareAndSwap(13, 17, arr);
	pixelCompareAndSwap(14, 18, arr);
	pixelCompareAndSwap(15, 19, arr);

	pixelCompareAndSwap(20, 21, arr);


	pixelCompareAndSwap(2, 4, arr);
	pixelCompareAndSwap(3, 5, arr);
	pixelCompareAndSwap(6, 8, arr);
	pixelCompareAndSwap(7, 9, arr);
	pixelCompareAndSwap(10, 12, arr);
	pixelCompareAndSwap(11, 13, arr);
	pixelCompareAndSwap(14, 16, arr);
	pixelCompareAndSwap(15, 17, arr);
	pixelCompareAndSwap(18, 20, arr);
	pixelCompareAndSwap(19, 21, arr);
	pixelCompareAndSwap(22, 24, arr);


	pixelCompareAndSwap(1, 2, arr);
	pixelCompareAndSwap(3, 4, arr);
	pixelCompareAndSwap(5, 6, arr);
	pixelCompareAndSwap(7, 8, arr);
	pixelCompareAndSwap(9, 10, arr);
	pixelCompareAndSwap(11, 12, arr);
	pixelCompareAndSwap(13, 14, arr);
	pixelCompareAndSwap(15, 16, arr);
	pixelCompareAndSwap(17, 18, arr);
	pixelCompareAndSwap(19, 20, arr);
	pixelCompareAndSwap(21, 22, arr);
	pixelCompareAndSwap(23, 24, arr);
}

#define MEDIAN 12

//void medianFilterAVX(int imgHeight, int imgWidth,  int imgWidthF, float *imgFloatSrc, float *imgFloatDst)
void medianFilterAVX(int imgHeight, int imgWidth, int imgWidthF, int imgFOffsetH, int imgFOffsetW, float *imgFloatSrc, float *imgFloatDst)
{
	// Kép sorai
#pragma omp parallel for
	for (int y = 0; y<imgHeight; y++)
		// Az adott sor pixelei
		for (int x = 0; x<imgWidth; x++)
		{
			__m128 medianArray[25];
			for (int medianY = 0; medianY < 5; medianY++) 
				for (int medianX = 0; medianX < 5; medianX++) 
					medianArray[5*medianY + medianX] = _mm_load_ps(imgFloatSrc + ((y+medianY)*imgWidthF + x + medianX) * 4);
				
			mergeSortAVX(medianArray);
			_mm_stream_ps(imgFloatDst + (y*imgWidth + x) * 4, medianArray[MEDIAN]);
		}
}

