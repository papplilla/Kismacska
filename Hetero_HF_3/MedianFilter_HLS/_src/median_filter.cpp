#include <stdint.h>

void cmpswap(int a, int b, unsigned char * tomb) {
#pragma HLS INLINE
	unsigned char buf;
	if (tomb[a] > tomb[b]) {
		buf = tomb[b];
		tomb[b] = tomb[a];
		tomb[a] = buf;
	}
}

void oddeven(unsigned char * tomb) {
#pragma HLS INLINE
#pragma HLS PIPELINE II=1
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
	cmpswap(2, 6, tomb);
	cmpswap(2, 4, tomb);
	cmpswap(1, 5, tomb);
	cmpswap(3, 7, tomb);
	cmpswap(3, 5, tomb);
	cmpswap(1, 2, tomb);
	cmpswap(3, 4, tomb);
	cmpswap(5, 6, tomb);
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
	cmpswap(10, 14, tomb);
	cmpswap(10, 12, tomb);
	cmpswap(9, 13, tomb);
	cmpswap(11, 15, tomb);
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


#define PIXEL_COMPARE_AND_SWAP(x, y) if(arr[(x)] > arr[(y)]) { tmp = arr[(y)];arr[(y)] = arr[(x)];arr[(x)] = tmp;	}
void mergeSort(unsigned char * arr);
void mergeSort(unsigned char * arr)
{
	#pragma HLS INLINE
	#pragma HLS PIPELINE II=1	
	unsigned char tmp;
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

typedef enum {RED, GREEN, BLUE}Colors;
void median_filter_hls(pix_t in_pix[3], int n_line, pix_t out_pix[3])
{
//TT
//void medfilter(uint8_t r, uint8_t g, uint8_t b, uint8_t* r_out, uint8_t* g_out, uint8_t* b_out, bool endline) {
#pragma HLS PIPELINE II=1

	static uint8_t sorbuf[3][1280][5];
	#pragma HLS ARRAY_PARTITION variable=sorbuf complete dim=3
	#pragma HLS ARRAY_PARTITION variable=sorbuf complete dim=1

	static uint8_t buf5 [3][5][5];
	#pragma HLS ARRAY_PARTITION variable=buf5 complete dim=0

	static uint8_t buf5_ordered [3][5][5];
	#pragma HLS ARRAY_PARTITION variable=buf5_ordered complete dim=0
	static int sorbuf_x = 0;
	static uint8_t sorbuf_y = 0;

	// Új sor
	if (n_line)
	{
		sorbuf_x = 0;
		if (sorbuf_y == 4) 
			sorbuf_y = 0;
		else
			sorbuf_y++;
	}
	else
		sorbuf_x++;
	
	
	sorbuf[RED][sorbuf_x][sorbuf_y] = in_pix[RED];
	sorbuf[GREEN][sorbuf_x][sorbuf_y] = in_pix[GREEN];
	sorbuf[BLUE][sorbuf_x][sorbuf_y] = in_pix[BLUE];

	buffer_shift: 
	for (uint8_t color = 0; color < 3; color++)
	{
		// A szûrõablaka tartalmának balra shiftelése
	#pragma HLS UNROLL
			buffer_shift_y:
			for (uint8_t dy = 0; dy < 5; dy++)
			{
			#pragma HLS UNROLL
				buffer_shift_x:
				for (uint8_t dx = 1; dx < 5; dx++)
				{
				#pragma HLS PIPELINE II=1
				#pragma HLS UNROLL
					buf5[color][dx-1][dy] = buf5[color][dx][dy];
				}
			}
	}
 
	buffer_last_line: 
	for (uint8_t color = 0; color < 3; color++)
	{
	// Új elem behelyezése
	#pragma HLS UNROLL
		buffer_last_line_y:
		for (uint8_t dy = 0; dy < 5; dy++)
		{
		#pragma HLS UNROLL
			buf5[color][4][dy] = sorbuf[color][sorbuf_x][dy];
		}
	}

	buffer_ordered_copy: // a buffer mentése
	for (uint8_t color = 0; color < 3; color++){
	#pragma HLS UNROLL
		buffer_ordered_copy_y:
		for (uint8_t dy = 0; dy < 5; dy++){
		#pragma HLS UNROLL
			buffer_ordered_copy_x:
			for (uint8_t dx = 0; dx < 5; dx++){
			#pragma HLS UNROLL
				buf5_ordered[color][dx][dy] = buf5[color][dx][dy];
			}
		}
	}

	oddeven: // rendezés
	for (uint8_t color = 0; color < 3; color++){
	#pragma HLS UNROLL
		oddeven(&buf5_ordered[color][0][0]);
	}

	/*if (endline) {
		sorbuf_x = 0;
		if (sorbuf_y == 4) {
			sorbuf_y = 0;
		}
		else sorbuf_y++;
	}
	else sorbuf_x++;
*/
	// kimeneti pixel
	out_pix[RED] = buf5_ordered[RED][2][2];
	out_pix[GREEN] = buf5_ordered[GREEN][2][2];
	out_pix[BLUE] = buf5_ordered[BLUE][2][2];
}


