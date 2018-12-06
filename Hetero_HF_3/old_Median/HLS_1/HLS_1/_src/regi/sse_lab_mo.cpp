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