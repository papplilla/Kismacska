
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
			int pixel_offset = (row *imgWidth + col) * 3;

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

	printf("Minden ok\n");
	return 0;
}

//#define ONLY_VERIFY
//#define VERIFY_AND_RUN

void main()
{
#ifdef  ONLY_VERIFY
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

	int imgWidthF = imgWidth+FILTER_W-1;
	int imgHeightF = imgHeight+FILTER_H-1;
	int imgFOfssetW = (FILTER_W-1)/2;
	int imgFOfssetH = (FILTER_H-1)/2;
	
	unsigned char *imgSrc;
	unsigned char *imgRes;
	memalloc_host(imgWidthF, imgHeightF, &imgSrc, imgWidth, imgHeight, &imgRes);

    int row, col;

	for (row=0; row<imgHeightF; row++)
	{
		for (col=0; col<imgWidthF;col++)
		{
			int pixel = (row*imgWidthF + col)*3;
			*(imgSrc + pixel + 0) = 0;
			*(imgSrc + pixel + 1) = 0;
			*(imgSrc + pixel + 2) = 0;
		}
	}

	for (row=0; row<imgHeight; row++)
	{
		for (col=0; col<imgWidth;col++)
		{
			int pixel_dst = ((row+imgFOfssetH)*imgWidthF + (col+imgFOfssetW))*3;
			int pixel_src = (row*imgWidth + col)*3;
			*(imgSrc + pixel_dst + 0) = (unsigned char)(*(imgData + pixel_src + 0));
			*(imgSrc + pixel_dst + 1) = (unsigned char)(*(imgData + pixel_src + 1));
			*(imgSrc + pixel_dst + 2) = (unsigned char)(*(imgData + pixel_src + 2));
		}
	}


// IMAGE PROCESSING
//---------------------------------------------------------------------------------------
	clock_t s0, e0;
    double d0;


	double mpixel;

#if 0
	s0 = clock();
for (int r=0; r<RUNS; r++)
{
    conv_filter(imgHeight, imgWidth, imgWidthF,
				filter_laplace, imgSrc, imgRes);
}

    e0 = clock();
    d0 = (double)(e0-s0)/(RUNS*CLOCKS_PER_SEC);
	mpixel = (imgWidth*imgHeight/d0)/1000000;
    printf("C CPU TIME: %4.4f\n", d0);
	printf("C Mpixel/s: %4.4f\n", mpixel);
#endif

	cudaMain(imgHeight, imgWidth, imgHeightF, imgWidthF,
		     imgSrc, imgRes);


//---------------------------------------------------------------------------------------
// IMAGE PROCESSING END

	for (row=0; row<imgHeight; row++)
	{
		for (col=0; col<imgWidth;col++)
		{
			int pixel_src = (row*imgWidth + col) * 3;
			int pixel_dst = (row*imgWidth + col) * 3;
			//int pixel_dst = ((row + imgFOfssetH)*imgWidthF + (col + imgFOfssetW)) * 4;

			*(imgData + pixel_dst + 0) = (ILubyte)(*(imgRes + pixel_src + 0));
			*(imgData + pixel_dst + 1) = (ILubyte)(*(imgRes + pixel_src + 1));
			*(imgData + pixel_dst + 2) = (ILubyte)(*(imgRes + pixel_src + 2));
		}
	}

	//_aligned_free(imgSrc);
    //_aligned_free(imgRes);
	memfree_host(&imgSrc, &imgRes);


	ret = ilSetData(imgData);
	ilEnable(IL_FILE_OVERWRITE);
    ilSaveImage((const char*)("output.jpg"));
	
	#ifdef VERIFY_AND_RUN
		ilSaveImage((const char*)("output.bmp"));				// teszteléshez
	#endif // VERIFY_AND_RUN

		ilDeleteImages(1, &ilImg);

	#ifdef VERIFY_AND_RUN
		verifyImage();
	#endif // VERIFY_AND_RUN

#endif	// ONLY_VERIFY
}

