#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"
#include "immintrin.h"


#include "defs.h"



void conv_filter_avx(int imgHeight, int imgWidth, int imgWidthF,
				 short *filter, unsigned char *imgSrcExt, unsigned char *imgDst)
{
	// Generate the vector-coefficients
	__m256i filter_laplace[25];
	for (int i = 0; i < 25; i++)
	{
		filter_laplace[i] = _mm256_set1_epi16(filter[i]);
	}


#if USE_OMP==1
	#pragma omp parallel for
#else
#endif
	for (int row=0; row<imgHeight; row++)
	{
		int wr_base = row*imgWidth*3;
		int rd_base = row*imgWidthF*3;
		// step through all components in a line
		for (int col=0; col<(imgWidth*3); col=col+16)
		{
			__m256i fval;
			fval = _mm256_set1_epi16(0);

			int rd_offset = 0;
			for (int fy=0; fy<FILTER_H; fy++)
			{
#if LOOP_UNROLL==0
				for (int fx=0; fx<FILTER_W; fx++)
#endif
				{
					int pixel_src = rd_base + rd_offset;
					__m128i load_data;
					__m256i conv_res, mul_res;

#if LOOP_UNROLL==0
					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src));
					conv_res = _mm256_cvtepu8_epi16(load_data);
					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + fx]);
					fval = _mm256_add_epi16(fval, mul_res);
					rd_offset = rd_offset + 3;
#else
					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 0));
					conv_res = _mm256_cvtepu8_epi16(load_data);
					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 0]);
					fval = _mm256_add_epi16(fval, mul_res);

					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 3));
					conv_res = _mm256_cvtepu8_epi16(load_data);
					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 1]);
					fval = _mm256_add_epi16(fval, mul_res);

					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 6));
					conv_res = _mm256_cvtepu8_epi16(load_data);
					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 2]);
					fval = _mm256_add_epi16(fval, mul_res);

					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 9));
					conv_res = _mm256_cvtepu8_epi16(load_data);
					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 3]);
					fval = _mm256_add_epi16(fval, mul_res);

					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 12));
					conv_res = _mm256_cvtepu8_epi16(load_data);
					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 4]);
					fval = _mm256_add_epi16(fval, mul_res);
#endif
				}
#if LOOP_UNROLL==0
				rd_offset = rd_offset - 5*3 + imgWidthF*3;
#else
				rd_offset = rd_offset + imgWidthF * 3;
#endif
			}

			__m256i sat_val;
			sat_val = _mm256_set1_epi16(255);
			fval = _mm256_min_epi16(fval, sat_val);
			sat_val = _mm256_set1_epi16(0);
			fval = _mm256_max_epi16(fval, sat_val);

			__m256i *res_vec_ptr;
			res_vec_ptr = &fval;
			short *res_short_ptr;
			res_short_ptr = (short*)(res_vec_ptr);

			for (int i = 0; i < 16; i++)
			{
				*(imgDst + wr_base + i) = *(res_short_ptr + i);
			}

			wr_base = wr_base + 16;
			rd_base = rd_base + 16;
		}
	}
}

