#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"
#include "immintrin.h"

#include "defs.h"

#include "sorter.h"

#define SIZE 25						//legközelebbi 2 hatvány

void median_filter(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF, float *imgFloatSrc, float *imgFloatDst)
{

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

	for (row = 0; row < imgHeight; row++)
	{
		// A sorokon belül végiglépkedünk egy sor pixelein

		for (col = 0; col < imgWidth; col++)
		{
			ext_adress = (row * imgWidthF + col) * 4;
			wr_base = (row * imgWidth + col) * 4;

			for (i = 0; i < 4; i++)
			{
				for (row_filter = 0; row_filter < FILTER_H; row_filter++)
				{

					for (col_filter = 0; col_filter < FILTER_W; col_filter++)
					{
						//tömb feltöltése a szükséges adatokkal
						data[row_filter * FILTER_W + col_filter] = imgFloatSrc[ext_adress + (row_filter*imgWidthF + col_filter) * 4 + i];
					}
				}

				odd_even_sort(data);	//rendező alg
				imgFloatDst[wr_base + i] = data[12];	//medián visszaadása
			}
		}
	}
}
