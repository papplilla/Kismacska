; Listing generated by Microsoft (R) Optimizing Compiler Version 19.14.26430.0 

	TITLE	D:\D_Strabi\D Dokumentumai\BME\Heterog�n sz�m�t�si rendszerek\HF\Kismacska\Hetero_HW_2\_src\median_filter_avx.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMTD
INCLUDELIB OLDNAMES

PUBLIC	?conv_filter_avx@@YAXHHHPAFPAE1@Z		; conv_filter_avx
PUBLIC	__ymm@0000000000000000000000000000000000000000000000000000000000000000
PUBLIC	__ymm@00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff
EXTRN	@_RTC_CheckStackVars@8:PROC
EXTRN	@__security_check_cookie@4:PROC
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
EXTRN	__vcomp_for_static_end:PROC
EXTRN	__vcomp_for_static_simple_init:PROC
EXTRN	__vcomp_fork:PROC
EXTRN	__You_must_link_with_Microsoft_OpenMP_library:DWORD
EXTRN	___security_cookie:DWORD
;	COMDAT __ymm@00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff
CONST	SEGMENT
__ymm@00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff DB 0ffH
	DB	00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H, 0ffH
	DB	00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H, 0ffH
	DB	00H, 0ffH, 00H, 0ffH, 00H, 0ffH, 00H
CONST	ENDS
;	COMDAT __ymm@0000000000000000000000000000000000000000000000000000000000000000
CONST	SEGMENT
__ymm@0000000000000000000000000000000000000000000000000000000000000000 DB 00H
	DB	00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H
	DB	00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H, 00H
	DB	00H, 00H, 00H, 00H, 00H
CONST	ENDS
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hw_2\_src\median_filter_avx.cpp
;	COMDAT ?conv_filter_avx$omp$1@@YAXHHHPAFPAE1@Z
_TEXT	SEGMENT
$T1 = -2648						; size = 4
$T2 = -2636						; size = 4
$T3 = -2624						; size = 32
$T4 = -2560						; size = 32
$T5 = -2496						; size = 32
$T6 = -2432						; size = 32
$T7 = -2368						; size = 32
$T8 = -2304						; size = 32
$T9 = -2240						; size = 32
$T10 = -2176						; size = 16
$T11 = -2144						; size = 32
$T12 = -2080						; size = 32
$T13 = -2016						; size = 32
$T14 = -1952						; size = 16
$T15 = -1920						; size = 32
$T16 = -1856						; size = 32
$T17 = -1792						; size = 32
$T18 = -1728						; size = 16
$T19 = -1696						; size = 32
$T20 = -1632						; size = 32
$T21 = -1568						; size = 32
$T22 = -1504						; size = 16
$T23 = -1472						; size = 32
$T24 = -1408						; size = 32
$T25 = -1344						; size = 32
$T26 = -1280						; size = 16
$T27 = -1248						; size = 32
_$S3$28 = -424						; size = 4
_$S2$29 = -412						; size = 4
_$S1$30 = -400						; size = 4
_i$31 = -388						; size = 4
_res_short_ptr$32 = -376				; size = 4
_res_vec_ptr$33 = -364					; size = 4
_sat_val$34 = -352					; size = 32
_mul_res$35 = -288					; size = 32
_conv_res$36 = -224					; size = 32
_load_data$37 = -160					; size = 16
_pixel_src$38 = -132					; size = 4
_fy$39 = -120						; size = 4
_rd_offset$40 = -108					; size = 4
_fval$41 = -96						; size = 32
_col$42 = -44						; size = 4
_rd_base$43 = -32					; size = 4
_wr_base$44 = -20					; size = 4
_row$45 = -8						; size = 4
_filter_laplace$ = 8					; size = 4
_imgHeight$ = 12					; size = 4
_imgWidth$ = 16						; size = 4
_imgWidthF$ = 20					; size = 4
_imgSrcExt$ = 24					; size = 4
_imgDst$ = 28						; size = 4
?conv_filter_avx$omp$1@@YAXHHHPAFPAE1@Z PROC		; conv_filter_avx$omp$1, COMDAT

; 24   : 	#pragma omp parallel for

	push	ebx
	mov	ebx, esp
	sub	esp, 8
	and	esp, -32				; ffffffe0H
	add	esp, 4
	push	ebp
	mov	ebp, DWORD PTR [ebx+4]
	mov	DWORD PTR [esp+4], ebp
	mov	ebp, esp
	sub	esp, 2680				; 00000a78H
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-2680]
	mov	ecx, 670				; 0000029eH
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 25   : #else
; 26   : #endif
; 27   : 	for (int row=0; row<imgHeight; row++)

	mov	DWORD PTR _$S1$30[ebp], 0
	mov	DWORD PTR _$S3$28[ebp], 1
	mov	eax, DWORD PTR _imgHeight$[ebx]
	mov	DWORD PTR _$S2$29[ebp], eax
	mov	eax, DWORD PTR _$S1$30[ebp]
	cmp	eax, DWORD PTR _$S2$29[ebp]
	jge	$LN1@conv_filte
	mov	ecx, DWORD PTR _$S2$29[ebp]
	sub	ecx, 1
	mov	DWORD PTR _$S2$29[ebp], ecx
	lea	eax, DWORD PTR $T1[ebp]
	push	eax
	lea	ecx, DWORD PTR $T2[ebp]
	push	ecx
	push	1
	mov	edx, DWORD PTR _$S3$28[ebp]
	push	edx
	mov	eax, DWORD PTR _$S2$29[ebp]
	push	eax
	mov	ecx, DWORD PTR _$S1$30[ebp]
	push	ecx
	call	__vcomp_for_static_simple_init
	add	esp, 24					; 00000018H
	mov	eax, DWORD PTR $T2[ebp]
	mov	DWORD PTR _row$45[ebp], eax
	jmp	SHORT $LN2@conv_filte
$LN5@conv_filte:
	mov	ecx, DWORD PTR _row$45[ebp]
	add	ecx, DWORD PTR _$S3$28[ebp]
	mov	DWORD PTR _row$45[ebp], ecx
$LN2@conv_filte:
	mov	edx, DWORD PTR _row$45[ebp]
	cmp	edx, DWORD PTR $T1[ebp]
	jg	$LN6@conv_filte

; 28   : 	{
; 29   : 		int wr_base = row*imgWidth*3;

	mov	eax, DWORD PTR _row$45[ebp]
	imul	eax, DWORD PTR _imgWidth$[ebx]
	imul	ecx, eax, 3
	mov	DWORD PTR _wr_base$44[ebp], ecx

; 30   : 		int rd_base = row*imgWidthF*3;

	mov	eax, DWORD PTR _row$45[ebp]
	imul	eax, DWORD PTR _imgWidthF$[ebx]
	imul	ecx, eax, 3
	mov	DWORD PTR _rd_base$43[ebp], ecx

; 31   : 		// step through all components in a line
; 32   : 		for (int col=0; col<(imgWidth*3); col=col+16)

	mov	DWORD PTR _col$42[ebp], 0
	jmp	SHORT $LN9@conv_filte
$LN7@conv_filte:
	mov	eax, DWORD PTR _col$42[ebp]
	add	eax, 16					; 00000010H
	mov	DWORD PTR _col$42[ebp], eax
$LN9@conv_filte:
	imul	eax, DWORD PTR _imgWidth$[ebx], 3
	cmp	DWORD PTR _col$42[ebp], eax
	jge	$LN8@conv_filte

; 33   : 		{
; 34   : 			__m256i fval;
; 35   : 			fval = _mm256_set1_epi16(0);

	vmovdqu	ymm0, YMMWORD PTR __ymm@0000000000000000000000000000000000000000000000000000000000000000
	vmovdqu	YMMWORD PTR $T27[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T27[ebp]
	vmovdqu	YMMWORD PTR _fval$41[ebp], ymm0

; 36   : 
; 37   : 			int rd_offset = 0;

	mov	DWORD PTR _rd_offset$40[ebp], 0

; 38   : 			for (int fy=0; fy<FILTER_H; fy++)

	mov	DWORD PTR _fy$39[ebp], 0
	jmp	SHORT $LN12@conv_filte
$LN10@conv_filte:
	mov	eax, DWORD PTR _fy$39[ebp]
	add	eax, 1
	mov	DWORD PTR _fy$39[ebp], eax
$LN12@conv_filte:
	cmp	DWORD PTR _fy$39[ebp], 5
	jge	$LN11@conv_filte

; 39   : 			{
; 40   : #if LOOP_UNROLL==0
; 41   : 				for (int fx=0; fx<FILTER_W; fx++)
; 42   : #endif
; 43   : 				{
; 44   : 					int pixel_src = rd_base + rd_offset;

	mov	eax, DWORD PTR _rd_base$43[ebp]
	add	eax, DWORD PTR _rd_offset$40[ebp]
	mov	DWORD PTR _pixel_src$38[ebp], eax

; 45   : 					__m128i load_data;
; 46   : 					__m256i conv_res, mul_res;
; 47   : 
; 48   : #if LOOP_UNROLL==0
; 49   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src));
; 50   : 					conv_res = _mm256_cvtepu8_epi16(load_data);
; 51   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + fx]);
; 52   : 					fval = _mm256_add_epi16(fval, mul_res);
; 53   : 					rd_offset = rd_offset + 3;
; 54   : #else
; 55   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 0));

	mov	eax, DWORD PTR _imgSrcExt$[ebx]
	add	eax, DWORD PTR _pixel_src$38[ebp]
	lddqu	xmm0, XMMWORD PTR [eax]
	movaps	XMMWORD PTR $T26[ebp], xmm0
	movaps	xmm0, XMMWORD PTR $T26[ebp]
	movaps	XMMWORD PTR _load_data$37[ebp], xmm0

; 56   : 					conv_res = _mm256_cvtepu8_epi16(load_data);

	vpmovzxbw ymm0, XMMWORD PTR _load_data$37[ebp]
	vmovdqu	YMMWORD PTR $T25[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T25[ebp]
	vmovdqu	YMMWORD PTR _conv_res$36[ebp], ymm0

; 57   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 0]);

	imul	eax, DWORD PTR _fy$39[ebp], 5
	shl	eax, 5
	add	eax, DWORD PTR _filter_laplace$[ebx]
	vmovdqu	ymm0, YMMWORD PTR _conv_res$36[ebp]
	vpmullw	ymm0, ymm0, YMMWORD PTR [eax]
	vmovdqu	YMMWORD PTR $T24[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T24[ebp]
	vmovdqu	YMMWORD PTR _mul_res$35[ebp], ymm0

; 58   : 					fval = _mm256_add_epi16(fval, mul_res);

	vmovdqu	ymm0, YMMWORD PTR _fval$41[ebp]
	vpaddw	ymm0, ymm0, YMMWORD PTR _mul_res$35[ebp]
	vmovdqu	YMMWORD PTR $T23[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T23[ebp]
	vmovdqu	YMMWORD PTR _fval$41[ebp], ymm0

; 59   : 
; 60   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 3));

	mov	eax, DWORD PTR _pixel_src$38[ebp]
	mov	ecx, DWORD PTR _imgSrcExt$[ebx]
	lddqu	xmm0, XMMWORD PTR [ecx+eax+3]
	movaps	XMMWORD PTR $T22[ebp], xmm0
	movaps	xmm0, XMMWORD PTR $T22[ebp]
	movaps	XMMWORD PTR _load_data$37[ebp], xmm0

; 61   : 					conv_res = _mm256_cvtepu8_epi16(load_data);

	vpmovzxbw ymm0, XMMWORD PTR _load_data$37[ebp]
	vmovdqu	YMMWORD PTR $T21[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T21[ebp]
	vmovdqu	YMMWORD PTR _conv_res$36[ebp], ymm0

; 62   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 1]);

	imul	eax, DWORD PTR _fy$39[ebp], 5
	add	eax, 1
	shl	eax, 5
	add	eax, DWORD PTR _filter_laplace$[ebx]
	vmovdqu	ymm0, YMMWORD PTR _conv_res$36[ebp]
	vpmullw	ymm0, ymm0, YMMWORD PTR [eax]
	vmovdqu	YMMWORD PTR $T20[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T20[ebp]
	vmovdqu	YMMWORD PTR _mul_res$35[ebp], ymm0

; 63   : 					fval = _mm256_add_epi16(fval, mul_res);

	vmovdqu	ymm0, YMMWORD PTR _fval$41[ebp]
	vpaddw	ymm0, ymm0, YMMWORD PTR _mul_res$35[ebp]
	vmovdqu	YMMWORD PTR $T19[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T19[ebp]
	vmovdqu	YMMWORD PTR _fval$41[ebp], ymm0

; 64   : 
; 65   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 6));

	mov	eax, DWORD PTR _pixel_src$38[ebp]
	mov	ecx, DWORD PTR _imgSrcExt$[ebx]
	lddqu	xmm0, XMMWORD PTR [ecx+eax+6]
	movaps	XMMWORD PTR $T18[ebp], xmm0
	movaps	xmm0, XMMWORD PTR $T18[ebp]
	movaps	XMMWORD PTR _load_data$37[ebp], xmm0

; 66   : 					conv_res = _mm256_cvtepu8_epi16(load_data);

	vpmovzxbw ymm0, XMMWORD PTR _load_data$37[ebp]
	vmovdqu	YMMWORD PTR $T17[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T17[ebp]
	vmovdqu	YMMWORD PTR _conv_res$36[ebp], ymm0

; 67   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 2]);

	imul	eax, DWORD PTR _fy$39[ebp], 5
	add	eax, 2
	shl	eax, 5
	add	eax, DWORD PTR _filter_laplace$[ebx]
	vmovdqu	ymm0, YMMWORD PTR _conv_res$36[ebp]
	vpmullw	ymm0, ymm0, YMMWORD PTR [eax]
	vmovdqu	YMMWORD PTR $T16[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T16[ebp]
	vmovdqu	YMMWORD PTR _mul_res$35[ebp], ymm0

; 68   : 					fval = _mm256_add_epi16(fval, mul_res);

	vmovdqu	ymm0, YMMWORD PTR _fval$41[ebp]
	vpaddw	ymm0, ymm0, YMMWORD PTR _mul_res$35[ebp]
	vmovdqu	YMMWORD PTR $T15[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T15[ebp]
	vmovdqu	YMMWORD PTR _fval$41[ebp], ymm0

; 69   : 
; 70   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 9));

	mov	eax, DWORD PTR _pixel_src$38[ebp]
	mov	ecx, DWORD PTR _imgSrcExt$[ebx]
	lddqu	xmm0, XMMWORD PTR [ecx+eax+9]
	movaps	XMMWORD PTR $T14[ebp], xmm0
	movaps	xmm0, XMMWORD PTR $T14[ebp]
	movaps	XMMWORD PTR _load_data$37[ebp], xmm0

; 71   : 					conv_res = _mm256_cvtepu8_epi16(load_data);

	vpmovzxbw ymm0, XMMWORD PTR _load_data$37[ebp]
	vmovdqu	YMMWORD PTR $T13[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T13[ebp]
	vmovdqu	YMMWORD PTR _conv_res$36[ebp], ymm0

; 72   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 3]);

	imul	eax, DWORD PTR _fy$39[ebp], 5
	add	eax, 3
	shl	eax, 5
	add	eax, DWORD PTR _filter_laplace$[ebx]
	vmovdqu	ymm0, YMMWORD PTR _conv_res$36[ebp]
	vpmullw	ymm0, ymm0, YMMWORD PTR [eax]
	vmovdqu	YMMWORD PTR $T12[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T12[ebp]
	vmovdqu	YMMWORD PTR _mul_res$35[ebp], ymm0

; 73   : 					fval = _mm256_add_epi16(fval, mul_res);

	vmovdqu	ymm0, YMMWORD PTR _fval$41[ebp]
	vpaddw	ymm0, ymm0, YMMWORD PTR _mul_res$35[ebp]
	vmovdqu	YMMWORD PTR $T11[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T11[ebp]
	vmovdqu	YMMWORD PTR _fval$41[ebp], ymm0

; 74   : 
; 75   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 12));

	mov	eax, DWORD PTR _pixel_src$38[ebp]
	mov	ecx, DWORD PTR _imgSrcExt$[ebx]
	lddqu	xmm0, XMMWORD PTR [ecx+eax+12]
	movaps	XMMWORD PTR $T10[ebp], xmm0
	movaps	xmm0, XMMWORD PTR $T10[ebp]
	movaps	XMMWORD PTR _load_data$37[ebp], xmm0

; 76   : 					conv_res = _mm256_cvtepu8_epi16(load_data);

	vpmovzxbw ymm0, XMMWORD PTR _load_data$37[ebp]
	vmovdqu	YMMWORD PTR $T9[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T9[ebp]
	vmovdqu	YMMWORD PTR _conv_res$36[ebp], ymm0

; 77   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 4]);

	imul	eax, DWORD PTR _fy$39[ebp], 5
	add	eax, 4
	shl	eax, 5
	add	eax, DWORD PTR _filter_laplace$[ebx]
	vmovdqu	ymm0, YMMWORD PTR _conv_res$36[ebp]
	vpmullw	ymm0, ymm0, YMMWORD PTR [eax]
	vmovdqu	YMMWORD PTR $T8[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T8[ebp]
	vmovdqu	YMMWORD PTR _mul_res$35[ebp], ymm0

; 78   : 					fval = _mm256_add_epi16(fval, mul_res);

	vmovdqu	ymm0, YMMWORD PTR _fval$41[ebp]
	vpaddw	ymm0, ymm0, YMMWORD PTR _mul_res$35[ebp]
	vmovdqu	YMMWORD PTR $T7[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T7[ebp]
	vmovdqu	YMMWORD PTR _fval$41[ebp], ymm0

; 79   : #endif
; 80   : 				}
; 81   : #if LOOP_UNROLL==0
; 82   : 				rd_offset = rd_offset - 5*3 + imgWidthF*3;
; 83   : #else
; 84   : 				rd_offset = rd_offset + imgWidthF * 3;

	imul	eax, DWORD PTR _imgWidthF$[ebx], 3
	add	eax, DWORD PTR _rd_offset$40[ebp]
	mov	DWORD PTR _rd_offset$40[ebp], eax

; 85   : #endif
; 86   : 			}

	jmp	$LN10@conv_filte
$LN11@conv_filte:

; 87   : 
; 88   : 			__m256i sat_val;
; 89   : 			sat_val = _mm256_set1_epi16(255);

	vmovdqu	ymm0, YMMWORD PTR __ymm@00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff00ff
	vmovdqu	YMMWORD PTR $T6[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T6[ebp]
	vmovdqu	YMMWORD PTR _sat_val$34[ebp], ymm0

; 90   : 			fval = _mm256_min_epi16(fval, sat_val);

	vmovdqu	ymm0, YMMWORD PTR _fval$41[ebp]
	vpminsw	ymm0, ymm0, YMMWORD PTR _sat_val$34[ebp]
	vmovdqu	YMMWORD PTR $T5[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T5[ebp]
	vmovdqu	YMMWORD PTR _fval$41[ebp], ymm0

; 91   : 			sat_val = _mm256_set1_epi16(0);

	vmovdqu	ymm0, YMMWORD PTR __ymm@0000000000000000000000000000000000000000000000000000000000000000
	vmovdqu	YMMWORD PTR $T4[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T4[ebp]
	vmovdqu	YMMWORD PTR _sat_val$34[ebp], ymm0

; 92   : 			fval = _mm256_max_epi16(fval, sat_val);

	vmovdqu	ymm0, YMMWORD PTR _fval$41[ebp]
	vpmaxsw	ymm0, ymm0, YMMWORD PTR _sat_val$34[ebp]
	vmovdqu	YMMWORD PTR $T3[ebp], ymm0
	vmovdqu	ymm0, YMMWORD PTR $T3[ebp]
	vmovdqu	YMMWORD PTR _fval$41[ebp], ymm0

; 93   : 
; 94   : 			__m256i *res_vec_ptr;
; 95   : 			res_vec_ptr = &fval;

	lea	eax, DWORD PTR _fval$41[ebp]
	mov	DWORD PTR _res_vec_ptr$33[ebp], eax

; 96   : 			short *res_short_ptr;
; 97   : 			res_short_ptr = (short*)(res_vec_ptr);

	mov	eax, DWORD PTR _res_vec_ptr$33[ebp]
	mov	DWORD PTR _res_short_ptr$32[ebp], eax

; 98   : 
; 99   : 			for (int i = 0; i < 16; i++)

	mov	DWORD PTR _i$31[ebp], 0
	jmp	SHORT $LN15@conv_filte
$LN13@conv_filte:
	mov	eax, DWORD PTR _i$31[ebp]
	add	eax, 1
	mov	DWORD PTR _i$31[ebp], eax
$LN15@conv_filte:
	cmp	DWORD PTR _i$31[ebp], 16		; 00000010H
	jge	SHORT $LN14@conv_filte

; 100  : 			{
; 101  : 				*(imgDst + wr_base + i) = *(res_short_ptr + i);

	mov	eax, DWORD PTR _imgDst$[ebx]
	add	eax, DWORD PTR _wr_base$44[ebp]
	mov	ecx, DWORD PTR _i$31[ebp]
	mov	edx, DWORD PTR _i$31[ebp]
	mov	esi, DWORD PTR _res_short_ptr$32[ebp]
	mov	dl, BYTE PTR [esi+edx*2]
	mov	BYTE PTR [eax+ecx], dl

; 102  : 			}

	jmp	SHORT $LN13@conv_filte
$LN14@conv_filte:

; 103  : 
; 104  : 			wr_base = wr_base + 16;

	mov	eax, DWORD PTR _wr_base$44[ebp]
	add	eax, 16					; 00000010H
	mov	DWORD PTR _wr_base$44[ebp], eax

; 105  : 			rd_base = rd_base + 16;

	mov	eax, DWORD PTR _rd_base$43[ebp]
	add	eax, 16					; 00000010H
	mov	DWORD PTR _rd_base$43[ebp], eax

; 106  : 		}

	jmp	$LN7@conv_filte
$LN8@conv_filte:

; 25   : #else
; 26   : #endif
; 27   : 	for (int row=0; row<imgHeight; row++)

	jmp	$LN5@conv_filte
$LN6@conv_filte:
	call	__vcomp_for_static_end
$LN1@conv_filte:

; 107  : 	}

	push	edx
	mov	ecx, ebp
	push	eax
	lea	edx, DWORD PTR $LN5@conv_filte
	call	@_RTC_CheckStackVars@8
	pop	eax
	pop	edx
	pop	edi
	pop	esi
	mov	esp, ebp
	pop	ebp
	mov	esp, ebx
	pop	ebx
	ret	0
$LN5@conv_filte:
	DD	1
	DD	$LN4@conv_filte
$LN4@conv_filte:
	DD	-96					; ffffffa0H
	DD	32					; 00000020H
	DD	$LN3@conv_filte
$LN3@conv_filte:
	DB	102					; 00000066H
	DB	118					; 00000076H
	DB	97					; 00000061H
	DB	108					; 0000006cH
	DB	0
?conv_filter_avx$omp$1@@YAXHHHPAFPAE1@Z ENDP		; conv_filter_avx$omp$1
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hw_2\_src\median_filter_avx.cpp
;	COMDAT ?conv_filter_avx@@YAXHHHPAFPAE1@Z
_TEXT	SEGMENT
$T1 = -1280						; size = 32
_i$2 = -844						; size = 4
_filter_laplace$ = -832					; size = 800
__$ArrayPad$ = -4					; size = 4
_imgHeight$ = 8						; size = 4
_imgWidth$ = 12						; size = 4
_imgWidthF$ = 16					; size = 4
_filter$ = 20						; size = 4
_imgSrcExt$ = 24					; size = 4
_imgDst$ = 28						; size = 4
?conv_filter_avx@@YAXHHHPAFPAE1@Z PROC			; conv_filter_avx, COMDAT

; 14   : {

	push	ebx
	mov	ebx, esp
	sub	esp, 8
	and	esp, -32				; ffffffe0H
	add	esp, 4
	push	ebp
	mov	ebp, DWORD PTR [ebx+4]
	mov	DWORD PTR [esp+4], ebp
	mov	ebp, esp
	sub	esp, 1304				; 00000518H
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-1304]
	mov	ecx, 326				; 00000146H
	mov	eax, -858993460				; ccccccccH
	rep stosd
	mov	eax, DWORD PTR ___security_cookie
	xor	eax, ebp
	mov	DWORD PTR __$ArrayPad$[ebp], eax

; 15   : 	// Generate the vector-coefficients
; 16   : 	__m256i filter_laplace[25];
; 17   : 	for (int i = 0; i < 25; i++)

	mov	DWORD PTR _i$2[ebp], 0
	jmp	SHORT $LN4@conv_filte
$LN2@conv_filte:
	mov	eax, DWORD PTR _i$2[ebp]
	add	eax, 1
	mov	DWORD PTR _i$2[ebp], eax
$LN4@conv_filte:
	cmp	DWORD PTR _i$2[ebp], 25			; 00000019H
	jge	SHORT $LN3@conv_filte

; 18   : 	{
; 19   : 		filter_laplace[i] = _mm256_set1_epi16(filter[i]);

	mov	eax, DWORD PTR _i$2[ebp]
	mov	ecx, DWORD PTR _filter$[ebx]
	movsx	edx, WORD PTR [ecx+eax*2]
	vmovd	xmm0, edx
	vpunpcklwd xmm0, xmm0, xmm0
	vpshufd	xmm0, xmm0, 0
	vinsertf128 ymm0, ymm0, xmm0, 1
	vmovdqu	YMMWORD PTR $T1[ebp], ymm0
	mov	eax, DWORD PTR _i$2[ebp]
	shl	eax, 5
	vmovdqu	ymm0, YMMWORD PTR $T1[ebp]
	vmovdqu	YMMWORD PTR _filter_laplace$[ebp+eax], ymm0

; 20   : 	}

	jmp	SHORT $LN2@conv_filte
$LN3@conv_filte:

; 21   : 
; 22   : 
; 23   : #if USE_OMP==1
; 24   : 	#pragma omp parallel for

	mov	eax, DWORD PTR _imgDst$[ebx]
	push	eax
	mov	ecx, DWORD PTR _imgSrcExt$[ebx]
	push	ecx
	mov	edx, DWORD PTR _imgWidthF$[ebx]
	push	edx
	mov	eax, DWORD PTR _imgWidth$[ebx]
	push	eax
	mov	ecx, DWORD PTR _imgHeight$[ebx]
	push	ecx
	lea	edx, DWORD PTR _filter_laplace$[ebp]
	push	edx
	push	OFFSET ?conv_filter_avx$omp$1@@YAXHHHPAFPAE1@Z ; conv_filter_avx$omp$1
	push	6
	push	1
	call	__vcomp_fork
	add	esp, 36					; 00000024H

; 25   : #else
; 26   : #endif
; 27   : 	for (int row=0; row<imgHeight; row++)
; 28   : 	{
; 29   : 		int wr_base = row*imgWidth*3;
; 30   : 		int rd_base = row*imgWidthF*3;
; 31   : 		// step through all components in a line
; 32   : 		for (int col=0; col<(imgWidth*3); col=col+16)
; 33   : 		{
; 34   : 			__m256i fval;
; 35   : 			fval = _mm256_set1_epi16(0);
; 36   : 
; 37   : 			int rd_offset = 0;
; 38   : 			for (int fy=0; fy<FILTER_H; fy++)
; 39   : 			{
; 40   : #if LOOP_UNROLL==0
; 41   : 				for (int fx=0; fx<FILTER_W; fx++)
; 42   : #endif
; 43   : 				{
; 44   : 					int pixel_src = rd_base + rd_offset;
; 45   : 					__m128i load_data;
; 46   : 					__m256i conv_res, mul_res;
; 47   : 
; 48   : #if LOOP_UNROLL==0
; 49   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src));
; 50   : 					conv_res = _mm256_cvtepu8_epi16(load_data);
; 51   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + fx]);
; 52   : 					fval = _mm256_add_epi16(fval, mul_res);
; 53   : 					rd_offset = rd_offset + 3;
; 54   : #else
; 55   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 0));
; 56   : 					conv_res = _mm256_cvtepu8_epi16(load_data);
; 57   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 0]);
; 58   : 					fval = _mm256_add_epi16(fval, mul_res);
; 59   : 
; 60   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 3));
; 61   : 					conv_res = _mm256_cvtepu8_epi16(load_data);
; 62   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 1]);
; 63   : 					fval = _mm256_add_epi16(fval, mul_res);
; 64   : 
; 65   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 6));
; 66   : 					conv_res = _mm256_cvtepu8_epi16(load_data);
; 67   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 2]);
; 68   : 					fval = _mm256_add_epi16(fval, mul_res);
; 69   : 
; 70   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 9));
; 71   : 					conv_res = _mm256_cvtepu8_epi16(load_data);
; 72   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 3]);
; 73   : 					fval = _mm256_add_epi16(fval, mul_res);
; 74   : 
; 75   : 					load_data = _mm_lddqu_si128((__m128i *)(imgSrcExt + pixel_src + 12));
; 76   : 					conv_res = _mm256_cvtepu8_epi16(load_data);
; 77   : 					mul_res = _mm256_mullo_epi16(conv_res, filter_laplace[fy * 5 + 4]);
; 78   : 					fval = _mm256_add_epi16(fval, mul_res);
; 79   : #endif
; 80   : 				}
; 81   : #if LOOP_UNROLL==0
; 82   : 				rd_offset = rd_offset - 5*3 + imgWidthF*3;
; 83   : #else
; 84   : 				rd_offset = rd_offset + imgWidthF * 3;
; 85   : #endif
; 86   : 			}
; 87   : 
; 88   : 			__m256i sat_val;
; 89   : 			sat_val = _mm256_set1_epi16(255);
; 90   : 			fval = _mm256_min_epi16(fval, sat_val);
; 91   : 			sat_val = _mm256_set1_epi16(0);
; 92   : 			fval = _mm256_max_epi16(fval, sat_val);
; 93   : 
; 94   : 			__m256i *res_vec_ptr;
; 95   : 			res_vec_ptr = &fval;
; 96   : 			short *res_short_ptr;
; 97   : 			res_short_ptr = (short*)(res_vec_ptr);
; 98   : 
; 99   : 			for (int i = 0; i < 16; i++)
; 100  : 			{
; 101  : 				*(imgDst + wr_base + i) = *(res_short_ptr + i);
; 102  : 			}
; 103  : 
; 104  : 			wr_base = wr_base + 16;
; 105  : 			rd_base = rd_base + 16;
; 106  : 		}
; 107  : 	}
; 108  : }

	push	edx
	mov	ecx, ebp
	push	eax
	lea	edx, DWORD PTR $LN19@conv_filte
	call	@_RTC_CheckStackVars@8
	pop	eax
	pop	edx
	pop	edi
	pop	esi
	mov	ecx, DWORD PTR __$ArrayPad$[ebp]
	xor	ecx, ebp
	call	@__security_check_cookie@4
	mov	esp, ebp
	pop	ebp
	mov	esp, ebx
	pop	ebx
	ret	0
	npad	2
$LN19@conv_filte:
	DD	1
	DD	$LN18@conv_filte
$LN18@conv_filte:
	DD	-832					; fffffcc0H
	DD	800					; 00000320H
	DD	$LN17@conv_filte
$LN17@conv_filte:
	DB	102					; 00000066H
	DB	105					; 00000069H
	DB	108					; 0000006cH
	DB	116					; 00000074H
	DB	101					; 00000065H
	DB	114					; 00000072H
	DB	95					; 0000005fH
	DB	108					; 0000006cH
	DB	97					; 00000061H
	DB	112					; 00000070H
	DB	108					; 0000006cH
	DB	97					; 00000061H
	DB	99					; 00000063H
	DB	101					; 00000065H
	DB	0
?conv_filter_avx@@YAXHHHPAFPAE1@Z ENDP			; conv_filter_avx
_TEXT	ENDS
END
