﻿#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"

#include <stdlib.h>

#include <algorithm>

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
	

void mergeSort(float * arr)
{
	float tmp;
	// 4x4
	PIXEL_COMPARE_AND_SWAP(0, 1);
	PIXEL_COMPARE_AND_SWAP(2, 3);
	PIXEL_COMPARE_AND_SWAP(0, 2);
	PIXEL_COMPARE_AND_SWAP(1, 3);
	PIXEL_COMPARE_AND_SWAP(1, 2);

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
	PIXEL_COMPARE_AND_SWAP(18, 19);
	PIXEL_COMPARE_AND_SWAP(20, 21);
	PIXEL_COMPARE_AND_SWAP(22, 23);

	PIXEL_COMPARE_AND_SWAP(16, 18);
	PIXEL_COMPARE_AND_SWAP(20, 22);
	PIXEL_COMPARE_AND_SWAP(17, 19);
	PIXEL_COMPARE_AND_SWAP(21, 23);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	PIXEL_COMPARE_AND_SWAP(21, 22);


	PIXEL_COMPARE_AND_SWAP(16, 20);
	PIXEL_COMPARE_AND_SWAP(17, 21);
	PIXEL_COMPARE_AND_SWAP(18, 22);
	PIXEL_COMPARE_AND_SWAP(19, 23);

	PIXEL_COMPARE_AND_SWAP(18, 20);
	PIXEL_COMPARE_AND_SWAP(19, 21);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	PIXEL_COMPARE_AND_SWAP(19, 20);
	PIXEL_COMPARE_AND_SWAP(21, 22);

	PIXEL_COMPARE_AND_SWAP(16, 24);

	PIXEL_COMPARE_AND_SWAP(20, 24);

	PIXEL_COMPARE_AND_SWAP(18, 20);
	PIXEL_COMPARE_AND_SWAP(19, 21);
	PIXEL_COMPARE_AND_SWAP(22, 24);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	PIXEL_COMPARE_AND_SWAP(19, 20);
	PIXEL_COMPARE_AND_SWAP(21, 22);
	PIXEL_COMPARE_AND_SWAP(23, 24);
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
	PIXEL_COMPARE_AND_SWAP(14, 22);
	PIXEL_COMPARE_AND_SWAP(15, 23);


	PIXEL_COMPARE_AND_SWAP(4, 8);
	PIXEL_COMPARE_AND_SWAP(5, 9);
	PIXEL_COMPARE_AND_SWAP(6, 10);
	PIXEL_COMPARE_AND_SWAP(7, 11);

	PIXEL_COMPARE_AND_SWAP(12, 16);
	PIXEL_COMPARE_AND_SWAP(13, 17);


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

void mergeSortFull(float * arr)
{
	float tmp;
	// 4x4
	PIXEL_COMPARE_AND_SWAP(0, 1);
	PIXEL_COMPARE_AND_SWAP(2, 3);
	PIXEL_COMPARE_AND_SWAP(0, 2);
	PIXEL_COMPARE_AND_SWAP(1, 3);
	PIXEL_COMPARE_AND_SWAP(1, 2);
	
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
	PIXEL_COMPARE_AND_SWAP(18, 19);
	PIXEL_COMPARE_AND_SWAP(20, 21);
	PIXEL_COMPARE_AND_SWAP(22, 23);

	PIXEL_COMPARE_AND_SWAP(16, 18);
	PIXEL_COMPARE_AND_SWAP(20, 22);
	PIXEL_COMPARE_AND_SWAP(17, 19);
	PIXEL_COMPARE_AND_SWAP(21, 23);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	PIXEL_COMPARE_AND_SWAP(21, 22);


	PIXEL_COMPARE_AND_SWAP(16, 20);
	PIXEL_COMPARE_AND_SWAP(17, 21);
	PIXEL_COMPARE_AND_SWAP(18, 22);
	PIXEL_COMPARE_AND_SWAP(19, 23);

	PIXEL_COMPARE_AND_SWAP(18, 20);
	PIXEL_COMPARE_AND_SWAP(19, 21);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	PIXEL_COMPARE_AND_SWAP(19, 20);
	PIXEL_COMPARE_AND_SWAP(21, 22);

	PIXEL_COMPARE_AND_SWAP(16, 24);

	PIXEL_COMPARE_AND_SWAP(20, 24);

	PIXEL_COMPARE_AND_SWAP(18, 20);
	PIXEL_COMPARE_AND_SWAP(19, 21);
	PIXEL_COMPARE_AND_SWAP(22, 24);

	PIXEL_COMPARE_AND_SWAP(17, 18);
	PIXEL_COMPARE_AND_SWAP(19, 20);
	PIXEL_COMPARE_AND_SWAP(21, 22);
	PIXEL_COMPARE_AND_SWAP(23, 24);
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
	PIXEL_COMPARE_AND_SWAP(14, 22);
	PIXEL_COMPARE_AND_SWAP(15, 23);


	PIXEL_COMPARE_AND_SWAP(4, 8);
	PIXEL_COMPARE_AND_SWAP(5, 9);
	PIXEL_COMPARE_AND_SWAP(6, 10);
	PIXEL_COMPARE_AND_SWAP(7, 11);

	PIXEL_COMPARE_AND_SWAP(12, 16);
	PIXEL_COMPARE_AND_SWAP(13, 17);
	PIXEL_COMPARE_AND_SWAP(14, 18);
	PIXEL_COMPARE_AND_SWAP(15, 19);

	PIXEL_COMPARE_AND_SWAP(20, 24);


	PIXEL_COMPARE_AND_SWAP(2, 4);
	PIXEL_COMPARE_AND_SWAP(3, 5);

	PIXEL_COMPARE_AND_SWAP(6, 8);
	PIXEL_COMPARE_AND_SWAP(7, 9);

	PIXEL_COMPARE_AND_SWAP(10, 12);
	PIXEL_COMPARE_AND_SWAP(11, 13);

	PIXEL_COMPARE_AND_SWAP(14, 16);
	PIXEL_COMPARE_AND_SWAP(15, 17);

	PIXEL_COMPARE_AND_SWAP(18, 20);
	PIXEL_COMPARE_AND_SWAP(19, 21);

	PIXEL_COMPARE_AND_SWAP(22, 24);


	PIXEL_COMPARE_AND_SWAP(1, 2);
	PIXEL_COMPARE_AND_SWAP(3, 4);
	PIXEL_COMPARE_AND_SWAP(5, 6);
	PIXEL_COMPARE_AND_SWAP(7, 8);
	PIXEL_COMPARE_AND_SWAP(9, 10);
	PIXEL_COMPARE_AND_SWAP(11, 12);
	PIXEL_COMPARE_AND_SWAP(13, 14);
	PIXEL_COMPARE_AND_SWAP(15, 16);
	PIXEL_COMPARE_AND_SWAP(17, 18);
	PIXEL_COMPARE_AND_SWAP(19, 20);
	PIXEL_COMPARE_AND_SWAP(21, 22);
	PIXEL_COMPARE_AND_SWAP(23, 24);
}

#define MEDIAN 12

//void medianFilter(int imgHeight, int imgWidth, int imgWidthF, float *imgFloatSrc, float *imgFloatDst)
void medianFilter(int imgHeight, int imgWidth, int imgWidthF, int imgFOffsetH, int imgFOffsetW,  float *imgFloatSrc, float *imgFloatDst)
{
	// Kép sorai
	for (int y=imgFOffsetH; y<(imgHeight + imgFOffsetH); y++)
		// Kép oszlopai
		for (int x=imgFOffsetW; x<(imgWidth + imgFOffsetW); x++)
			// Szín komponensek
			for (int rgb = 0; rgb < 4; rgb++)
			{			
				float medianArray[25];

				for (int medianY = 0; medianY < 5; medianY++) 
					for (int medianX = 0; medianX < 5; medianX++) 
						medianArray[5*medianY  + medianX] = imgFloatSrc[((y+(medianY-2))*imgWidthF + x + (medianX-2))*4 + rgb];

				mergeSort(medianArray);
				//mergeSortFull(medianArray);
				imgFloatDst[(y*imgWidth + x) * 4 + rgb] = medianArray[MEDIAN];
			}
}

