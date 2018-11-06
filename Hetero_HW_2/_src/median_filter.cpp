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
