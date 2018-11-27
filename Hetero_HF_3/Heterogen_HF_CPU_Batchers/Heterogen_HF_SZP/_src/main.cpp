#include "memory.h"
#include "time.h"

#include "omp.h"

#include <IL/ilut.h>
#include <IL/ilu.h>

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"
#include "func.h"

int verifyImage();
int verifyImage()
{

// Általunk számolt kimeneti kép
	ilInit(); iluInit();
	ILboolean ret;
	ILuint ilImg = 0;
	ilGenImages(1, &ilImg);
	ilBindImage(ilImg);
	//ret = ilLoadImage((const char*)("output.jpg"));
	ret = ilLoadImage((const char*)("output.bmp"));
	ILubyte* imgData = ilGetData();

	int imgWidth = ilGetInteger(IL_IMAGE_WIDTH);
	int imgHeight = ilGetInteger(IL_IMAGE_HEIGHT);
	ILint imgOrigin = ilGetInteger(IL_ORIGIN_MODE);

	printf("Teszt started\n");
	printf("Output resolution: %4dx%4d\n", imgWidth, imgHeight);

	//float *imgFloat;
	//imgFloat = (float *)(_aligned_malloc(4 * imgWidth*imgHeight * sizeof(float), 32));

// Teszt kép
	ILboolean retRef;
	ILuint ilImgRef = 0;
	ilGenImages(1, &ilImgRef);
	ilBindImage(ilImgRef);
	//retRef = ilLoadImage((const char*)("hf_output_ref.jpg"));
	retRef = ilLoadImage((const char*)("hf_output_ref.bmp"));
	ILubyte* imgDataRef = ilGetData();

	int imgWidthRef = ilGetInteger(IL_IMAGE_WIDTH);
	int imgHeighReft = ilGetInteger(IL_IMAGE_HEIGHT);
	ILint imgOriginRef = ilGetInteger(IL_ORIGIN_MODE);


	printf("Ref picture resolution: %4dx%4d\n", imgWidth, imgHeight);

	//float *imgFloathf_output_ref;
	//imgFloathf_output_ref = (float *)(_aligned_malloc(4 * imgWidth*imgHeight * sizeof(float), 32));

	if (imgWidth != imgWidthRef)
	{
		printf("Nem egyeznek a szélességek\n");
		return -1;
	}

	if (imgHeight != imgHeighReft)
	{
		printf("Nem egyeznek a hosszúságok\n");
		return -2;
	}

	int row, col;
	for (row = 0; row<imgHeight; row++)
	{
		for (col = 0; col<imgWidth;col++)
		{
			int pixel_offset = (row *imgWidth + col)  * 3;
			
			if ((const char)(*(imgData + pixel_offset)) != (const char)(*(imgDataRef + pixel_offset)))
			{
				
				printf("Baj van!\n");
				
				printf("Erdeti\n");
				printf("%d. Sor, :%d. oszlop: %d \n ", row, col, *(imgDataRef + pixel_offset));

				printf("Sajat\n");
				printf("%d. Sor, :%d. oszlop: %d \n\n ", row, col, *(imgData + pixel_offset));
				//return -3;
			}

		}
	}

	ilDeleteImages(1, &ilImg);
	ilDeleteImages(1, &ilImgRef);

	printf("Minden oké\n");
	return 0;
}

//#define VERIFY
void main()
{
#ifdef  VERIFY

	verifyImage();
#else 
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

	double mpixel;


	s0 = clock();
for (int r=0; r<RUNS; r++)
{
	medianFilter(imgHeight, imgWidth, imgWidthF, imgFOffsetH, imgFOffsetW, imgFloat, imgFloatRes);
	//medianFilterAVX(imgHeight, imgWidth, imgWidthF, imgFOffsetH, imgFOffsetW, imgFloat, imgFloatRes);

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
			int pixel_src = ((row+2)*imgWidth + col+2)*4;
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
    //ilSaveImage((const char*)("output.jpg"));
    ilSaveImage((const char*)("output.bmp"));				// teszteléshez
	ilDeleteImages(1, &ilImg);

	verifyImage();

#endif
}

