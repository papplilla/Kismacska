#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"

#include <stdlib.h>

#include <algorithm>

void mergeSort(float * tomb);

/*void bubble(int n, float * tomb) {
	float buf;
	for (int i = n; i >= 11; i--) {
		for (int j = 1; j <= i - 1; j++) {
			if (tomb[j] > tomb[j + 1]){
				buf = tomb[j];
				tomb[j] = tomb[j + 1];
				tomb[j + 1] = buf;
			}
		}
	}
}*/

/*inline void cmpswap(int a, int b, float * tomb) {
	float buf;
			if (tomb[a] > tomb[b]) {
				buf = tomb[b];
				tomb[b] = tomb[a];
				tomb[a] = buf;
			}
}
*/
inline void cmpswap2(int a, int b, float * tomb) {
	float buf1 = tomb[a];
	float buf2 = tomb[b];
	tomb[a] = std::max(buf1, buf2);
	tomb[b] = std::min(buf1, buf2);
}


#define PIXEL_COMPARE_AND_SWAP(x, y) if (tomb[(x)] > tomb[(y)]) { tmp = tomb[(y)];tomb[(y)] = tomb[(x)];tomb[(x)] = tmp;	}	
	

void mergeSort(float * tomb) {
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

void mergeSortFull(float * tomb) {
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

	//cmpswap(19, 21);
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

	PIXEL_COMPARE_AND_SWAP(20, 21);


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

void medianFilter(int imgHeight, int imgWidth, int imgWidthF, float *imgFloatSrc, float *imgFloatDst)
{
	// Kép sorai
	for (int y=0; y<imgHeight; y++)
		// Kép oszlopai
		for (int x=0; x<imgWidth; x++)
			// Szín komponensek
			for (int rgb = 0; rgb < 4; rgb++)
			{			
				float medianArray[25];

				for (int medianY = 0; medianY < 5; medianY++) 
					for (int medianX = 0; medianX < 5; medianX++) 
						medianArray[5*medianY  + medianX] = imgFloatSrc[((y+ medianY )*imgWidthF + x + medianX)*4 + rgb];

				mergeSort(medianArray);
				imgFloatDst[(y*imgWidth + x) * 4 + rgb] = medianArray[MEDIAN];
			}
}





void conv_filter_sse(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF,
				 int imgFOfssetH, int imgFOfssetW,
				 float *filter, float *imgFloatSrc, float *imgFloatDst)
{

	__declspec(align(16)) __m128 const_0 = _mm_set_ps(0.0, 0.0, 0.0, 0.0);
    __declspec(align(16)) __m128 const_255 = _mm_set_ps(255.0, 255.0, 255.0, 255.0);

	// szűrő együtthatók négyszerezése
	float filter_ext[4*FILTER_W*FILTER_H];
	for (int i=0; i<4*FILTER_W*FILTER_H; i++)
		filter_ext[i] = filter[i/4];
	
	// float -> m128 konverzió
	__declspec(align(16)) __m128 filter_l[FILTER_W*FILTER_H];
	for (unsigned int i=0; i<4*FILTER_W*FILTER_H; i++)
		filter_l[i>>2].m128_f32[i&0x3]=*(filter_ext+i);




}

void conv_filter_sse2(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF,
	int imgFOfssetH, int imgFOfssetW,
	float *filter, float *imgFloatSrc, float *imgFloatDst)
{


#if USE_OMP==1
#pragma omp parallel
	{
#pragma omp for \
    schedule(dynamic, 1) nowait
#else
	{
#endif
		for (int row = 0; row < imgHeight; row++)
		{
			for (int col = 0; col<imgWidth; col = col + 8)
			{
				int pixel_src = (row*imgWidthF + col) * 4;
				int pixel_dst = (row*imgWidth + col) * 4;
				__m128 fval[8];
				fval[0] = _mm_set_ps1(0.0f);
				fval[1] = _mm_set_ps1(0.0f);
				fval[2] = _mm_set_ps1(0.0f);
				fval[3] = _mm_set_ps1(0.0f);
				fval[4] = _mm_set_ps1(0.0f);
				fval[5] = _mm_set_ps1(0.0f);
				fval[6] = _mm_set_ps1(0.0f);
				fval[7] = _mm_set_ps1(0.0f);

				int addr = pixel_src;
				for (int fy = 0; fy<FILTER_H; fy++)
				{
					int fx = 0;
					//for (int fx=0; fx<FILTER_W; fx++)
					{
						// Adott együttható-sor betöltése 5 SSE regiszterbe
						__m128 coeff[5];
						coeff[0] = _mm_set_ps1(*(filter + fy * 5 + 0));
						coeff[1] = _mm_set_ps1(*(filter + fy * 5 + 1));
						coeff[2] = _mm_set_ps1(*(filter + fy * 5 + 2));
						coeff[3] = _mm_set_ps1(*(filter + fy * 5 + 3));
						coeff[4] = _mm_set_ps1(*(filter + fy * 5 + 4));

						__m128 pixel, mul_res;

						// 0. pixel konvolúciója a 0. együtthatóval --> 0. akkumulátor
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[0] = _mm_add_ps(fval[0], mul_res);

						// 1. pixel töltése
						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[0] = _mm_add_ps(fval[0], mul_res);			// 0. akku: 1. pixel és 1. együttható
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[1] = _mm_add_ps(fval[1], mul_res);			// 1. akku: 1. pixel és 0. együttható

																		// 2. pixel töltése
						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[0] = _mm_add_ps(fval[0], mul_res);			// 0. akku: 2. pixel és 2. együttható
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[1] = _mm_add_ps(fval[1], mul_res);			// 1. akku: 2. pixel és 1. együttható
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[2] = _mm_add_ps(fval[2], mul_res);			// 3. akku: 2. pixel és 0. együttható

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[3]);
						fval[0] = _mm_add_ps(fval[0], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[1] = _mm_add_ps(fval[1], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[2] = _mm_add_ps(fval[2], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[3] = _mm_add_ps(fval[3], mul_res);

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[4]);
						fval[0] = _mm_add_ps(fval[0], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[3]);
						fval[1] = _mm_add_ps(fval[1], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[2] = _mm_add_ps(fval[2], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[3] = _mm_add_ps(fval[3], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[4] = _mm_add_ps(fval[4], mul_res);

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[4]);
						fval[1] = _mm_add_ps(fval[1], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[3]);
						fval[2] = _mm_add_ps(fval[2], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[3] = _mm_add_ps(fval[3], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[4] = _mm_add_ps(fval[4], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[5] = _mm_add_ps(fval[5], mul_res);

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[4]);
						fval[2] = _mm_add_ps(fval[2], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[3]);
						fval[3] = _mm_add_ps(fval[3], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[4] = _mm_add_ps(fval[4], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[5] = _mm_add_ps(fval[5], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[6] = _mm_add_ps(fval[6], mul_res);

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[4]);
						fval[3] = _mm_add_ps(fval[3], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[3]);
						fval[4] = _mm_add_ps(fval[4], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[5] = _mm_add_ps(fval[5], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[6] = _mm_add_ps(fval[6], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[7] = _mm_add_ps(fval[7], mul_res);

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[4]);
						fval[4] = _mm_add_ps(fval[4], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[3]);
						fval[5] = _mm_add_ps(fval[5], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[6] = _mm_add_ps(fval[6], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[7] = _mm_add_ps(fval[7], mul_res);

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[4]);
						fval[5] = _mm_add_ps(fval[5], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[3]);
						fval[6] = _mm_add_ps(fval[6], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[7] = _mm_add_ps(fval[7], mul_res);

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[4]);
						fval[6] = _mm_add_ps(fval[6], mul_res);
						mul_res = _mm_mul_ps(pixel, coeff[3]);
						fval[7] = _mm_add_ps(fval[7], mul_res);

						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[4]);
						fval[7] = _mm_add_ps(fval[7], mul_res);
					}
					addr = addr - 11 * 4;
					addr = addr + imgWidthF * 4;
				}

				__m128 const_0, const_255;
				const_0 = _mm_set_ps1(0.0f);
				const_255 = _mm_set_ps1(255.0f);

				fval[0] = _mm_min_ps(fval[0], const_255);
				fval[0] = _mm_max_ps(fval[0], const_0);
				fval[1] = _mm_min_ps(fval[1], const_255);
				fval[1] = _mm_max_ps(fval[1], const_0);
				fval[2] = _mm_min_ps(fval[2], const_255);
				fval[2] = _mm_max_ps(fval[2], const_0);
				fval[3] = _mm_min_ps(fval[3], const_255);
				fval[3] = _mm_max_ps(fval[3], const_0);
				fval[4] = _mm_min_ps(fval[4], const_255);
				fval[4] = _mm_max_ps(fval[4], const_0);
				fval[5] = _mm_min_ps(fval[5], const_255);
				fval[5] = _mm_max_ps(fval[5], const_0);
				fval[6] = _mm_min_ps(fval[6], const_255);
				fval[6] = _mm_max_ps(fval[6], const_0);
				fval[7] = _mm_min_ps(fval[7], const_255);
				fval[7] = _mm_max_ps(fval[7], const_0);


				_mm_stream_ps((imgFloatDst + pixel_dst + 0), fval[0]);
				_mm_stream_ps((imgFloatDst + pixel_dst + 4), fval[1]);
				_mm_stream_ps((imgFloatDst + pixel_dst + 8), fval[2]);
				_mm_stream_ps((imgFloatDst + pixel_dst + 12), fval[3]);
				_mm_stream_ps((imgFloatDst + pixel_dst + 16), fval[4]);
				_mm_stream_ps((imgFloatDst + pixel_dst + 20), fval[5]);
				_mm_stream_ps((imgFloatDst + pixel_dst + 24), fval[6]);
				_mm_stream_ps((imgFloatDst + pixel_dst + 28), fval[7]);
			}
		}
	}
	}