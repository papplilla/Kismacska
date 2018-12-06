#include "omp.h"

#include "emmintrin.h"
#include "nmmintrin.h"
#include "immintrin.h"


#include "defs.h"

void conv_filter(int imgHeight, int imgWidth, int imgWidthF,
				 short *filter, unsigned char *imgSrcExt, unsigned char *imgDst)
{

#if USE_OMP==1
	#pragma omp parallel for
#else
#endif
	for (int row=0; row<imgHeight; row++)
	{
		int wr_base = row*imgWidth*3;
		int rd_base = row*imgWidthF*3;
		for (int col=0; col<imgWidth; col++)
		{
			short fval[3] = {0,0,0};
			int rd_offset = 0;
			for (int fy=0; fy<FILTER_H; fy++)
			{
				for (int fx=0; fx<FILTER_W; fx++)
				{
					for (int rgba=0; rgba<3; rgba++)
					{
						int pixel_src = rd_base + rd_offset;
						fval[rgba] = fval[rgba] + *(filter+fy*FILTER_W+fx) * (short)(*(imgSrcExt + pixel_src + rgba));
					}
					rd_offset = rd_offset + 3;
				}
				rd_offset = rd_offset - 5*3 + imgWidthF*3;
				
			}

			for (int rgba=0; rgba<3; rgba++)
			{
				if (fval[rgba]>255) fval[rgba]=255;
				if (fval[rgba]<0)   fval[rgba]=0;
			}

			for (int rgba=0; rgba<3; rgba++)
			{
				*(imgDst +wr_base+rgba) = (unsigned char)(fval[rgba]);
			}
			wr_base = wr_base + 3;
			rd_base = rd_base + 3;
		}
		wr_base = wr_base + 4*3;
		rd_base = rd_base + 4*3;
	}
}
