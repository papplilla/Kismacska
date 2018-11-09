#include "omp.h"
#include "emmintrin.h"
#include "nmmintrin.h"
#include "defs.h"
#include "func.h"

#include <stdio.h>

/*void median_filter(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF, unsigned char *imgSrcExt, unsigned char *imgDst)
{
	printf("Median filter called\n");
	float data[SIZE] = { 0 };	//megfelelő méretü munkatömb


								// írási bázis: 0. sor, 0. oszlop (a kimenet NEM kiterjesztett)
	int wr_base = 0;
	// olvasási bázis: a kiterjesztett kép bal felső pixele (ez az első konvolúció első bemeneti adata)
	int rd_base = 0;

	int ext_adress;
	// Végiglépkedünk a kép sorain

	int row_filter;
	int col_filter;
	int i, col, row;

	printf("Median: Pixel steps START\n");

	for (row = 0; row < imgHeight; row++)
	{
		// A sorokon belül végiglépkedünk egy sor pixelein

		for (col = 0; col < imgWidth; col++)
		{
			printf("Pixel: %dx%d\n", row, col);
			ext_adress = (row * imgWidthF + col) * 3;
			wr_base = (row * imgWidth + col) * 3;

			for (i = 0; i < 3; i++)
			{
				for (row_filter = 0; row_filter < FILTER_H; row_filter++)
				{

					for (col_filter = 0; col_filter < FILTER_W; col_filter++)
					{
						//tömb feltöltése a szükséges adatokkal
						data[row_filter * FILTER_W + col_filter] = imgSrcExt[ext_adress + (row_filter*imgWidthF + col_filter) * 3 + i];
					}
				}

				odd_even_sort(data);	//rendező alg
				//oddEvenSort(data, 25);
				imgDst[wr_base + i] = data[12];	//medián visszaadása
			}
		}
	}

	printf("Median: Pixel steps STOP\n");
}*/

/*
void median_filter(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF, unsigned char *imgSrcExt, unsigned char *imgDst)
{
	printf("MEDIAN START!\n");

	unsigned char frame[SIZE] = { 0 };

	for (int row = 0; row < imgHeight; row++)
	{
		int wr_base = row * imgWidth * 3;
		int rd_base = row * imgWidthF * 3;

		for (int col = 0; col < imgWidth; col++)
		{
			printf("PIXEL %dx%d\n", row, col);
			int rd_offset = ((FILTER_W-1)/2 + col) * 3;
			short fval[3] = { 0,0,0 };

			int pixel_src = rd_base + rd_offset + (FILTER_H-1)/2 * imgWidthF;
			int filter_src = pixel_src - (FILTER_H - 1) / 2 * imgWidthF;

			printf("Pixel source: %d\nFilter source:%d\n", pixel_src, filter_src);

			for (int rgb = 0; rgb < 3; rgb++)
			{
				for (int fy = 0; fy < FILTER_H; fy++)
				{
					for (int fx = 0; fx < FILTER_W; fx++)
					{
						frame[fx * FILTER_W + fy] = imgSrcExt[filter_src + fx * imgWidthF + fy + rgb];
					}
				}

				oddEvenSort(frame, 25);
				fval[rgb] = frame[12];
				if (fval[rgb] > 255) fval[rgb] = 255;
				if (fval[rgb] < 0)   fval[rgb] = 0;
				*(imgDst + wr_base + rgb) = (unsigned char)(fval[rgb]);

				printf("Pixel src_%d: %d\n", rgb, imgSrcExt[pixel_src+rgb]);
				printf("Pixel mod_%d: %d\n", rgb, fval[rgb]);
			}
	
			wr_base = wr_base + 3;

		}
		wr_base = wr_base + 4 * 3;

	}

	printf("MEDIAN STOP!\n");
}
*/

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


	cmpswap(0, 8, tomb);//
	cmpswap(1, 9, tomb);//
	cmpswap(2, 10, tomb);//
	cmpswap(3, 11, tomb);//
	cmpswap(4, 12, tomb);//
	cmpswap(5, 13, tomb);//
	cmpswap(6, 14, tomb);//
	cmpswap(7, 15, tomb);//


	cmpswap(4, 8, tomb);//2
	cmpswap(5, 9, tomb);//2
	cmpswap(6, 10, tomb);//2
	cmpswap(7, 11, tomb);//2

	cmpswap(2, 4, tomb);//3
	cmpswap(3, 5, tomb);//3
	cmpswap(6, 8, tomb);//???3
	cmpswap(7, 9, tomb);//???3
	cmpswap(10, 12, tomb);//3
	cmpswap(11, 13, tomb);//3
	
	cmpswap(1, 2, tomb);//4
	cmpswap(3, 4, tomb);//4
	cmpswap(5, 6, tomb);//4
	cmpswap(7, 8, tomb);//4
	cmpswap(9, 10, tomb);//4
	cmpswap(11, 12, tomb);//4
	cmpswap(13, 14, tomb);//4

// Eddig 8x8-as (16 bemenet�)

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

	//??????? TODO ?????

	cmpswap(18, 20, tomb);
	cmpswap(19, 21, tomb);//SB
	cmpswap(22, 24, tomb);

	//cmpswap(19, 21, tomb);
	cmpswap(17, 18, tomb);
	cmpswap(19, 20, tomb);
	cmpswap(21, 22, tomb);
	cmpswap(23, 24, tomb);
	//Eddig egy 8x8-as (De ez csak 9 bemenet�)

// 16x16 
	cmpswap(0, 16, tomb);
	cmpswap(1, 17, tomb);
	cmpswap(2, 18, tomb);
	cmpswap(3, 19, tomb);
	cmpswap(4, 20, tomb);
	cmpswap(5, 21, tomb);
	cmpswap(6, 22, tomb);
	cmpswap(7, 23, tomb);
	cmpswap(8, 24, tomb);


	cmpswap(8, 16, tomb);
	cmpswap(9, 17, tomb);
	cmpswap(10, 18, tomb);
	cmpswap(11, 19, tomb);
	cmpswap(12, 20, tomb);
	cmpswap(13, 21, tomb);
	cmpswap(14, 22, tomb);
	cmpswap(15, 23, tomb);


	cmpswap(4, 8, tomb);
	cmpswap(5, 9, tomb);
	cmpswap(6, 10, tomb);
	cmpswap(7, 11, tomb);

	cmpswap(12, 16, tomb);
	cmpswap(13, 17, tomb);
	cmpswap(14, 18, tomb);
	cmpswap(15, 19, tomb);

	cmpswap(20, 21, tomb);


	cmpswap(2, 4, tomb);
	cmpswap(3, 5, tomb);
	cmpswap(6, 8, tomb);
	cmpswap(7, 9, tomb);
	cmpswap(10, 12, tomb);
	cmpswap(11, 13, tomb);
	cmpswap(14, 16, tomb);
	cmpswap(15, 17, tomb);
	cmpswap(18, 20, tomb);
	cmpswap(19, 21, tomb);
	cmpswap(22, 24, tomb);


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
	// irasi bazis: 0. sor, 0. oszlop (a kimenet NEM kiterjesztett)
	int wr_base = 0;
	// olvasasi bazis: a kiterjesztett kep bal felso pixele (ez az elso konvoloci� els� bemeneti adata)
	int rd_base = 0;

	// V�gigl�pked�nk a k�p sorain
	for (int y = 0; y < imgHeight; y++)
	{
		// A sorokon bel�l v�gigl�pked�nk egy sor pixelein
		for (int x = 0; x < imgWidth; x++)
		{
			for (int rgb = 0; rgb < 4; rgb++) {


				// RGBA komponensek akkumul�tora
				float fval[25];

				for (int dy = 0; dy < 5; dy++) {
					for (int dx = 0; dx < 5; dx++) {
						fval[dy * 5 + dx] = imgFloatSrc[(y*imgWidthF + x + dy * imgWidthF + dx) * 4 + rgb];
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

	// sz�r� egy�tthat�k n�gyszerez�se
	float filter_ext[4 * FILTER_W*FILTER_H];
	for (int i = 0; i < 4 * FILTER_W*FILTER_H; i++)
		filter_ext[i] = filter[i / 4];

	// float -> m128 konverzi�
	__declspec(align(16)) __m128 filter_l[FILTER_W*FILTER_H];
	for (unsigned int i = 0; i < 4 * FILTER_W*FILTER_H; i++)
		filter_l[i >> 2].m128_f32[i & 0x3] = *(filter_ext + i);




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
			for (int col = 0; col < imgWidth; col = col + 8)
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
				for (int fy = 0; fy < FILTER_H; fy++)
				{
					int fx = 0;
					//for (int fx=0; fx<FILTER_W; fx++)
					{
						// Adott egy�tthat�-sor bet�lt�se 5 SSE regiszterbe
						__m128 coeff[5];
						coeff[0] = _mm_set_ps1(*(filter + fy * 5 + 0));
						coeff[1] = _mm_set_ps1(*(filter + fy * 5 + 1));
						coeff[2] = _mm_set_ps1(*(filter + fy * 5 + 2));
						coeff[3] = _mm_set_ps1(*(filter + fy * 5 + 3));
						coeff[4] = _mm_set_ps1(*(filter + fy * 5 + 4));

						__m128 pixel, mul_res;

						// 0. pixel konvol�ci�ja a 0. egy�tthat�val --> 0. akkumul�tor
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[0] = _mm_add_ps(fval[0], mul_res);

						// 1. pixel t�lt�se
						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[0] = _mm_add_ps(fval[0], mul_res);			// 0. akku: 1. pixel �s 1. egy�tthat�
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[1] = _mm_add_ps(fval[1], mul_res);			// 1. akku: 1. pixel �s 0. egy�tthat�

																		// 2. pixel t�lt�se
						addr = addr + 4;
						pixel = _mm_load_ps((imgFloatSrc + addr));
						mul_res = _mm_mul_ps(pixel, coeff[2]);
						fval[0] = _mm_add_ps(fval[0], mul_res);			// 0. akku: 2. pixel �s 2. egy�tthat�
						mul_res = _mm_mul_ps(pixel, coeff[1]);
						fval[1] = _mm_add_ps(fval[1], mul_res);			// 1. akku: 2. pixel �s 1. egy�tthat�
						mul_res = _mm_mul_ps(pixel, coeff[0]);
						fval[2] = _mm_add_ps(fval[2], mul_res);			// 3. akku: 2. pixel �s 0. egy�tthat�

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