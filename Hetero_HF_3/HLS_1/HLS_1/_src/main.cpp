#include "ap_int.h"
#include "ap_fixed.h"

#include "types.h"

#define SWAP(a,b) temp=a;a=b;b=temp;
#define N 25

static row_t row = 0; 			//0,1,2,3,4
static col_t col = 0; 			//0,1,2,....1280-1

#define PIXEL_COMPARE_AND_SWAP(x, y) if(arr[(x)] > arr[(y)]) { tmp = arr[(y)];arr[(y)] = arr[(x)];arr[(x)] = tmp;	}	

#define MEDIAN 12

//1. m�sszer
pix_t mergeSort(pix_t arr[25])
//2. m�sszer
//pix_t mergeSort(pix_t arrIn[25])
{
	pix_t tmp;
	//2. m�dszer
	//pix_t arr[N] = { 0 };
	//for (int i = 0; i < 15; i++)
	//	arr[i] = arrIn[i]


	//float tmp;
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

	PIXEL_COMPARE_AND_SWAP(16, 18);
	PIXEL_COMPARE_AND_SWAP(17, 19);

	PIXEL_COMPARE_AND_SWAP(17, 18);


	PIXEL_COMPARE_AND_SWAP(16, 20);
	PIXEL_COMPARE_AND_SWAP(17, 21);

	PIXEL_COMPARE_AND_SWAP(17, 18);


	PIXEL_COMPARE_AND_SWAP(16, 24);

	PIXEL_COMPARE_AND_SWAP(17, 18);

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


	PIXEL_COMPARE_AND_SWAP(4, 8);
	PIXEL_COMPARE_AND_SWAP(5, 9);
	PIXEL_COMPARE_AND_SWAP(6, 10);
	PIXEL_COMPARE_AND_SWAP(7, 11);

	PIXEL_COMPARE_AND_SWAP(12, 16);
	PIXEL_COMPARE_AND_SWAP(13, 17);

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
	

	return arr[MEDIAN];
}

void median_filter_hls(pix_t in_pix[3], int n_line, pix_t out_pix[3]) {

	//pipeline a f�ggv�nyre (unroll a benne l�v� loop-okra)
#pragma HLS PIPELINE II=2

	//kimenetre reshape: p�rhuzamosan el�rj�k az elemeit
#pragma HLS ARRAY_RESHAPE variable=out_pix complete dim=1

	static pix_t win[4][1280 * 3] = { { 0 } }; 	//4 sor t�rol�sa
#pragma HLS ARRAY_PARTITION variable=win factor=4 dim=1 //sorbuffer soronk�nti el�r�se

												//komponens ablakok
	static pix_t in_R[25] = { 0 };
	static pix_t in_G[25] = { 0 };
	static pix_t in_B[25] = { 0 };

	//ablakok elemenk�nti el�r�se
#pragma HLS ARRAY_PARTITION variable=in_R complete
#pragma HLS ARRAY_PARTITION variable=in_G complete
#pragma HLS ARRAY_PARTITION variable=in_B complete


	if (n_line) { //�j sor eset�n az oszlopsz�ml�l�t null�zzuk
		col = 0;
		row++; //sorsz�ml�l�t n�velj�k
		if (row == 4) row = 0;
	}

	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			//0. 1. 2. 3. oszlop felt�lt�se
			//az oszlopokat a 5x5-as m�trixban balra shiftelj�k
			in_R[i * 5 + j - 1] = in_R[i * 5 + j];
			in_G[i * 5 + j - 1] = in_G[i * 5 + j];
			in_B[i * 5 + j - 1] = in_B[i * 5 + j];
		}

		if (i == 4) {
			//ott tartunk, ahov� �pp �rjuk az �j pixelt ->
			//nem win-t olvassuk, hanem k�zvetlen a pixelt haszn�ljuk
			in_R[i * 5 + 4] = in_pix[0];
			in_G[i * 5 + 4] = in_pix[1];
			in_B[i * 5 + 4] = in_pix[2];
		}
		else {
			//kiolvassuk a pixelt�rol�b�l az �rt�keket
			in_R[i * 5 + 4] = win[i][col * 3 + 0];
			in_G[i * 5 + 4] = win[i][col * 3 + 1];
			in_B[i * 5 + 4] = win[i][col * 3 + 2];
		}
	}
	//buffer friss�t�se a bej�v� �rt�kekkel
	for (i = 0; i < 3; i++)
		win[row][col * 3 + i] = in_pix[i];
	//sz�nkomponensenk�nti sz�r�s
	out_pix[0] = mergeSort(in_R);
	out_pix[1] = mergeSort(in_G);
	out_pix[2] = mergeSort(in_B);

	col++;
}
