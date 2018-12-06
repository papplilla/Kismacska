//void medianFilter(int imgHeight, int imgWidth, int imgWidthF, float *imgFloatSrc, float *imgFloatDst);
void medianFilter(int imgHeight, int imgWidth, int imgWidthF, int imgFOffsetH, int imgFOffsetW, float *imgFloatSrc, float *imgFloatDst);
//void medianFilterAVX(int imgHeight, int imgWidth, int imgWidthF, float *imgFloatSrc, float *imgFloatDst);
void medianFilterAVX(int imgHeight, int imgWidth, int imgWidthF, int imgFOffsetH, int imgFOffsetW, float *imgFloatSrc, float *imgFloatDst);