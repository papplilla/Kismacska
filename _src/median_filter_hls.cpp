#include "ap_int.h"
#include "ap_fixed.h"

typedef ap_uint<8> pix_t; //8 bites unsigned int: RGB komponensek 8 bitesek
typedef ap_uint<3> row_t; //3 bites unsigned int (5 sor)
typedef ap_uint<11> col_t;//11 bites unsigned int (1280 oszlop)

#include "ap_int.h"
#include "ap_fixed.h"

#include "types.h"
#include "defs.h"

#define N 25

static row_t row = 0; 			//0,1,2,3,4
static col_t col = 0; 			//0,1,2,....1280-1

pix_t median_hw(pix_t data_in[25]) {
	pix_t temp = 0.0f;
	pix_t data[N] = { 0 };

	for (int i = 0; i< 25; i++)
	{
		data[i] = data_in[i];
	}


	for (int i = 1; i < 24; i += 2) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
	}

	for (int i = 1; i < 22; i += 4) {
		if (data[i] > data[i + 2])
		{
			SWAP(data[i], data[i + 2]);
		}
		if (data[i + 1] > data[i + 3])
		{
			SWAP(data[i + 1], data[i + 3]);
		}
	}

	for (int i = 2; i < 23; i += 4) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
	}

	for (int i = 1; i < 22; i += 8) {
		if (data[i] > data[i + 4])
		{
			SWAP(data[i], data[i + 4]);
		}
		if (data[i + 1] > data[i + 5])
		{
			SWAP(data[i + 1], data[i + 5]);
		}
		if (data[i + 2] > data[i + 6])
		{
			SWAP(data[i + 2], data[i + 6]);
		}
		if (data[i + 3] > data[i + 7])
		{
			SWAP(data[i + 3], data[i + 7]);
		}
	}

	for (int i = 3; i < 22; i += 8) {
		if (data[i] > data[i + 2])
		{
			SWAP(data[i], data[i + 2]);
		}
		if (data[i + 1] > data[i + 3])
		{
			SWAP(data[i + 1], data[i + 3]);
		}
	}

	for (int i = 2; i < 22; i += 8) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
		if (data[i + 2] > data[i + 3])
		{
			SWAP(data[i + 2], data[i + 3]);
		}
		if (data[i + 4] > data[i + 5])
		{
			SWAP(data[i + 4], data[i + 5]);
		}
	}

	if (data[0] > data[8])
	{
		SWAP(data[0], data[8]);
	}

	for (int i = 9; i < 17; i++) {
		if (data[i] > data[i + 8])
		{
			SWAP(data[i], data[i + 8]);
		}
	}

	if (data[0] > data[4])
	{
		SWAP(data[0], data[4]);
	}

	for (int i = 13; i < 17; i++) {
		if (data[i] > data[i + 4])
		{
			SWAP(data[i], data[i + 4]);
		}
	}

	if (data[0] > data[2])
	{
		SWAP(data[0], data[2]);
	}

	if (data[3] > data[5])
	{
		SWAP(data[3], data[5]);
	}

	if (data[4] > data[6])
	{
		SWAP(data[4], data[6]);
	}

	for (int i = 11; i < 20; i += 4) {
		if (data[i] > data[i + 2])
		{
			SWAP(data[i], data[i + 2]);
		}
		if (data[i + 1] > data[i + 3])
		{
			SWAP(data[i + 1], data[i + 3]);
		}
	}

	for (int i = 0; i < 7; i += 2) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
	}

	for (int i = 9; i < 23; i += 2) {
		if (data[i] > data[i + 1])
		{
			SWAP(data[i], data[i + 1]);
		}
	}

	for (int i = 0; i < 8; i++) {
		if (data[i] > data[i + 16])
		{
			SWAP(data[i], data[i + 16]);
		}
	}

	for (int i = 1; i < 9; i++) {
		if (data[i] > data[i + 8])
		{
			SWAP(data[i], data[i + 8]);
		}
	}

	for (int i = 5; i < 16; i += 8) {
		if (data[i] > data[i + 4])
		{
			SWAP(data[i], data[i + 4]);
		}
		if (data[i + 1] > data[i + 5])
		{
			SWAP(data[i + 1], data[i + 5]);
		}
		if (data[i + 2] > data[i + 6])
		{
			SWAP(data[i + 2], data[i + 6]);
		}
		if (data[i + 3] > data[i + 7])
		{
			SWAP(data[i + 3], data[i + 7]);
		}
	}

	if (data[11] > data[13])
	{
		SWAP(data[11], data[13]);
	}
	if (data[12] > data[14])
	{
		SWAP(data[12], data[14]);
	}
	if (data[12] > data[13])
	{
		SWAP(data[12], data[13]);
	}

	if (data[10] > data[12])
	{
		SWAP(data[10], data[12]);
	}
	if (data[8] > data[12])
	{
		SWAP(data[8], data[12]);
	}

	return data[12];
}


void median_filter_hls(pix_t in_pix[3], int n_line, pix_t out_pix[3]) {

	//pipeline a függvényre (unroll a benne lévő loop-okra)
#pragma HLS PIPELINE II=2

	//kimenetre reshape: párhuzamosan elérjük az elemeit
#pragma HLS ARRAY_RESHAPE variable=out_pix complete dim=1

	static pix_t win[4][1280 * 3] = { { 0 } }; 	//4 sor tárolása
#pragma HLS ARRAY_PARTITION variable=win factor=4 dim=1 //sorbuffer soronkénti elérése

												//komponens ablakok
	static pix_t in_R[25] = { 0 };
	static pix_t in_G[25] = { 0 };
	static pix_t in_B[25] = { 0 };

	//ablakok elemenkénti elérése
#pragma HLS ARRAY_PARTITION variable=in_R complete
#pragma HLS ARRAY_PARTITION variable=in_G complete
#pragma HLS ARRAY_PARTITION variable=in_B complete


	if (n_line) { //új sor esetén az oszlopszámlálót nullázzuk
		col = 0;
		row++; //sorszámlálót növeljük
		if (row == 4) row = 0;
	}

	int i, j;

	for (i = 0; i < 5; i++) {
		for (j = 1; j < 5; j++) {
			//0. 1. 2. 3. oszlop feltöltése
			//az oszlopokat a 5x5-as mátrixban balra shifteljük
			in_R[i * 5 + j - 1] = in_R[i * 5 + j];
			in_G[i * 5 + j - 1] = in_G[i * 5 + j];
			in_B[i * 5 + j - 1] = in_B[i * 5 + j];
		}

		if (i == 4) {
			//ott tartunk, ahová épp írjuk az új pixelt ->
			//nem win-t olvassuk, hanem közvetlen a pixelt használjuk
			in_R[i * 5 + 4] = in_pix[0];
			in_G[i * 5 + 4] = in_pix[1];
			in_B[i * 5 + 4] = in_pix[2];
		}
		else {
			//kiolvassuk a pixeltárolóból az értékeket
			in_R[i * 5 + 4] = win[i][col * 3 + 0];
			in_G[i * 5 + 4] = win[i][col * 3 + 1];
			in_B[i * 5 + 4] = win[i][col * 3 + 2];
		}
	}
	//buffer frissítése a bejövő értékekkel
	for (i = 0; i < 3; i++)
		win[row][col * 3 + i] = in_pix[i];
	//színkomponensenkénti szűrés
	out_pix[0] = median_hw(in_R);
	out_pix[1] = median_hw(in_G);
	out_pix[2] = median_hw(in_B);

	col++;
}
