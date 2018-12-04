#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
//#include "filter.cpp"

using namespace cv;
using namespace std;

#define PIXEL_COMPARE_AND_SWAP(x, y) if(arr[(x)] > arr[(y)]) { tmp = arr[(y)];arr[(y)] = arr[(x)];arr[(x)] = tmp;	}


void mergeSort(unsigned char * arr);
void mergeSort(unsigned char * arr)
{
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


// =========== TT ==============

void medfilter(uint8_t r, uint8_t g, uint8_t b, uint8_t* r_out, uint8_t* g_out, uint8_t* b_out, bool endline);

void medfilter(uint8_t r, uint8_t g, uint8_t b, uint8_t* r_out, uint8_t* g_out, uint8_t* b_out, bool endline) {
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

	sorbuf[0][sorbuf_x][sorbuf_y] = r;
	sorbuf[1][sorbuf_x][sorbuf_y] = g;
	sorbuf[2][sorbuf_x][sorbuf_y] = b;

	buffer_shift: // 5x5-ös buffer oszlopait balra shifteljük
	for (uint8_t color = 0; color < 3; color++){
	#pragma HLS UNROLL
		buffer_shift_y:
		for (uint8_t dy = 0; dy < 5; dy++){
		#pragma HLS UNROLL
			buffer_shift_x:
			for (uint8_t dx = 0; dx < 4; dx++){
			#pragma HLS PIPELINE II=1
			#pragma HLS UNROLL
				buf5[color][dx][dy] = buf5[color][dx+1][dy];
			}
		}
	}

	buffer_last_line: // új elemek a shiftelt bufferbe
	for (uint8_t color = 0; color < 3; color++){
	#pragma HLS UNROLL
		buffer_last_line_y:
		for (uint8_t dy = 0; dy < 5; dy++){
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

	mergeSort: // rendezés
	for (uint8_t color = 0; color < 3; color++){
	#pragma HLS UNROLL
		mergeSort(&buf5_ordered[color][0][0]);
	}

	if (endline) {
		sorbuf_x = 0;
		if (sorbuf_y == 4) {
			sorbuf_y = 0;
		}
		else sorbuf_y++;
	}
	else sorbuf_x++;

	// kimeneti pixel
	*r_out = buf5_ordered[0][2][2];
	*g_out = buf5_ordered[1][2][2];
	*b_out = buf5_ordered[2][2][2];
}


// =========== P ==============

#if 0

#include "ap_int.h"
#include "ap_fixed.h"

#include "types.h"

#define SWAP(a,b) temp=a;a=b;b=temp;
#define N 25

static row_t row = 0; 			//0,1,2,3,4
static col_t col = 0; 			//0,1,2,....1280-1

#define PIXEL_COMPARE_AND_SWAP(x, y) if(arr[(x)] > arr[(y)]) { tmp = arr[(y)];arr[(y)] = arr[(x)];arr[(x)] = tmp;	}

#define MEDIAN 12

//1. mósszer
pix_t mergeSort(pix_t arr[25])
//2. mósszer
//pix_t mergeSort(pix_t arrIn[25])
{
	pix_t tmp;
	//2. módszer
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


	return arr[MEDIAN];
}

void median_filter_hls(pix_t in_pix[3], int n_line, pix_t out_pix[3]) {

	//pipeline a függvényre (unroll a benne lévõ loop-okra)
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
	//buffer frissítése a bejövõ értékekkel
	for (i = 0; i < 3; i++)
		win[row][col * 3 + i] = in_pix[i];
	//színkomponensenkénti szûrés
	out_pix[0] = mergeSort(in_R);
	out_pix[1] = mergeSort(in_G);
	out_pix[2] = mergeSort(in_B);

	col++;
}


#endif



int main( int argc, char** argv )
{

    Mat image;
    image = imread("c:\\heterogen_hls\\input.jpg", CV_LOAD_IMAGE_COLOR);   // Read the file

    if(! image.data )
    {
        cout <<  "Could not open or find the image" << std::endl ;
        return -1;
    }

	uint8_t r_in, g_in, b_in;
	uint8_t r_out, g_out, b_out;
	bool endline = false;
    Mat outimg(image.size(),CV_8UC3);

	for (int y = 0; y < image.rows; y++ ){
		   for (int x = 0; x < image.cols; x++ ){
    		if (x == (image.cols - 1)){
    			endline = true;
    		}
    		else endline = false;

    		r_in = image.at<Vec3b>(y,x)[0];
    		g_in = image.at<Vec3b>(y,x)[1];
    		b_in = image.at<Vec3b>(y,x)[2];

    		medfilter(r_in, g_in, b_in, &r_out, &g_out, &b_out,endline);

    		outimg.at<Vec3b>(y,x)[0] = r_out;
    		outimg.at<Vec3b>(y,x)[1] = g_out;
    		outimg.at<Vec3b>(y,x)[2] = b_out;
    	}
    }


    namedWindow( "Display window", WINDOW_AUTOSIZE );// Create a window for display.
    imshow( "Display window", outimg );                   // Show our image inside it.

    imwrite( "c:\\heterogen_hls\\Out_Image.jpg", outimg );

    waitKey(0);                                          // Wait for a keystroke in the window
    return 0;
}
