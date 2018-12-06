//#include <stdint.h>

#include "ap_int.h"
#include "ap_fixed.h"

typedef ap_uint<8> pixel_t; 	// pixelek
typedef ap_uint<3> row_t;  	 	// 5 sor
typedef ap_uint<11> col_t;		// 1280 oszlop
typedef ap_uint<3> median_t;	// 5 széles, 5 hosszú

#define PIXEL_COMPARE_AND_SWAP(x, y) if(arr[(x)] > arr[(y)]) { tmp = arr[(y)];arr[(y)] = arr[(x)];arr[(x)] = tmp;	}

void mergeSort(pixel_t * arr)
{
	#pragma HLS INLINE
	#pragma HLS PIPELINE II=1	
	pixel_t tmp;
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

typedef enum {RED, GREEN, BLUE}Colors;
#define MEDIAN 2

void medianFilter(pixel_t pixelIn[3], int newLine, pixel_t pixelOut[3])
{
#pragma HLS PIPELINE II=1

	static pixel_t fiveLine[3][1280][5];
	#pragma HLS ARRAY_PARTITION variable=fiveLine complete dim=3
	#pragma HLS ARRAY_PARTITION variable=fiveLine complete dim=1


	static pixel_t bufferOrig_Red[5][5];
	static pixel_t bufferOrig_Green[5][5];
	static pixel_t bufferOrig_Blue[5][5];
	#pragma HLS ARRAY_PARTITION variable=bufferOrig_Red complete dim=0
	#pragma HLS ARRAY_PARTITION variable=bufferOrig_Green complete dim=0
	#pragma HLS ARRAY_PARTITION variable=bufferOrig_Blue complete dim=0
	// Minden dimenzió mentén partícionáljon

	static pixel_t buffer_Red[5][5];
	static pixel_t buffer_Green[5][5];
	static pixel_t buffer_Blue[5][5];
	#pragma HLS ARRAY_PARTITION variable=buffer_Red complete dim=0
	#pragma HLS ARRAY_PARTITION variable=buffer_Green complete dim=0
	#pragma HLS ARRAY_PARTITION variable=buffer_Blue complete dim=0
	// Minden dimenzió mentén partícionáljon
	
	static col_t fiveLineX = 0;
	static row_t fiveLineY = 0;

	// Új sor jel
	if (newLine)
	{
		fiveLineX = 0;
		if (fiveLineY == 4) 
			fiveLineY = 0;
		else
			fiveLineY++;
	}
	else
		fiveLineX++;
	
	fiveLine[RED][fiveLineX][fiveLineY] = pixelIn[RED];
	fiveLine[GREEN][fiveLineX][fiveLineY] = pixelIn[GREEN];
	fiveLine[BLUE][fiveLineX][fiveLineY] = pixelIn[BLUE];

// A szûrõablaka tartalmának balra shiftelése		
shiftY: for (median_t medianY = 0; medianY < 5; medianY++)
		{
			#pragma HLS UNROLL
			buffer_shift_x:
			for (median_t medianX = 1; medianX < 5; medianX++)
			{
				#pragma HLS PIPELINE II=1
				#pragma HLS UNROLL
				bufferOrig_Red[medianX-1][medianY] = bufferOrig_Red[medianX][medianY] ;
				bufferOrig_Green[medianX-1][medianY] = bufferOrig_Green[medianX][medianY] ;
				bufferOrig_Blue[medianX-1][medianY] = bufferOrig_Blue[medianX][medianY] ;
			}
		}

// Új elem behelyezése
newPixel:	for (median_t medianY = 0; medianY < 5; medianY++)
			{
				#pragma HLS UNROLL
				bufferOrig_Red[4][medianY] = fiveLine[RED][fiveLineX][medianY];;
				bufferOrig_Green[4][medianY] = fiveLine[GREEN][fiveLineX][medianY];;
				bufferOrig_Blue[4][medianY] = fiveLine[BLUE][fiveLineX][medianY];;
			}
	
// Buffer tartalmának a lemásolása
bufferCopyY:	for (median_t medianY = 0; medianY < 5; medianY++)
				{
					#pragma HLS UNROLL
					bufferCopyX:			
					for (median_t medianX = 0; medianX < 5; medianX++)
					{
						#pragma HLS UNROLL
						buffer_Red[medianX][medianY] = bufferOrig_Red[medianX][medianY];
						buffer_Green[medianX][medianY] = bufferOrig_Green[medianX][medianY];
						buffer_Blue[medianX][medianY] = bufferOrig_Blue[medianX][medianY];
					}
				}
	
		mergeSort(buffer_Red);
		mergeSort(buffer_Green);
		mergeSort(buffer_Blue);

	// Kimeneti pixel beállítása
	pixelOut[RED] = buffer_Red[MEDIAN][MEDIAN];
	pixelOut[GREEN] = buffer_Green[MEDIAN][MEDIAN];
	pixelOut[BLUE] = buffer_Blue[MEDIAN][MEDIAN];
}


