// lab1.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
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

	unsigned char *imgSrcExt;
	int imgWidthF = imgWidth+FILTER_W-1;			// 2-es kiterjesztés minden irányból
	int imgHeightF = imgHeight+FILTER_H-1;
	int imgFOfssetW = (FILTER_W-1)/2;				// 2-es offszet
	int imgFOfssetH = (FILTER_H-1)/2;				// 2-es offszet
	imgSrcExt = (unsigned char *)(_aligned_malloc(3*imgWidthF*imgHeightF*sizeof(unsigned char), 32));
    int row, col, rgb;


/*	
// kinullázza a kiterjesztett képet
	for (row=0; row<imgHeightF; row++)
	{
		for (col=0; col<imgWidthF;col++)
		{
			int pixel = (row*imgWidthF + col)*3;
			*(imgSrcExt + pixel + 0) = 0;
			*(imgSrcExt + pixel + 1) = 0;
			*(imgSrcExt + pixel + 2) = 0;
		}
	}

//  eredeti kép  másolása a kiterjesztett képbe
	for (row=0; row<imgHeight; row++)
	{
		for (col=0; col<imgWidth;col++)
		{
			int pixel_dst = ((row+imgFOfssetH)*imgWidthF + (col+imgFOfssetW))*3;
			int pixel_src = (row*imgWidth + col)*3;
			*(imgSrcExt + pixel_dst + 0) = (unsigned char)(*(imgData + pixel_src + 0));
			*(imgSrcExt + pixel_dst + 1) = (unsigned char)(*(imgData + pixel_src + 1));
			*(imgSrcExt + pixel_dst + 2) = (unsigned char)(*(imgData + pixel_src + 2));
		}
	}
	*/
	
	// ========= SB =======
	//enum class Color { RED = 0, GREEN = 1, BLUE = 2 };
	#define SRC_PIXEL(ROW, COL) 	((((ROW)+imgFOfssetH)*imgWidthF + ((COL) +imgFOfssetW))*3)
	#define DST_PIXEL(ROW, COL)		(((ROW)*imgWidth + (COL))*3)
	
	
	for (row=0; row<imgHeightF; row++)
		for (col=0; col<imgWidthF;col++)
			// 0. és 1. sor 		utolsó 2 sor		0. és e1. oszlop	utolsó 2 oszlop
			if(row < imgFOfssetH || row >= imgHeight || col < imgFOfssetW || col >= imgWidth)
				for(rgb=0; rgb<3; rgb++)
					*(imgSrcExt + pixel + rgb) = 0;			// keret kinullázása
			else
				for(rgb=0; rgb<3; rgb++)
					*(imgSrcExt + DST_PIXEL(row, col) + rgb) = (unsigned char)(*(imgData + SRC_PIXEL(row, col) + rgb));
		
	

	unsigned char *imgRes;
	imgRes = (unsigned char *)(_aligned_malloc(3 * imgWidth*imgHeight * sizeof(unsigned char), 32));

// IMAGE PROCESSING
//---------------------------------------------------------------------------------------
	clock_t s0, e0;
    double d0;

	short filter_laplace[] = {-1, -1, -1, -1, -1,
	                          -1, -1, -1, -1, -1,
	                          -1, -1, 24, -1, -1,
		                      -1, -1, -1, -1, -1,
		                      -1, -1, -1, -1, -1};
	double mpixel;

	short *imgDstConv;
	imgDstConv = (short*)(_aligned_malloc(3 * imgWidthF*imgHeightF * sizeof(short), 32));

	printf("Start convolution\n");
	s0 = clock();
for (int r=0; r<RUNS; r++)
{
#if 0
	conv_filter(imgHeight, imgWidth, imgWidthF,
		filter_laplace, imgSrcExt, imgRes);
#endif

#if 1
    conv_filter_avx(imgHeight, imgWidth, imgWidthF,
				filter_laplace, imgSrcExt, imgRes);
#endif
}

    e0 = clock();
    d0 = (double)(e0-s0)/(RUNS*CLOCKS_PER_SEC);
	mpixel = (imgWidth*imgHeight/d0)/1000000;
    printf("C CPU TIME: %4.4f\n", d0);
	printf("C Mpixel/s: %4.4f\n", mpixel);



	    s0 = clock();
for (int r=0; r<RUNS; r++)
{
/*
	conv_filter_sse(imgHeight, imgWidth, imgHeightF, imgWidthF,
				imgFOfssetH, imgFOfssetW,
				filter_laplace, imgFloat, imgFloatRes);
	
	conv_filter(imgHeight, imgWidth, imgHeightF, imgWidthF,
		imgFOfssetH, imgFOfssetW,
		filter_laplace, imgFloat, imgFloatRes);

	conv_filter_block_sse(imgHeight, imgWidth, imgHeightF, imgWidthF,
		imgFOfssetH, imgFOfssetW,
		filter_laplace, imgFloat, imgFloatRes);
*/
}
    e0 = clock();
    d0 = (double)(e0-s0)/(RUNS*CLOCKS_PER_SEC);
	mpixel = (imgWidth*imgHeight/d0)/1000000;
    printf("SSE CPU TIME: %4.4f\n", d0*1000);
	printf("SSE Mpixel/s: %4.4f\n", mpixel);

/*
    s0 = clock();
for (int r=0; r<RUNS; r++)
{
    conv_filter_asm(imgHeight, imgWidth, imgHeightF, imgWidthF,
				imgFOfssetH, imgFOfssetW,
				filter_laplace, imgFloat, imgFloatRes);
}
    e0 = clock();
    d0 = (double)(e0-s0)/(RUNS*CLOCKS_PER_SEC);
	mpixel = (imgWidth*imgHeight/d0)/1000000;
	printf("ASM CPU TIME: %4.4f\n", d0);
	printf("ASM Mpixel/s: %4.4f\n", mpixel);
*/

//---------------------------------------------------------------------------------------
// IMAGE PROCESSING END

	for (row=0; row<imgHeight; row++)
	{
		for (col=0; col<imgWidth;col++)
		{
			int pixel_src = (row*imgWidth + col)*3;
			int pixel_dst = (row*imgWidth + col)*3;
			*(imgData + pixel_dst + 0) = (ILubyte)(*(imgRes + pixel_src + 0));
			*(imgData + pixel_dst + 1) = (ILubyte)(*(imgRes + pixel_src + 1));
			*(imgData + pixel_dst + 2) = (ILubyte)(*(imgRes + pixel_src + 2));
		}
	}

	_aligned_free(imgDstConv);
	_aligned_free(imgSrcExt);
    _aligned_free(imgRes);

	ret = ilSetData(imgData);
	ilEnable(IL_FILE_OVERWRITE);
    ilSaveImage((const char*)("output.jpg"));
	ilDeleteImages(1, &ilImg);
}

