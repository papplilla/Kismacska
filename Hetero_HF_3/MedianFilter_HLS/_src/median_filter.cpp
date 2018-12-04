#include <stdint.h>

void cmpswap(int a, int b, unsigned char * tomb) {
#pragma HLS INLINE
	unsigned char buf;
	if (tomb[a] > tomb[b]) {
		buf = tomb[b];
		tomb[b] = tomb[a];
		tomb[a] = buf;
	}
}

void oddeven(unsigned char * tomb) {
#pragma HLS INLINE
#pragma HLS PIPELINE II=1
	cmpswap(0, 1, tomb);
	cmpswap(2, 3, tomb);
	cmpswap(0, 2, tomb);
	cmpswap(1, 3, tomb);
	cmpswap(1, 2, tomb);
	cmpswap(4, 5, tomb);
	cmpswap(6, 7, tomb);
	cmpswap(4, 6, tomb);
	cmpswap(5, 7, tomb);
	cmpswap(5, 6, tomb);
	cmpswap(0, 4, tomb);
	cmpswap(2, 6, tomb);
	cmpswap(2, 4, tomb);
	cmpswap(1, 5, tomb);
	cmpswap(3, 7, tomb);
	cmpswap(3, 5, tomb);
	cmpswap(1, 2, tomb);
	cmpswap(3, 4, tomb);
	cmpswap(5, 6, tomb);
	cmpswap(8, 9, tomb);
	cmpswap(10, 11, tomb);
	cmpswap(8, 10, tomb);
	cmpswap(9, 11, tomb);
	cmpswap(9, 10, tomb);
	cmpswap(12, 13, tomb);
	cmpswap(14, 15, tomb);
	cmpswap(12, 14, tomb);
	cmpswap(13, 15, tomb);
	cmpswap(13, 14, tomb);
	cmpswap(8, 12, tomb);
	cmpswap(10, 14, tomb);
	cmpswap(10, 12, tomb);
	cmpswap(9, 13, tomb);
	cmpswap(11, 15, tomb);
	cmpswap(11, 13, tomb);
	cmpswap(9, 10, tomb);
	cmpswap(11, 12, tomb);
	cmpswap(13, 14, tomb);
	cmpswap(0, 8, tomb);
	cmpswap(4, 12, tomb);
	cmpswap(4, 8, tomb);
	cmpswap(2, 10, tomb);
	cmpswap(6, 14, tomb);
	cmpswap(6, 10, tomb);
	cmpswap(2, 4, tomb);
	cmpswap(6, 8, tomb);
	cmpswap(10, 12, tomb);
	cmpswap(1, 9, tomb);
	cmpswap(5, 13, tomb);
	cmpswap(5, 9, tomb);
	cmpswap(3, 11, tomb);
	cmpswap(7, 15, tomb);
	cmpswap(7, 11, tomb);
	cmpswap(3, 5, tomb);
	cmpswap(7, 9, tomb);
	cmpswap(11, 13, tomb);
	cmpswap(1, 2, tomb);
	cmpswap(3, 4, tomb);
	cmpswap(5, 6, tomb);
	cmpswap(7, 8, tomb);
	cmpswap(9, 10, tomb);
	cmpswap(11, 12, tomb);
	cmpswap(13, 14, tomb);
	cmpswap(16, 17, tomb);
	cmpswap(18, 19, tomb);
	cmpswap(16, 18, tomb);
	cmpswap(17, 19, tomb);
	cmpswap(17, 18, tomb);
	cmpswap(20, 21, tomb);
	cmpswap(22, 23, tomb);
	cmpswap(20, 22, tomb);
	cmpswap(21, 23, tomb);
	cmpswap(21, 22, tomb);
	cmpswap(16, 20, tomb);
	cmpswap(18, 22, tomb);
	cmpswap(18, 20, tomb);
	cmpswap(17, 21, tomb);
	cmpswap(19, 23, tomb);
	cmpswap(19, 21, tomb);
	cmpswap(17, 18, tomb);
	cmpswap(19, 20, tomb);
	cmpswap(21, 22, tomb);
	cmpswap(16, 24, tomb);
	cmpswap(20, 24, tomb);
	cmpswap(18, 20, tomb);
	cmpswap(22, 24, tomb);
	cmpswap(19, 21, tomb);
	cmpswap(17, 18, tomb);
	cmpswap(19, 20, tomb);
	cmpswap(21, 22, tomb);
	cmpswap(23, 24, tomb);
	cmpswap(0, 16, tomb);
	cmpswap(8, 24, tomb);
	cmpswap(8, 16, tomb);
	cmpswap(4, 20, tomb);
	cmpswap(12, 20, tomb);
	cmpswap(4, 8, tomb);
	cmpswap(12, 16, tomb);
	cmpswap(20, 24, tomb);
	cmpswap(2, 18, tomb);
	cmpswap(10, 18, tomb);
	cmpswap(6, 22, tomb);
	cmpswap(14, 22, tomb);
	cmpswap(6, 10, tomb);
	cmpswap(14, 18, tomb);
	cmpswap(2, 4, tomb);
	cmpswap(6, 8, tomb);
	cmpswap(10, 12, tomb);
	cmpswap(14, 16, tomb);
	cmpswap(18, 20, tomb);
	cmpswap(22, 24, tomb);
	cmpswap(1, 17, tomb);
	cmpswap(9, 17, tomb);
	cmpswap(5, 21, tomb);
	cmpswap(13, 21, tomb);
	cmpswap(5, 9, tomb);
	cmpswap(13, 17, tomb);
	cmpswap(3, 19, tomb);
	cmpswap(11, 19, tomb);
	cmpswap(7, 23, tomb);
	cmpswap(15, 23, tomb);
	cmpswap(7, 11, tomb);
	cmpswap(15, 19, tomb);
	cmpswap(3, 5, tomb);
	cmpswap(7, 9, tomb);
	cmpswap(11, 13, tomb);
	cmpswap(15, 17, tomb);
	cmpswap(19, 21, tomb);
	cmpswap(1, 2, tomb);
	cmpswap(3, 4, tomb);
	cmpswap(5, 6, tomb);
	cmpswap(7, 8, tomb);
	cmpswap(9, 10, tomb);
	cmpswap(11, 12, tomb);
	cmpswap(13, 14, tomb);
	cmpswap(15, 16, tomb);
	cmpswap(17, 18, tomb);
	cmpswap(19, 20, tomb);
	cmpswap(21, 22, tomb);
	cmpswap(23, 24, tomb);

}


#define PIXEL_COMPARE_AND_SWAP(x, y) if(arr[(x)] > arr[(y)]) { tmp = arr[(y)];arr[(y)] = arr[(x)];arr[(x)] = tmp;	}
void mergeSort(unsigned char * arr);
void mergeSort(unsigned char * arr)
{
	#pragma HLS INLINE
	#pragma HLS PIPELINE II=1	
	unsigned char tmp;
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

void medianFilter(pix_t pixelIn[3], int newLine, pix_t pixelOut[3])
{
#pragma HLS PIPELINE II=1

	static uint8_t fiveLine[3][1280][5];
	#pragma HLS ARRAY_PARTITION variable=fiveLine complete dim=3
	#pragma HLS ARRAY_PARTITION variable=fiveLine complete dim=1


	static uint8_t bufferOrig_Red[5][5];
	static uint8_t bufferOrig_Green[5][5];
	static uint8_t bufferOrig_Blue[5][5];
	#pragma HLS ARRAY_PARTITION variable=bufferOrig_Red complete dim=0
	#pragma HLS ARRAY_PARTITION variable=bufferOrig_Green complete dim=0
	#pragma HLS ARRAY_PARTITION variable=bufferOrig_Blue complete dim=0
	// Minden dimenzió mentén partícionáljon

	static uint8_t buffer_Red[5][5];
	static uint8_t buffer_Green[5][5];
	static uint8_t buffer_Blue[5][5];
	#pragma HLS ARRAY_PARTITION variable=buffer_Red complete dim=0
	#pragma HLS ARRAY_PARTITION variable=buffer_Green complete dim=0
	#pragma HLS ARRAY_PARTITION variable=buffer_Blue complete dim=0
	// Minden dimenzió mentén partícionáljon
	
	static int fiveLineX = 0;
	static uint8_t fiveLineY = 0;

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
shiftY: for (uint8_t medianY = 0; medianY < 5; medianY++)
		{
			#pragma HLS UNROLL
			buffer_shift_x:
			for (uint8_t medianX = 1; medianX < 5; medianX++)
			{
				#pragma HLS PIPELINE II=1
				#pragma HLS UNROLL
				bufferOrig_Red[medianX-1][medianY] = bufferOrig_Red[medianX][medianY] ;
				bufferOrig_Green[medianX-1][medianY] = bufferOrig_Green[medianX][medianY] ;
				bufferOrig_Blue[medianX-1][medianY] = bufferOrig_Blue[medianX][medianY] ;
			}
		}

// Új elem behelyezése
newPixel:	for (uint8_t medianY = 0; medianY < 5; medianY++)
			{
				#pragma HLS UNROLL
				bufferOrig_Red[4][medianY] = fiveLine[RED][fiveLineX][medianY];;
				bufferOrig_Green[4][medianY] = fiveLine[GREEN][fiveLineX][medianY];;
				bufferOrig_Blue[4][medianY] = fiveLine[BLUE][fiveLineX][medianY];;
			}
	
// Buffer tartalmának a lemásolása
bufferCopyY:	for (uint8_t medianY = 0; medianY < 5; medianY++)
				{
					#pragma HLS UNROLL
					bufferCopyX:			
					for (uint8_t medianX = 0; medianX < 5; medianX++)
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


