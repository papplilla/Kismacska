#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"

#include "defs.h"

#include <stdlib.h>

#include <algorithm>

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

inline void cmpswap(int a, int b, float * tomb) {
	float buf;
			if (tomb[a] > tomb[b]) {
				buf = tomb[b];
				tomb[b] = tomb[a];
				tomb[a] = buf;
			}
}

inline void cmpswap2(int a, int b, float * tomb) {
	float buf1 = tomb[a];
	float buf2 = tomb[b];
	tomb[a] = std::max(buf1, buf2);
	tomb[b] = std::min(buf1, buf2);
}

void oddeven(float * tomb) {
// 4x4
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
	cmpswap(1, 5, tomb); //SB
	cmpswap(2, 6, tomb);
	//cmpswap(2, 4, tomb);
	//cmpswap(1, 5, tomb);
	cmpswap(3, 7, tomb);
	
	cmpswap(2, 4, tomb); // SB
	cmpswap(3, 5, tomb);
	
	cmpswap(1, 2, tomb);
	cmpswap(3, 4, tomb);
	cmpswap(5, 6, tomb);
	
// 4x4	
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
	cmpswap(9, 13, tomb); // SB
	cmpswap(10, 14, tomb);
	//cmpswap(10, 12, tomb);
	//cmpswap(9, 13, tomb);
	cmpswap(11, 15, tomb);
	
	cmpswap(10, 12, tomb); // SB
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

void oddevenSB(float * tomb) {
// 4x4
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
	cmpswap(1, 5, tomb); //SB
	cmpswap(2, 6, tomb);
	//cmpswap(2, 4, tomb);
	//cmpswap(1, 5, tomb);
	cmpswap(3, 7, tomb);
	
	cmpswap(2, 4, tomb); // SB
	cmpswap(3, 5, tomb);
	
	cmpswap(1, 2, tomb);
	cmpswap(3, 4, tomb);
	cmpswap(5, 6, tomb);
	
// 4x4	
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
	cmpswap(9, 13, tomb); // SB
	cmpswap(10, 14, tomb);
	//cmpswap(10, 12, tomb);
	//cmpswap(9, 13, tomb);
	cmpswap(11, 15, tomb);
	
	cmpswap(10, 12, tomb); // SB
	cmpswap(11, 13, tomb);
	
	cmpswap(9, 10, tomb);
	cmpswap(11, 12, tomb);
	cmpswap(13, 14, tomb);
	
	
	cmpswap(0, 8, tomb);//
	cmpswap(4, 12, tomb);//
	cmpswap(4, 8, tomb);//2
	cmpswap(2, 10, tomb);//
	cmpswap(6, 14, tomb);//
	cmpswap(6, 10, tomb);//2
	cmpswap(2, 4, tomb);//3
	cmpswap(6, 8, tomb);//???3
	cmpswap(10, 12, tomb);//3
	cmpswap(1, 9, tomb);//
	cmpswap(5, 13, tomb);//
	cmpswap(5, 9, tomb);//2
	cmpswap(3, 11, tomb);//
	cmpswap(7, 15, tomb);//
	cmpswap(7, 11, tomb);//2
	cmpswap(3, 5, tomb);//3
	cmpswap(7, 9, tomb);//???3
	cmpswap(11, 13, tomb);//3
	cmpswap(1, 2, tomb);//4
	cmpswap(3, 4, tomb);//4
	cmpswap(5, 6, tomb);//4
	cmpswap(7, 8, tomb);//4
	cmpswap(9, 10, tomb);//4
	cmpswap(11, 12, tomb);//4
	cmpswap(13, 14, tomb);//4
// Eddig 8x8-as (16 bemenetû)
	
//4x4
	cmpswap(16, 17, tomb);
	cmpswap(18, 19, tomb);
	cmpswap(20, 21, tomb);//SB
	cmpswap(22, 23, tomb);//SB
	
	cmpswap(16, 18, tomb);
	cmpswap(20, 22, tomb);
	cmpswap(17, 19, tomb);
	cmpswap(21, 23, tomb);//SB
	
	cmpswap(17, 18, tomb);
	//cmpswap(20, 21, tomb);
	//cmpswap(22, 23, tomb);
	//cmpswap(20, 22, tomb);
	//cmpswap(21, 23, tomb);
	cmpswap(21, 22, tomb);
	
	
	cmpswap(16, 20, tomb);
	cmpswap(17, 21, tomb);//SB
	cmpswap(18, 22, tomb);
	cmpswap(19, 23, tomb);//SB
	
	cmpswap(18, 20, tomb);
	//cmpswap(17, 21, tomb);
	//cmpswap(19, 23, tomb);
	cmpswap(19, 21, tomb);
	
	cmpswap(17, 18, tomb);
	cmpswap(19, 20, tomb);
	cmpswap(21, 22, tomb);
	
	
	cmpswap(16, 24, tomb);
	
	cmpswap(20, 24, tomb);
	
	cmpswap(18, 20, tomb);
	cmpswap(19, 21, tomb);//SB
	cmpswap(22, 24, tomb);
	
	//cmpswap(19, 21, tomb);
	cmpswap(17, 18, tomb);
	cmpswap(19, 20, tomb);
	cmpswap(21, 22, tomb);
	cmpswap(23, 24, tomb);
//Eddig egy 8x8-as (De ez csak 9 bemenetû)
	
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


void med_filter(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF,
				 int imgFOffsetH, int imgFOffsetW,
				 float *filter, float *imgFloatSrc, float *imgFloatDst)
{
	// írási bázis: 0. sor, 0. oszlop (a kimenet NEM kiterjesztett)
	int wr_base = 0;
	// olvasási bázis: a kiterjesztett kép bal felsõ pixele (ez az elsõ konvolúció elsõ bemeneti adata)
	int rd_base = 0;
	
	// Végiglépkedünk a kép sorain
	for (int y=0; y<imgHeight; y++)
	{
		// A sorokon belül végiglépkedünk egy sor pixelein
		for (int x=0; x<imgWidth; x++)
		{
			for (int rgb = 0; rgb < 4; rgb++) {

			
			// RGBA komponensek akkumulátora
				float fval[25];

				for (int dy = 0; dy < 5; dy++) {
					for (int dx = 0; dx < 5; dx++) {
						fval[dy * 5 + dx] = imgFloatSrc[(y*imgWidthF + x + dy*imgWidthF + dx) * 4 + rgb];
					}
				}

				oddeven(fval);

				imgFloatDst[(y*imgWidth + x) * 4 + rgb] = fval[12];
		

			}
		}
	}
}



void conv_filter_sse(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF,
				 int imgFOfssetH, int imgFOfssetW,
				 float *filter, float *imgFloatSrc, float *imgFloatDst)
{

	__declspec(align(16)) __m128 const_0 = _mm_set_ps(0.0, 0.0, 0.0, 0.0);
    __declspec(align(16)) __m128 const_255 = _mm_set_ps(255.0, 255.0, 255.0, 255.0);

	// szûrõ együtthatók négyszerezése
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