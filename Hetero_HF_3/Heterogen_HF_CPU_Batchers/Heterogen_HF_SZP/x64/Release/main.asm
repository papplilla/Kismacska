; Listing generated by Microsoft (R) Optimizing Compiler Version 19.14.26430.0 

include listing.inc

INCLUDELIB OLDNAMES

PUBLIC	??_C@_0L@OICGFOEL@output?4bmp?$AA@		; `string'
PUBLIC	??_C@_0P@NDNGIGNK@Teszt?5started?6?$AA@		; `string'
PUBLIC	??_C@_0BM@BNCOCNFJ@Output?5resolution?3?5?$CF4dx?$CF4d?6?$AA@ ; `string'
PUBLIC	??_C@_0BC@GIOFBGHC@hf_output_ref?4bmp?$AA@	; `string'
PUBLIC	??_C@_0CB@IAMBGCGL@Ref?5picture?5resolution?3?5?$CF4dx?$CF4d?6@ ; `string'
PUBLIC	??_C@_0BM@BOHMLGCJ@Nem?5egyeznek?5a?5sz?iless?igek?6?$AA@ ; `string'
PUBLIC	??_C@_0BM@IIPHDHFB@Nem?5egyeznek?5a?5hossz?zs?agok?6?$AA@ ; `string'
PUBLIC	??_C@_09CCAEKEFA@Baj?5van?$CB?6?$AA@		; `string'
PUBLIC	??_C@_07BLFELHIC@Erdeti?6?$AA@			; `string'
PUBLIC	??_C@_0BM@GEKJLJJG@?$CFd?4?5Sor?0?5?3?$CFd?4?5oszlop?3?5?$CFd?5?6?5?$AA@ ; `string'
PUBLIC	??_C@_06EKAJNINI@Sajat?6?$AA@			; `string'
PUBLIC	??_C@_0BN@LJFGHIFM@?$CFd?4?5Sor?0?5?3?$CFd?4?5oszlop?3?5?$CFd?5?6?6?5?$AA@ ; `string'
PUBLIC	??_C@_0M@CAGJMMDC@Minden?5ok?i?6?$AA@		; `string'
PUBLIC	??_C@_09HDLCNAPM@input?4jpg?$AA@		; `string'
PUBLIC	??_C@_0BL@EIJCCJGD@Input?5resolution?3?5?$CF4dx?$CF4d?6?$AA@ ; `string'
PUBLIC	??_C@_0BD@NGKMKCMP@C?5CPU?5TIME?3?5?$CF4?44f?6?$AA@ ; `string'
PUBLIC	??_C@_0BD@CKJPLJHO@C?5Mpixel?1s?3?5?$CF4?44f?6?$AA@ ; `string'
EXTRN	__imp_ilGenImages:PROC
EXTRN	__imp_ilGetInteger:PROC
EXTRN	__imp_ilGetData:PROC
EXTRN	__imp_ilBindImage:PROC
EXTRN	__imp_ilInit:PROC
EXTRN	__imp_iluInit:PROC
EXTRN	_aligned_malloc:PROC
EXTRN	__imp_ilDeleteImages:PROC
EXTRN	__imp_ilLoadImage:PROC
EXTRN	__imp_ilSetData:PROC
EXTRN	__imp_ilEnable:PROC
EXTRN	__imp_ilSaveImage:PROC
EXTRN	clock:PROC
EXTRN	_aligned_free:PROC
;	COMDAT ??_C@_0BD@CKJPLJHO@C?5Mpixel?1s?3?5?$CF4?44f?6?$AA@
CONST	SEGMENT
??_C@_0BD@CKJPLJHO@C?5Mpixel?1s?3?5?$CF4?44f?6?$AA@ DB 'C Mpixel/s: %4.4f'
	DB	0aH, 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BD@NGKMKCMP@C?5CPU?5TIME?3?5?$CF4?44f?6?$AA@
CONST	SEGMENT
??_C@_0BD@NGKMKCMP@C?5CPU?5TIME?3?5?$CF4?44f?6?$AA@ DB 'C CPU TIME: %4.4f'
	DB	0aH, 00H					; `string'
CONST	ENDS
;	COMDAT ??_C@_0BL@EIJCCJGD@Input?5resolution?3?5?$CF4dx?$CF4d?6?$AA@
CONST	SEGMENT
??_C@_0BL@EIJCCJGD@Input?5resolution?3?5?$CF4dx?$CF4d?6?$AA@ DB 'Input re'
	DB	'solution: %4dx%4d', 0aH, 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_09HDLCNAPM@input?4jpg?$AA@
CONST	SEGMENT
??_C@_09HDLCNAPM@input?4jpg?$AA@ DB 'input.jpg', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0M@CAGJMMDC@Minden?5ok?i?6?$AA@
CONST	SEGMENT
??_C@_0M@CAGJMMDC@Minden?5ok?i?6?$AA@ DB 'Minden ok', 0e9H, 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BN@LJFGHIFM@?$CFd?4?5Sor?0?5?3?$CFd?4?5oszlop?3?5?$CFd?5?6?6?5?$AA@
CONST	SEGMENT
??_C@_0BN@LJFGHIFM@?$CFd?4?5Sor?0?5?3?$CFd?4?5oszlop?3?5?$CFd?5?6?6?5?$AA@ DB '%'
	DB	'd. Sor, :%d. oszlop: %d ', 0aH, 0aH, ' ', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_06EKAJNINI@Sajat?6?$AA@
CONST	SEGMENT
??_C@_06EKAJNINI@Sajat?6?$AA@ DB 'Sajat', 0aH, 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BM@GEKJLJJG@?$CFd?4?5Sor?0?5?3?$CFd?4?5oszlop?3?5?$CFd?5?6?5?$AA@
CONST	SEGMENT
??_C@_0BM@GEKJLJJG@?$CFd?4?5Sor?0?5?3?$CFd?4?5oszlop?3?5?$CFd?5?6?5?$AA@ DB '%'
	DB	'd. Sor, :%d. oszlop: %d ', 0aH, ' ', 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_07BLFELHIC@Erdeti?6?$AA@
CONST	SEGMENT
??_C@_07BLFELHIC@Erdeti?6?$AA@ DB 'Erdeti', 0aH, 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_09CCAEKEFA@Baj?5van?$CB?6?$AA@
CONST	SEGMENT
??_C@_09CCAEKEFA@Baj?5van?$CB?6?$AA@ DB 'Baj van!', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BM@IIPHDHFB@Nem?5egyeznek?5a?5hossz?zs?agok?6?$AA@
CONST	SEGMENT
??_C@_0BM@IIPHDHFB@Nem?5egyeznek?5a?5hossz?zs?agok?6?$AA@ DB 'Nem egyezne'
	DB	'k a hossz', 0faH, 's', 0e1H, 'gok', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BM@BOHMLGCJ@Nem?5egyeznek?5a?5sz?iless?igek?6?$AA@
CONST	SEGMENT
??_C@_0BM@BOHMLGCJ@Nem?5egyeznek?5a?5sz?iless?igek?6?$AA@ DB 'Nem egyezne'
	DB	'k a sz', 0e9H, 'less', 0e9H, 'gek', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0CB@IAMBGCGL@Ref?5picture?5resolution?3?5?$CF4dx?$CF4d?6@
CONST	SEGMENT
??_C@_0CB@IAMBGCGL@Ref?5picture?5resolution?3?5?$CF4dx?$CF4d?6@ DB 'Ref p'
	DB	'icture resolution: %4dx%4d', 0aH, 00H	; `string'
CONST	ENDS
;	COMDAT ??_C@_0BC@GIOFBGHC@hf_output_ref?4bmp?$AA@
CONST	SEGMENT
??_C@_0BC@GIOFBGHC@hf_output_ref?4bmp?$AA@ DB 'hf_output_ref.bmp', 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0BM@BNCOCNFJ@Output?5resolution?3?5?$CF4dx?$CF4d?6?$AA@
CONST	SEGMENT
??_C@_0BM@BNCOCNFJ@Output?5resolution?3?5?$CF4dx?$CF4d?6?$AA@ DB 'Output '
	DB	'resolution: %4dx%4d', 0aH, 00H		; `string'
CONST	ENDS
;	COMDAT ??_C@_0P@NDNGIGNK@Teszt?5started?6?$AA@
CONST	SEGMENT
??_C@_0P@NDNGIGNK@Teszt?5started?6?$AA@ DB 'Teszt started', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT ??_C@_0L@OICGFOEL@output?4bmp?$AA@
CONST	SEGMENT
??_C@_0L@OICGFOEL@output?4bmp?$AA@ DB 'output.bmp', 00H	; `string'
PUBLIC	main
PUBLIC	?verifyImage@@YAHXZ				; verifyImage
;	COMDAT pdata
pdata	SEGMENT
$pdata$main DD	imagerel $LN95
	DD	imagerel $LN95+43
	DD	imagerel $unwind$main
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$0$main DD imagerel $LN95+43
	DD	imagerel $LN95+314
	DD	imagerel $chain$0$main
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$1$main DD imagerel $LN95+314
	DD	imagerel $LN95+1645
	DD	imagerel $chain$1$main
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$2$main DD imagerel $LN95+1645
	DD	imagerel $LN95+2493
	DD	imagerel $chain$2$main
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?verifyImage@@YAHXZ DD imagerel $LN22@verifyImag
	DD	imagerel $LN22@verifyImag+334
	DD	imagerel $unwind$?verifyImage@@YAHXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$0$?verifyImage@@YAHXZ DD imagerel $LN22@verifyImag+334
	DD	imagerel $LN22@verifyImag+350
	DD	imagerel $chain$0$?verifyImage@@YAHXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$2$?verifyImage@@YAHXZ DD imagerel $LN22@verifyImag+350
	DD	imagerel $LN22@verifyImag+539
	DD	imagerel $chain$2$?verifyImage@@YAHXZ
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$3$?verifyImage@@YAHXZ DD imagerel $LN22@verifyImag+539
	DD	imagerel $LN22@verifyImag+603
	DD	imagerel $chain$3$?verifyImage@@YAHXZ
pdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$3$?verifyImage@@YAHXZ DD 021H
	DD	imagerel $LN22@verifyImag+334
	DD	imagerel $LN22@verifyImag+350
	DD	imagerel $chain$0$?verifyImage@@YAHXZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$2$?verifyImage@@YAHXZ DD 040e21H
	DD	05d40eH
	DD	075405H
	DD	imagerel $LN22@verifyImag+334
	DD	imagerel $LN22@verifyImag+350
	DD	imagerel $chain$0$?verifyImage@@YAHXZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$0$?verifyImage@@YAHXZ DD 020521H
	DD	066405H
	DD	imagerel $LN22@verifyImag
	DD	imagerel $LN22@verifyImag+334
	DD	imagerel $unwind$?verifyImage@@YAHXZ
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?verifyImage@@YAHXZ DD 060d01H
	DD	0f009720dH
	DD	0c005e007H
	DD	030027003H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$2$main DD 020021H
	DD	054c400H
	DD	imagerel $LN95
	DD	imagerel $LN95+43
	DD	imagerel $unwind$main
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$1$main DD 020821H
	DD	054c408H
	DD	imagerel $LN95+43
	DD	imagerel $LN95+314
	DD	imagerel $chain$0$main
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$0$main DD 020921H
	DD	0266809H
	DD	imagerel $LN95
	DD	imagerel $LN95+43
	DD	imagerel $unwind$main
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$main DD	0b2b19H
	DD	0565419H
	DD	0553419H
	DD	04e0119H
	DD	0e010f012H
	DD	0700cd00eH
	DD	0600bH
	DD	imagerel __GSHandlerCheck
	DD	0250H
; Function compile flags: /Ogtpy
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hf_3\heterogen_hf_cpu_batchers\heterogen_hf_szp\_src\main.cpp
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hf_3\heterogen_hf_cpu_batchers\heterogen_hf_szp\_src\conv_filter_avx.cpp
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hf_3\heterogen_hf_cpu_batchers\heterogen_hf_szp\_src\main.cpp
;	COMDAT main
_TEXT	SEGMENT
tv13695 = 32
tv13650 = 32
s0$1$ = 32
tv13691 = 40
tv13660 = 40
tv13632 = 40
tv13692 = 48
tv13658 = 48
tv13645 = 48
tv13649 = 56
imgHeight$1$ = 56
ilImg$ = 64
tv13694 = 72
imgFloatRes$1$ = 72
imgData$1$ = 80
imgWidth$1$ = 88
tv13680 = 96
tv13640 = 96
tv13646 = 104
tv13609 = 104
tv13678 = 112
tv13637 = 112
tv13676 = 120
tv13672 = 120
tv13659 = 128
tv13605 = 128
tv13611 = 136
tv13603 = 136
tv13714 = 144
tv13613 = 144
tv13712 = 152
tv13617 = 152
tv13674 = 160
tv13619 = 160
tv13718 = 168
tv13623 = 168
imgFloat$1$ = 176
tv13754 = 184
medianArray$2 = 192
__$ArrayPad$ = 592
main	PROC						; COMDAT

; 102  : {

$LN95:
	mov	QWORD PTR [rsp+16], rbx
	mov	QWORD PTR [rsp+24], rbp
	push	rsi
	push	rdi
	push	r13
	push	r14
	push	r15
	sub	rsp, 624				; 00000270H
	mov	rax, QWORD PTR __security_cookie
	xor	rax, rsp
	mov	QWORD PTR __$ArrayPad$[rsp], rax
	vmovaps	XMMWORD PTR [rsp+608], xmm6

; 103  : #ifdef  VERIFY
; 104  : 
; 105  : 	verifyImage();
; 106  : #else 
; 107  : 	ilInit(); iluInit();

	call	QWORD PTR __imp_ilInit
	call	QWORD PTR __imp_iluInit

; 108  : 	ILboolean ret;
; 109  : 	ILuint ilImg=0;

	xor	r15d, r15d

; 110  : 	ilGenImages(1, &ilImg);

	lea	rdx, QWORD PTR ilImg$[rsp]
	mov	DWORD PTR ilImg$[rsp], r15d
	lea	ecx, QWORD PTR [r15+1]
	call	QWORD PTR __imp_ilGenImages

; 111  : 	ilBindImage(ilImg);

	mov	ecx, DWORD PTR ilImg$[rsp]
	call	QWORD PTR __imp_ilBindImage

; 112  :     ret = ilLoadImage((const char*)("input.jpg"));

	lea	rcx, OFFSET FLAT:??_C@_09HDLCNAPM@input?4jpg?$AA@
	call	QWORD PTR __imp_ilLoadImage

; 113  : 	ILubyte* imgData = ilGetData(); 

	call	QWORD PTR __imp_ilGetData

; 114  : 
; 115  : 	int imgWidth = ilGetInteger(IL_IMAGE_WIDTH);

	mov	ecx, 3556				; 00000de4H
	mov	QWORD PTR imgData$1$[rsp], rax
	mov	r13, rax
	call	QWORD PTR __imp_ilGetInteger

; 116  : 	int imgHeight = ilGetInteger(IL_IMAGE_HEIGHT);

	mov	ecx, 3557				; 00000de5H
	mov	DWORD PTR imgWidth$1$[rsp], eax
	mov	r14d, eax
	call	QWORD PTR __imp_ilGetInteger

; 117  : 	ILint imgOrigin = ilGetInteger(IL_ORIGIN_MODE);

	mov	ecx, 1539				; 00000603H
	mov	DWORD PTR imgHeight$1$[rsp], eax
	mov	ebp, eax
	call	QWORD PTR __imp_ilGetInteger

; 118  : 
; 119  : 	printf("Input resolution: %4dx%4d\n", imgWidth, imgHeight);

	mov	r8d, ebp
	lea	rcx, OFFSET FLAT:??_C@_0BL@EIJCCJGD@Input?5resolution?3?5?$CF4dx?$CF4d?6?$AA@
	mov	edx, r14d
	call	printf

; 120  : 
; 121  : 	float *imgFloat;
; 122  : 	int imgWidthF = imgWidth+FILTER_W-1;
; 123  : 	int imgHeightF = imgHeight+FILTER_H-1;

	lea	edi, DWORD PTR [rbp+4]

; 124  : 	int imgFOffsetW = (FILTER_W-1)/2;
; 125  : 	int imgFOffsetH = (FILTER_H-1)/2;
; 126  : 	imgFloat   = (float *)(_aligned_malloc(4*imgWidthF*imgHeightF*sizeof(float), 32));

	mov	eax, edi
	lea	esi, DWORD PTR [r14+4]
	imul	eax, esi
	lea	edx, QWORD PTR [r15+32]
	shl	eax, 2
	cdqe
	shl	rax, 2
	mov	rcx, rax
	mov	QWORD PTR tv13718[rsp], rax
	call	_aligned_malloc
	mov	QWORD PTR imgFloat$1$[rsp], rax
	mov	rbx, rax

; 127  :     int row, col;
; 128  : 
; 129  : 	for (row=0; row<imgHeightF; row++)

	test	edi, edi
	jle	SHORT $LN3@main

; 103  : #ifdef  VERIFY
; 104  : 
; 105  : 	verifyImage();
; 106  : #else 
; 107  : 	ilInit(); iluInit();

	lea	ecx, DWORD PTR [rsi*4]
	mov	r8d, edi
	movsxd	r9, ecx
	lea	rdx, QWORD PTR [rax+8]
	shl	r9, 2
	npad	7
$LL4@main:

; 130  : 	{
; 131  : 		for (col=0; col<imgWidthF;col++)

	test	esi, esi
	jle	SHORT $LN2@main
	mov	rax, rdx
	mov	ecx, esi
	npad	7
$LL7@main:

; 132  : 		{
; 133  : 			int pixel = (row*imgWidthF + col)*4;
; 134  : 			*(imgFloat+pixel+0) = 0.0f;

	mov	QWORD PTR [rax-8], r15

; 135  : 			*(imgFloat + pixel + 1) = 0.0f;
; 136  : 			*(imgFloat + pixel + 2) = 0.0f;

	mov	QWORD PTR [rax], r15
	lea	rax, QWORD PTR [rax+16]
	sub	rcx, 1
	jne	SHORT $LL7@main
$LN2@main:

; 127  :     int row, col;
; 128  : 
; 129  : 	for (row=0; row<imgHeightF; row++)

	add	rdx, r9
	sub	r8, 1
	jne	SHORT $LL4@main
$LN3@main:
	mov	QWORD PTR [rsp+672], r12

; 137  : 			*(imgFloat + pixel + 3) = 0.0f;
; 138  : 		}
; 139  : 	}
; 140  : 
; 141  : 	for (row=0; row<imgHeight; row++)

	test	ebp, ebp
	jle	$LN9@main
	lea	ecx, DWORD PTR [rsi*8]
	xor	edi, edi
	lea	eax, DWORD PTR [r14+r14*2]
	movsxd	rbp, ecx
	cdqe
	lea	r12d, DWORD PTR [rsi+rsi]
	mov	QWORD PTR tv13674[rsp], rax
	add	rbp, 8
	lea	eax, DWORD PTR [rsi*4]
	movsxd	r13, ecx
	cdqe
	mov	QWORD PTR tv13714[rsp], rax
	lea	r8, QWORD PTR [rbp+6]
	mov	DWORD PTR tv13695[rsp], r12d
	lea	r8, QWORD PTR [rbx+r8*4]
	mov	QWORD PTR tv13692[rsp], rbp
	lea	rax, QWORD PTR [rax*4]
	mov	QWORD PTR tv13691[rsp], r8
	mov	QWORD PTR tv13712[rsp], rax
	lea	eax, DWORD PTR [rsi*8+16]
	movsxd	rdx, eax
	mov	eax, DWORD PTR imgHeight$1$[rsp]
	sub	rdx, rbp
	mov	QWORD PTR tv13609[rsp], rdx
	sub	r13, rbp
	mov	QWORD PTR tv13694[rsp], rax
	npad	11
$LL10@main:

; 142  : 	{
; 143  : 		for (col=0; col<imgWidth;col++)

	xor	r11d, r11d
	cmp	r14d, 4
	jl	$LC76@main
	mov	rbx, QWORD PTR imgData$1$[rsp]
	lea	rcx, QWORD PTR [rdi+9]
	mov	rax, rcx
	mov	r10, rbx
	sub	rax, rdi
	add	rax, -3
	mov	QWORD PTR tv13680[rsp], rax
	lea	rdx, QWORD PTR [rbx+1]
	mov	rsi, QWORD PTR tv13680[rsp]
	lea	r11, QWORD PTR [rbx-3]
	sub	rax, rdx
	lea	r9, QWORD PTR [rdx+3]
	add	r11, rax
	sub	rcx, rdx
	dec	rax
	mov	QWORD PTR tv13678[rsp], r11
	add	rax, rbx
	sub	rcx, rdi
	mov	QWORD PTR tv13676[rsp], rax
	sub	r10, rdx
	mov	rdx, QWORD PTR tv13609[rsp]
	add	r9, rdi
	lea	rax, QWORD PTR [rcx+rbx]
	mov	QWORD PTR tv13605[rsp], rax
	lea	rax, QWORD PTR [rbx+2]
	mov	rbx, QWORD PTR tv13678[rsp]
	add	rax, rcx
	mov	rbp, QWORD PTR tv13605[rsp]
	mov	QWORD PTR tv13603[rsp], rax
	lea	eax, DWORD PTR [r14-4]
	mov	r14, QWORD PTR tv13676[rsp]
	mov	r12, QWORD PTR tv13603[rsp]
	shr	eax, 2
	inc	eax
	mov	ecx, eax
	lea	r11d, DWORD PTR [rax*4]
	npad	8
$LL77@main:

; 144  : 		{
; 145  : 			int pixel_dst = ((row+imgFOffsetH)*imgWidthF + (col+imgFOffsetW))*4;
; 146  : 			int pixel_src = (row*imgWidth + col)*3;
; 147  : 			*(imgFloat+pixel_dst+0) = (float)(*(imgData+pixel_src+0));

	movzx	eax, BYTE PTR [r10+r9-3]

; 150  : 			*(imgFloat+pixel_dst+3) = 0.0;

	lea	r8, QWORD PTR [r8+64]
	lea	r9, QWORD PTR [r9+12]
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8-88], xmm0
	movzx	eax, BYTE PTR [r9-15]
	vxorps	xmm0, xmm0, xmm0
	vxorps	xmm1, xmm1, xmm1
	vcvtsi2ss xmm1, xmm1, eax
	vmovss	DWORD PTR [r8-84], xmm1
	movzx	eax, BYTE PTR [r9-14]
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8-80], xmm0
	mov	DWORD PTR [r8-76], 0
	movzx	eax, BYTE PTR [r10+r9-12]
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8-72], xmm0
	movzx	eax, BYTE PTR [r9-12]
	vxorps	xmm0, xmm0, xmm0
	vxorps	xmm1, xmm1, xmm1
	vcvtsi2ss xmm1, xmm1, eax
	vmovss	DWORD PTR [r8-68], xmm1
	movzx	eax, BYTE PTR [r9-11]
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8-64], xmm0
	mov	DWORD PTR [r8-60], 0
	movzx	eax, BYTE PTR [rbx+r9-12]
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8+rdx*4-88], xmm0
	movzx	eax, BYTE PTR [rsi+r9-15]
	vxorps	xmm0, xmm0, xmm0
	vxorps	xmm1, xmm1, xmm1
	vcvtsi2ss xmm1, xmm1, eax
	vmovss	DWORD PTR [r8+rdx*4-84], xmm1
	movzx	eax, BYTE PTR [r14+r9-12]
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8+rdx*4-80], xmm0
	mov	DWORD PTR [r8+rdx*4-76], 0
	movzx	eax, BYTE PTR [r9+rbp-15]
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8+r13*4-8], xmm0
	movzx	eax, BYTE PTR [r9-6]
	vxorps	xmm1, xmm1, xmm1
	vcvtsi2ss xmm1, xmm1, eax
	vmovss	DWORD PTR [r8+r13*4-4], xmm1
	movzx	eax, BYTE PTR [r12+r9-15]
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8+r13*4], xmm0
	mov	DWORD PTR [r8+r13*4+4], 0
	sub	rcx, 1
	jne	$LL77@main
	mov	r14d, DWORD PTR imgWidth$1$[rsp]
	mov	rbx, QWORD PTR imgFloat$1$[rsp]
	mov	rbp, QWORD PTR tv13692[rsp]
	mov	r12d, DWORD PTR tv13695[rsp]
	mov	r8, QWORD PTR tv13691[rsp]
	lea	esi, DWORD PTR [r14+4]
	mov	rax, QWORD PTR tv13694[rsp]
$LC76@main:

; 142  : 	{
; 143  : 		for (col=0; col<imgWidth;col++)

	cmp	r11d, r14d
	jge	$LN8@main
	mov	r10, QWORD PTR imgData$1$[rsp]
	lea	eax, DWORD PTR [r15+r11]
	lea	ecx, DWORD PTR [rax+rax*2]
	movsxd	r9, ecx
	lea	eax, DWORD PTR [r12+r11]
	lea	eax, DWORD PTR [rax*4+8]
	mov	ecx, r14d
	lea	rdx, QWORD PTR [r10+1]
	movsxd	r8, eax
	add	r8, 2
	add	r9, rdx
	sub	r10, rdx
	sub	ecx, r11d
	lea	r8, QWORD PTR [rbx+r8*4]
$LC13@main:

; 144  : 		{
; 145  : 			int pixel_dst = ((row+imgFOffsetH)*imgWidthF + (col+imgFOffsetW))*4;
; 146  : 			int pixel_src = (row*imgWidth + col)*3;
; 147  : 			*(imgFloat+pixel_dst+0) = (float)(*(imgData+pixel_src+0));

	movzx	eax, BYTE PTR [r9+r10]
	lea	r8, QWORD PTR [r8+16]
	lea	r9, QWORD PTR [r9+3]
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8-24], xmm0

; 148  : 			*(imgFloat+pixel_dst+1) = (float)(*(imgData+pixel_src+1));

	movzx	eax, BYTE PTR [r9-3]
	vxorps	xmm1, xmm1, xmm1
	vcvtsi2ss xmm1, xmm1, eax
	vmovss	DWORD PTR [r8-20], xmm1

; 149  : 			*(imgFloat+pixel_dst+2) = (float)(*(imgData+pixel_src+2));

	movzx	eax, BYTE PTR [r9-2]

; 150  : 			*(imgFloat+pixel_dst+3) = 0.0;

	mov	DWORD PTR [r8-12], 0
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2ss xmm0, xmm0, eax
	vmovss	DWORD PTR [r8-16], xmm0
	sub	rcx, 1
	jne	SHORT $LC13@main
	mov	r8, QWORD PTR tv13691[rsp]
	mov	rax, QWORD PTR tv13694[rsp]
$LN8@main:

; 137  : 			*(imgFloat + pixel + 3) = 0.0f;
; 138  : 		}
; 139  : 	}
; 140  : 
; 141  : 	for (row=0; row<imgHeight; row++)

	add	rbp, QWORD PTR tv13714[rsp]
	add	r12d, esi
	add	r8, QWORD PTR tv13712[rsp]
	add	r15d, r14d
	add	rdi, QWORD PTR tv13674[rsp]
	sub	rax, 1
	mov	QWORD PTR tv13692[rsp], rbp
	mov	QWORD PTR tv13694[rsp], rax
	mov	QWORD PTR tv13691[rsp], r8
	mov	DWORD PTR tv13695[rsp], r12d
	jne	$LL10@main
	mov	r13, QWORD PTR imgData$1$[rsp]
	mov	ebp, DWORD PTR imgHeight$1$[rsp]
$LN9@main:

; 151  : 		}
; 152  : 	}
; 153  : 
; 154  : 
; 155  : // IMAGE PROCESSING
; 156  : //---------------------------------------------------------------------------------------
; 157  : 	clock_t s0, e0;
; 158  :     double d0;
; 159  : 
; 160  : 	float *imgFloatRes;
; 161  :     imgFloatRes = (float *)(_aligned_malloc(4*imgWidthF*imgHeightF*sizeof(float), 32));

	mov	rcx, QWORD PTR tv13718[rsp]
	mov	edx, 32					; 00000020H
	call	_aligned_malloc
	mov	rdi, rax
	mov	QWORD PTR imgFloatRes$1$[rsp], rax

; 162  : 
; 163  : 	double mpixel;
; 164  : 
; 165  : 
; 166  : 	s0 = clock();

	call	clock
	mov	DWORD PTR s0$1$[rsp], eax
	lea	eax, DWORD PTR [rbp+2]
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hf_3\heterogen_hf_cpu_batchers\heterogen_hf_szp\_src\conv_filter_avx.cpp

; 388  : 	for (int y = imgFOffsetH; y < (imgHeight + imgFOffsetH); y++)

	cmp	eax, 2
	jle	$LN26@main
	lea	ecx, DWORD PTR [r14*4]
	mov	r15d, 4
	movsxd	rcx, ecx
	lea	r8d, DWORD PTR [r14+2]
	shl	rcx, 2
	lea	esi, DWORD PTR [rsi*4]
	mov	QWORD PTR tv13658[rsp], rcx
	add	eax, -2					; fffffffeH
	lea	ecx, DWORD PTR [r14*8+8]
	mov	QWORD PTR tv13660[rsp], rax
	movsxd	rdx, ecx
	mov	rcx, QWORD PTR tv13658[rsp]
	lea	r12, QWORD PTR [rdi+rdx*4]
$LL27@main:

; 389  : 	{
; 390  : 	// Kép oszlopai
; 391  : 	for (int x = imgFOffsetW; x < (imgWidth + imgFOffsetW); x++)

	cmp	r8d, 2
	jle	$LN25@main
	mov	r10d, r15d
	lea	ebp, DWORD PTR [r8-2]
	mov	rdi, r12
	npad	7
$LL30@main:

; 392  : 	{
; 393  : 		__m128 medianArray[25];
; 394  : 		for (int medianY = 0; medianY < 5; medianY++)

	lea	rdx, QWORD PTR medianArray$2[rsp+16]
	mov	r8d, r10d
	mov	r9d, 5
$LL33@main:

; 395  : 			for (int medianX = 0; medianX < 5; medianX++)
; 396  : 				medianArray[5 * medianY + medianX] = _mm_load_ps(imgFloatSrc + ((y + (medianY - 2))*imgWidthF + x + (medianX - 2)) * 4);

	lea	eax, DWORD PTR [r8-4]
	movsxd	rcx, eax
	lea	rdx, QWORD PTR [rdx+80]
	movsxd	rax, r8d
	vmovups	xmm0, XMMWORD PTR [rbx+rcx*4]
	vmovups	XMMWORD PTR [rdx-96], xmm0
	vmovups	xmm0, XMMWORD PTR [rbx+rax*4]
	vmovups	XMMWORD PTR [rdx-80], xmm0
	lea	eax, DWORD PTR [r8+4]
	movsxd	rcx, eax
	lea	eax, DWORD PTR [r8+8]
	vmovups	xmm0, XMMWORD PTR [rbx+rcx*4]
	movsxd	rcx, eax
	lea	eax, DWORD PTR [r8+12]
	vmovups	XMMWORD PTR [rdx-64], xmm0
	add	r8d, esi
	vmovups	xmm0, XMMWORD PTR [rbx+rcx*4]
	movsxd	rcx, eax
	vmovups	XMMWORD PTR [rdx-48], xmm0
	vmovups	xmm0, XMMWORD PTR [rbx+rcx*4]
	vmovups	XMMWORD PTR [rdx-32], xmm0
	sub	r9, 1
	jne	SHORT $LL33@main

; 397  : 
; 398  : 		//mergeSortAVX(medianArray);
; 399  : 		mergeSortFullAVX(medianArray);

	lea	rcx, QWORD PTR medianArray$2[rsp]
	call	?mergeSortFullAVX@@YAXPEAT__m128@@@Z	; mergeSortFullAVX

; 400  : 		//printf("b++");
; 401  : 		_mm_stream_ps(imgFloatDst + (y*imgWidth + x) * 4, medianArray[MEDIAN]);

	vmovups	xmm0, XMMWORD PTR medianArray$2[rsp+192]
	vmovntps XMMWORD PTR [rdi], xmm0
	add	rdi, 16
	add	r10d, 4
	sub	rbp, 1
	jne	$LL30@main
	mov	rax, QWORD PTR tv13660[rsp]
	lea	r8d, DWORD PTR [r14+2]
	mov	rcx, QWORD PTR tv13658[rsp]
$LN25@main:

; 388  : 	for (int y = imgFOffsetH; y < (imgHeight + imgFOffsetH); y++)

	add	r15d, esi
	add	r12, rcx
	sub	rax, 1
	mov	QWORD PTR tv13660[rsp], rax
	jne	$LL27@main
	mov	rdi, QWORD PTR imgFloatRes$1$[rsp]
	mov	ebp, DWORD PTR imgHeight$1$[rsp]
$LN26@main:

; 402  : 	}
; 403  : 	}
; 404  : 
; 405  : printf("b+");

	lea	rcx, OFFSET FLAT:??_C@_02DNJNMEMK@b?$CL?$AA@
	call	printf
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hf_3\heterogen_hf_cpu_batchers\heterogen_hf_szp\_src\main.cpp

; 174  :     e0 = clock();

	call	clock

; 175  :     d0 = (double)(e0-s0)/(RUNS*CLOCKS_PER_SEC);

	sub	eax, DWORD PTR s0$1$[rsp]

; 176  : 	mpixel = (imgWidth*imgHeight/d0)/1000000;
; 177  :     printf("C CPU TIME: %4.4f\n", d0);

	lea	rcx, OFFSET FLAT:??_C@_0BD@NGKMKCMP@C?5CPU?5TIME?3?5?$CF4?44f?6?$AA@
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2sd xmm0, xmm0, eax
	vdivsd	xmm6, xmm0, QWORD PTR __real@408f400000000000
	vmovaps	xmm1, xmm6
	vmovq	rdx, xmm1
	call	printf
	mov	eax, ebp

; 178  : 	printf("C Mpixel/s: %4.4f\n", mpixel);

	lea	rcx, OFFSET FLAT:??_C@_0BD@CKJPLJHO@C?5Mpixel?1s?3?5?$CF4?44f?6?$AA@
	imul	eax, r14d
	vxorps	xmm0, xmm0, xmm0
	vcvtsi2sd xmm0, xmm0, eax
	vdivsd	xmm1, xmm0, xmm6
	vdivsd	xmm1, xmm1, QWORD PTR __real@412e848000000000
	vmovq	rdx, xmm1
	call	printf
	vmovaps	xmm6, XMMWORD PTR [rsp+608]

; 179  : 
; 180  : 
; 181  : 
; 182  : 	float *imgFloatWrite;
; 183  : 	imgFloatWrite = imgFloatRes;
; 184  : 
; 185  : //---------------------------------------------------------------------------------------
; 186  : // IMAGE PROCESSING END
; 187  : 
; 188  : 
; 189  : 	for (row=0; row<imgHeight; row++)

	test	ebp, ebp
	jle	$LN18@main

; 175  :     d0 = (double)(e0-s0)/(RUNS*CLOCKS_PER_SEC);

	mov	esi, DWORD PTR imgHeight$1$[rsp]
	lea	ecx, DWORD PTR [r14*8]
	xor	r12d, r12d
	movsxd	r15, ecx
	add	r15, 8
	movsxd	r10, ecx
	xor	r13d, r13d
	movsxd	r11, ecx
	lea	eax, DWORD PTR [r14+r14*2]
	mov	DWORD PTR tv13650[rsp], r12d
	cdqe
	lea	r9d, DWORD PTR [r14+r14]
	mov	QWORD PTR tv13672[rsp], rax
	lea	rbx, QWORD PTR [r15+2]
	lea	eax, DWORD PTR [r14*4]
	mov	QWORD PTR tv13646[rsp], r13
	movsxd	rbp, eax
	lea	rbx, QWORD PTR [rdi+rbx*4]
	lea	eax, DWORD PTR [r14*8+16]
	mov	QWORD PTR tv13645[rsp], r15
	cdqe
	sub	r10, rax
	mov	QWORD PTR tv13659[rsp], rbp
	sub	rax, r15
	mov	QWORD PTR tv13640[rsp], rbx
	mov	QWORD PTR tv13637[rsp], rax
	sub	r11, r15
	mov	QWORD PTR tv13754[rsp], r10
	mov	DWORD PTR tv13632[rsp], r9d
	mov	QWORD PTR tv13649[rsp], rsi
$LL19@main:

; 190  : 	{
; 191  : 		for (col=0; col<imgWidth;col++)

	xor	edi, edi
	cmp	r14d, 4
	jl	$LC79@main
	mov	rdi, QWORD PTR imgData$1$[rsp]
	lea	r9, QWORD PTR [r15+rax]
	lea	rbp, QWORD PTR [r13+9]
	mov	r8, rbx
	mov	rax, r9
	mov	rsi, rdi
	sub	rax, r15
	sub	r9, r15
	add	r10, rax
	lea	rcx, QWORD PTR [rdi+1]
	lea	rdx, QWORD PTR [rcx+3]
	sub	rsi, rcx
	mov	rax, rbp
	lea	rbx, QWORD PTR [rdi-3]
	sub	rax, r13
	sub	rbp, r13
	add	rax, -3
	add	rdx, r13
	mov	QWORD PTR tv13623[rsp], rax
	sub	rax, rcx
	add	rbx, rax
	dec	rax
	add	rax, rdi
	mov	QWORD PTR tv13619[rsp], rbx
	mov	rbx, QWORD PTR tv13623[rsp]
	mov	QWORD PTR tv13617[rsp], rax
	mov	rax, rbp
	mov	r12, QWORD PTR tv13617[rsp]
	sub	rax, rcx
	lea	rcx, QWORD PTR [rdi-3]
	add	rcx, rax
	dec	rax
	add	rax, rdi
	mov	QWORD PTR tv13613[rsp], rcx
	mov	r15, QWORD PTR tv13613[rsp]
	mov	QWORD PTR tv13611[rsp], rax
	lea	eax, DWORD PTR [r14-4]
	mov	r14, QWORD PTR tv13619[rsp]
	mov	r13, QWORD PTR tv13611[rsp]
	shr	eax, 2
	inc	eax
	mov	ecx, eax
	lea	edi, DWORD PTR [rax*4]
	npad	1
$LL80@main:

; 197  : 			*(imgData+pixel_dst+2) = (ILubyte)(*(imgFloatWrite+pixel_src+2));

	lea	rdx, QWORD PTR [rdx+12]
	vcvttss2si eax, DWORD PTR [r8-8]
	mov	BYTE PTR [rsi+rdx-15], al
	vcvttss2si eax, DWORD PTR [r8-4]
	mov	BYTE PTR [rdx-15], al
	vcvttss2si eax, DWORD PTR [r8]
	mov	BYTE PTR [rdx-14], al
	vcvttss2si eax, DWORD PTR [r8+r10*4+40]
	mov	BYTE PTR [rsi+rdx-12], al
	vcvttss2si eax, DWORD PTR [r8+r10*4+44]
	mov	BYTE PTR [rdx-12], al
	vcvttss2si eax, DWORD PTR [r8+r10*4+48]
	mov	BYTE PTR [rdx-11], al
	vcvttss2si eax, DWORD PTR [r8+r9*4-8]
	mov	BYTE PTR [r14+rdx-12], al
	vcvttss2si eax, DWORD PTR [r8+r9*4-4]
	mov	BYTE PTR [rbx+rdx-15], al
	vcvttss2si eax, DWORD PTR [r8+r9*4]
	mov	BYTE PTR [r12+rdx-12], al
	vcvttss2si eax, DWORD PTR [r8+r11*4+72]
	mov	BYTE PTR [r15+rdx-12], al
	vcvttss2si eax, DWORD PTR [r8+r11*4+76]
	mov	BYTE PTR [rdx+rbp-15], al
	vcvttss2si eax, DWORD PTR [r8+r11*4+80]
	mov	BYTE PTR [rdx+r13-12], al
	lea	r8, QWORD PTR [r8+64]
	sub	rcx, 1
	jne	$LL80@main
	mov	r14d, DWORD PTR imgWidth$1$[rsp]
	mov	r15, QWORD PTR tv13645[rsp]
	mov	r12d, DWORD PTR tv13650[rsp]
	mov	r13, QWORD PTR tv13646[rsp]
	mov	rbx, QWORD PTR tv13640[rsp]
	mov	rsi, QWORD PTR tv13649[rsp]
	mov	rbp, QWORD PTR tv13659[rsp]
	mov	r9d, DWORD PTR tv13632[rsp]
$LC79@main:

; 190  : 	{
; 191  : 		for (col=0; col<imgWidth;col++)

	cmp	edi, r14d
	jge	SHORT $LN17@main
	mov	r10, QWORD PTR imgData$1$[rsp]
	lea	eax, DWORD PTR [r12+rdi]
	lea	ecx, DWORD PTR [rax+rax*2]
	lea	eax, DWORD PTR [r9+r12]
	movsxd	r8, ecx
	add	eax, edi
	mov	ecx, r14d
	lea	rdx, QWORD PTR [r10+1]
	add	r8, rdx
	sub	r10, rdx
	lea	eax, DWORD PTR [rax*4+8]
	movsxd	r9, eax
	mov	rax, QWORD PTR imgFloatRes$1$[rsp]
	add	rax, 8
	sub	ecx, edi
	lea	r9, QWORD PTR [rax+r9*4]
$LC22@main:
	lea	r8, QWORD PTR [r8+3]

; 192  : 		{
; 193  : 			int pixel_src = ((row+2)*imgWidth + col+2)*4;
; 194  : 			int pixel_dst = (row*imgWidth + col)*3;
; 195  : 			*(imgData+pixel_dst+0) = (ILubyte)(*(imgFloatWrite+pixel_src+0));

	vcvttss2si eax, DWORD PTR [r9-8]
	mov	BYTE PTR [r8+r10-3], al

; 196  : 			*(imgData+pixel_dst+1) = (ILubyte)(*(imgFloatWrite+pixel_src+1));

	vcvttss2si eax, DWORD PTR [r9-4]
	mov	BYTE PTR [r8-3], al

; 197  : 			*(imgData+pixel_dst+2) = (ILubyte)(*(imgFloatWrite+pixel_src+2));

	vcvttss2si eax, DWORD PTR [r9]
	mov	BYTE PTR [r8-2], al
	lea	r9, QWORD PTR [r9+16]
	sub	rcx, 1
	jne	SHORT $LC22@main
$LN17@main:

; 179  : 
; 180  : 
; 181  : 
; 182  : 	float *imgFloatWrite;
; 183  : 	imgFloatWrite = imgFloatRes;
; 184  : 
; 185  : //---------------------------------------------------------------------------------------
; 186  : // IMAGE PROCESSING END
; 187  : 
; 188  : 
; 189  : 	for (row=0; row<imgHeight; row++)

	add	r13, QWORD PTR tv13672[rsp]
	lea	rax, QWORD PTR [rbp*4]
	mov	r10, QWORD PTR tv13754[rsp]
	lea	r9d, DWORD PTR [r14+r14]
	add	rbx, rax
	mov	QWORD PTR tv13646[rsp], r13
	mov	rax, QWORD PTR tv13637[rsp]
	add	r12d, r14d
	add	r15, rbp
	mov	DWORD PTR tv13650[rsp], r12d
	sub	rsi, 1
	mov	QWORD PTR tv13645[rsp], r15
	mov	QWORD PTR tv13649[rsp], rsi
	mov	QWORD PTR tv13640[rsp], rbx
	jne	$LL19@main
	mov	rbx, QWORD PTR imgFloat$1$[rsp]
	mov	r13, QWORD PTR imgData$1$[rsp]
$LN18@main:

; 198  : 		}
; 199  : 	}
; 200  : 
; 201  : 
; 202  : 	_aligned_free(imgFloat);

	mov	rcx, rbx
	call	_aligned_free

; 203  :     _aligned_free(imgFloatRes);

	mov	rcx, QWORD PTR imgFloatRes$1$[rsp]
	call	_aligned_free

; 204  : 
; 205  : 	ret = ilSetData(imgData);

	mov	rcx, r13
	call	QWORD PTR __imp_ilSetData

; 206  : 	ilEnable(IL_FILE_OVERWRITE);

	mov	ecx, 1568				; 00000620H
	call	QWORD PTR __imp_ilEnable

; 207  :     //ilSaveImage((const char*)("output.jpg"));
; 208  :     ilSaveImage((const char*)("output.bmp"));				// tesztel�shez

	lea	rcx, OFFSET FLAT:??_C@_0L@OICGFOEL@output?4bmp?$AA@
	call	QWORD PTR __imp_ilSaveImage

; 209  : 	ilDeleteImages(1, &ilImg);

	lea	rdx, QWORD PTR ilImg$[rsp]
	mov	ecx, 1
	call	QWORD PTR __imp_ilDeleteImages

; 210  : 
; 211  : 	verifyImage();

	call	?verifyImage@@YAHXZ			; verifyImage

; 212  : 
; 213  : #endif
; 214  : }

	mov	r12, QWORD PTR [rsp+672]
	xor	eax, eax
	mov	rcx, QWORD PTR __$ArrayPad$[rsp]
	xor	rcx, rsp
	call	__security_check_cookie
	lea	r11, QWORD PTR [rsp+624]
	mov	rbx, QWORD PTR [r11+56]
	mov	rbp, QWORD PTR [r11+64]
	mov	rsp, r11
	pop	r15
	pop	r14
	pop	r13
	pop	rdi
	pop	rsi
	ret	0
main	ENDP
_TEXT	ENDS
END
