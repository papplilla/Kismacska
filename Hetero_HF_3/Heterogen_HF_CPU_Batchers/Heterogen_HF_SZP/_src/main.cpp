// lab1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"



/*#include <stdlib.h>
#include <stdio.h>


inline void cmpswap(int a, int b, float * tomb) {
	float buf;
	if (tomb[a] > tomb[b]) {
		buf = tomb[b];
		tomb[b] = tomb[a];
		tomb[a] = buf;
	}
}


void oddeven(float * tomb) {
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

int log2ceil(int value)
{
	int i;
	int cmp = 1;
	for (i = 0; cmp < value; i++)
	{
		cmp <<= 1;
	}
	return i;
}

void sort(int length)
{
	int groups = log2ceil(length);
	for (int group = 0; group < groups; group++)
	{
		int blocks = 1 << (groups - group - 1);
		for (int block = 0; block < blocks; block++)
		{
			for (int stage = 0; stage <= group; stage++)
			{
				int distance = 1 << (group - stage);
				int startPoint = (stage == 0) ? 0 : distance;
				for (int j = startPoint; j + distance < (2 << group); j += 2 * distance)
				{
					for (int i = 0; i < distance; i++)            // shift startpoints
					{
						int x = (block * (length / blocks)) + j + i;
						int y = x + distance;
						if ((x < 25) && (y < 25)) {
							printf("%2i cmp %2i\n", x, y);
						}

					}
				}
			}
		}
	}
}

int main(char* argv, int args)
{
	const int COUNT = 24;
	sort(COUNT);
	system("pause");
}*/


#include "memory.h"
#include "time.h"

#include "omp.h"

#include <IL/ilut.h>
#include <IL/ilu.h>

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"
#include "func.h"


void main()
{
	ilInit(); iluInit();
	ILboolean ret;
	ILuint ilImg=0;
	ilGenImages(1, &ilImg);
	ilBindImage(ilImg);
    ret = ilLoadImage((const char*)("input.jpg"));
	ILubyte* imgData = ilGetData(); 

	int imgWidth = ilGetInteger(IL_IMAGE_WIDTH);
	int imgHeight = ilGetInteger(IL_IMAGE_HEIGHT);
	ILint imgOrigin = ilGetInteger(IL_ORIGIN_MODE);

	printf("Input resolution: %4dx%4d\n", imgWidth, imgHeight);

	float *imgFloat;
	int imgWidthF = imgWidth+FILTER_W-1;
	int imgHeightF = imgHeight+FILTER_H-1;
	int imgFOffsetW = (FILTER_W-1)/2;
	int imgFOffsetH = (FILTER_H-1)/2;
	imgFloat   = (float *)(_aligned_malloc(4*imgWidthF*imgHeightF*sizeof(float), 32));
    int row, col;

	for (row=0; row<imgHeightF; row++)
	{
		for (col=0; col<imgWidthF;col++)
		{
			int pixel = (row*imgWidthF + col)*4;
			*(imgFloat+pixel+0) = 0.0f;
			*(imgFloat + pixel + 1) = 0.0f;
			*(imgFloat + pixel + 2) = 0.0f;
			*(imgFloat + pixel + 3) = 0.0f;
		}
	}

	for (row=0; row<imgHeight; row++)
	{
		for (col=0; col<imgWidth;col++)
		{
			int pixel_dst = ((row+imgFOffsetH)*imgWidthF + (col+imgFOffsetW))*4;
			int pixel_src = (row*imgWidth + col)*3;
			*(imgFloat+pixel_dst+0) = (float)(*(imgData+pixel_src+0));
			*(imgFloat+pixel_dst+1) = (float)(*(imgData+pixel_src+1));
			*(imgFloat+pixel_dst+2) = (float)(*(imgData+pixel_src+2));
			*(imgFloat+pixel_dst+3) = 0.0;
		}
	}


// IMAGE PROCESSING
//---------------------------------------------------------------------------------------
	clock_t s0, e0;
    double d0;

	float *imgFloatRes;
    imgFloatRes = (float *)(_aligned_malloc(4*imgWidthF*imgHeightF*sizeof(float), 32));

	float filter_laplace[] = {-1.0, -1.0, -1.0, -1.0, -1.0,
		                      -1.0, -1.0, -1.0, -1.0, -1.0,
		                      -1.0, -1.0, 24.0, -1.0, -1.0,
		                      -1.0, -1.0, -1.0, -1.0, -1.0,
		                      -1.0, -1.0, -1.0, -1.0, -1.0};
	double mpixel;


	s0 = clock();
for (int r=0; r<RUNS; r++)
{
	med_filter(imgHeight, imgWidth, imgHeightF, imgWidthF,
				imgFOffsetH, imgFOffsetW,
				filter_laplace, imgFloat, imgFloatRes);
}

    e0 = clock();
    d0 = (double)(e0-s0)/(RUNS*CLOCKS_PER_SEC);
	mpixel = (imgWidth*imgHeight/d0)/1000000;
    printf("C CPU TIME: %4.4f\n", d0);
	printf("C Mpixel/s: %4.4f\n", mpixel);



	float *imgFloatWrite;
	imgFloatWrite = imgFloatRes;

//---------------------------------------------------------------------------------------
// IMAGE PROCESSING END


	for (row=0; row<imgHeight; row++)
	{
		for (col=0; col<imgWidth;col++)
		{
			int pixel_src = (row*imgWidth + col)*4;
			int pixel_dst = (row*imgWidth + col)*3;
			*(imgData+pixel_dst+0) = (ILubyte)(*(imgFloatWrite+pixel_src+0));
			*(imgData+pixel_dst+1) = (ILubyte)(*(imgFloatWrite+pixel_src+1));
			*(imgData+pixel_dst+2) = (ILubyte)(*(imgFloatWrite+pixel_src+2));
		}
	}


	_aligned_free(imgFloat);
    _aligned_free(imgFloatRes);

	ret = ilSetData(imgData);
	ilEnable(IL_FILE_OVERWRITE);
    ilSaveImage((const char*)("output.jpg"));
	ilDeleteImages(1, &ilImg);
}

