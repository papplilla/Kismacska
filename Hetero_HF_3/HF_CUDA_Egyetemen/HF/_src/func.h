double time_measure(int mode);

void conv_filter(int imgHeight, int imgWidth, int imgWidthF,
	             short *filter, unsigned char *imgSrcExt, unsigned char *imgDst);

void cudaMain(int imgHeight, int imgWidth, int imgHeightF, int imgWidthF,
              unsigned char *imgSrcExt, unsigned char *imgDst);

void memalloc_host(int imgWidthF, int imgHeightF, unsigned char **input, 
	int imgWidth, int imgHeight, unsigned char **output);

void memfree_host(unsigned char **input, unsigned char **output);