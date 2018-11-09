; Listing generated by Microsoft (R) Optimizing Compiler Version 19.14.26430.0 

	TITLE	D:\D_Strabi\D Dokumentumai\BME\Heterog�n sz�m�t�si rendszerek\HF\Kismacska\Hetero_HW_2\_src\sorter.cpp
	.686P
	.XMM
	include listing.inc
	.model	flat

INCLUDELIB LIBCMTD
INCLUDELIB OLDNAMES

PUBLIC	?odd_even_sort@@YAXPAM@Z			; odd_even_sort
PUBLIC	?oddEvenSort@@YAXPAEH@Z				; oddEvenSort
EXTRN	__RTC_InitBase:PROC
EXTRN	__RTC_Shutdown:PROC
EXTRN	__fltused:DWORD
;	COMDAT rtc$TMZ
rtc$TMZ	SEGMENT
__RTC_Shutdown.rtc$TMZ DD FLAT:__RTC_Shutdown
rtc$TMZ	ENDS
;	COMDAT rtc$IMZ
rtc$IMZ	SEGMENT
__RTC_InitBase.rtc$IMZ DD FLAT:__RTC_InitBase
rtc$IMZ	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hw_2\_src\sorter.cpp
;	COMDAT ?oddEvenSort@@YAXPAEH@Z
_TEXT	SEGMENT
_i$1 = -44						; size = 4
_i$2 = -32						; size = 4
_temp$ = -20						; size = 4
_isSorted$ = -5						; size = 1
_arr$ = 8						; size = 4
_n$ = 12						; size = 4
?oddEvenSort@@YAXPAEH@Z PROC				; oddEvenSort, COMDAT

; 209  : {

	push	ebp
	mov	ebp, esp
	sub	esp, 240				; 000000f0H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-240]
	mov	ecx, 60					; 0000003cH
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 210  : 	bool isSorted = false; // Initially array is unsorted 

	mov	BYTE PTR _isSorted$[ebp], 0

; 211  : 	float temp = 0.0f;

	xorps	xmm0, xmm0
	movss	DWORD PTR _temp$[ebp], xmm0
$LN2@oddEvenSor:

; 212  : 	while (!isSorted)

	movzx	eax, BYTE PTR _isSorted$[ebp]
	test	eax, eax
	jne	$LN3@oddEvenSor

; 213  : 	{
; 214  : 		isSorted = true;

	mov	BYTE PTR _isSorted$[ebp], 1

; 215  : 
; 216  : 		// Perform Bubble sort on odd indexed element 
; 217  : 		for (int i = 1; i <= n - 2; i = i + 2)

	mov	DWORD PTR _i$2[ebp], 1
	jmp	SHORT $LN6@oddEvenSor
$LN4@oddEvenSor:
	mov	eax, DWORD PTR _i$2[ebp]
	add	eax, 2
	mov	DWORD PTR _i$2[ebp], eax
$LN6@oddEvenSor:
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, 2
	cmp	DWORD PTR _i$2[ebp], eax
	jg	SHORT $LN5@oddEvenSor

; 218  : 		{
; 219  : 			if (arr[i] > arr[i + 1])

	mov	eax, DWORD PTR _arr$[ebp]
	add	eax, DWORD PTR _i$2[ebp]
	movzx	ecx, BYTE PTR [eax]
	mov	edx, DWORD PTR _arr$[ebp]
	add	edx, DWORD PTR _i$2[ebp]
	movzx	eax, BYTE PTR [edx+1]
	cmp	ecx, eax
	jle	SHORT $LN10@oddEvenSor

; 220  : 			{
; 221  : 				SWAP(arr[i], arr[i + 1]);

	mov	eax, DWORD PTR _arr$[ebp]
	add	eax, DWORD PTR _i$2[ebp]
	movzx	ecx, BYTE PTR [eax]
	cvtsi2ss xmm0, ecx
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _arr$[ebp]
	add	eax, DWORD PTR _i$2[ebp]
	mov	ecx, DWORD PTR _arr$[ebp]
	add	ecx, DWORD PTR _i$2[ebp]
	mov	dl, BYTE PTR [ecx+1]
	mov	BYTE PTR [eax], dl
	cvttss2si eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _arr$[ebp]
	add	ecx, DWORD PTR _i$2[ebp]
	mov	BYTE PTR [ecx+1], al

; 222  : 				isSorted = false;

	mov	BYTE PTR _isSorted$[ebp], 0
$LN10@oddEvenSor:

; 223  : 			}
; 224  : 		}

	jmp	SHORT $LN4@oddEvenSor
$LN5@oddEvenSor:

; 225  : 
; 226  : 		// Perform Bubble sort on even indexed element 
; 227  : 		for (int i = 0; i <= n - 2; i = i + 2)

	mov	DWORD PTR _i$1[ebp], 0
	jmp	SHORT $LN9@oddEvenSor
$LN7@oddEvenSor:
	mov	eax, DWORD PTR _i$1[ebp]
	add	eax, 2
	mov	DWORD PTR _i$1[ebp], eax
$LN9@oddEvenSor:
	mov	eax, DWORD PTR _n$[ebp]
	sub	eax, 2
	cmp	DWORD PTR _i$1[ebp], eax
	jg	SHORT $LN8@oddEvenSor

; 228  : 		{
; 229  : 			if (arr[i] > arr[i + 1])

	mov	eax, DWORD PTR _arr$[ebp]
	add	eax, DWORD PTR _i$1[ebp]
	movzx	ecx, BYTE PTR [eax]
	mov	edx, DWORD PTR _arr$[ebp]
	add	edx, DWORD PTR _i$1[ebp]
	movzx	eax, BYTE PTR [edx+1]
	cmp	ecx, eax
	jle	SHORT $LN11@oddEvenSor

; 230  : 			{
; 231  : 				SWAP(arr[i], arr[i + 1]);

	mov	eax, DWORD PTR _arr$[ebp]
	add	eax, DWORD PTR _i$1[ebp]
	movzx	ecx, BYTE PTR [eax]
	cvtsi2ss xmm0, ecx
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _arr$[ebp]
	add	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _arr$[ebp]
	add	ecx, DWORD PTR _i$1[ebp]
	mov	dl, BYTE PTR [ecx+1]
	mov	BYTE PTR [eax], dl
	cvttss2si eax, DWORD PTR _temp$[ebp]
	mov	ecx, DWORD PTR _arr$[ebp]
	add	ecx, DWORD PTR _i$1[ebp]
	mov	BYTE PTR [ecx+1], al

; 232  : 				isSorted = false;

	mov	BYTE PTR _isSorted$[ebp], 0
$LN11@oddEvenSor:

; 233  : 			}
; 234  : 		}

	jmp	SHORT $LN7@oddEvenSor
$LN8@oddEvenSor:

; 235  : 	}

	jmp	$LN2@oddEvenSor
$LN3@oddEvenSor:

; 236  : 
; 237  : 	return;
; 238  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?oddEvenSort@@YAXPAEH@Z ENDP				; oddEvenSort
_TEXT	ENDS
; Function compile flags: /Odtp /RTCsu /ZI
; File d:\d_strabi\d dokumentumai\bme\heterog�n sz�m�t�si rendszerek\hf\kismacska\hetero_hw_2\_src\sorter.cpp
;	COMDAT ?odd_even_sort@@YAXPAM@Z
_TEXT	SEGMENT
_i$1 = -176						; size = 4
_i$2 = -164						; size = 4
_i$3 = -152						; size = 4
_i$4 = -140						; size = 4
_i$5 = -128						; size = 4
_i$6 = -116						; size = 4
_i$7 = -104						; size = 4
_i$8 = -92						; size = 4
_i$9 = -80						; size = 4
_i$10 = -68						; size = 4
_i$11 = -56						; size = 4
_i$12 = -44						; size = 4
_i$13 = -32						; size = 4
_i$14 = -20						; size = 4
_temp$ = -8						; size = 4
_data$ = 8						; size = 4
?odd_even_sort@@YAXPAM@Z PROC				; odd_even_sort, COMDAT

; 11   : {

	push	ebp
	mov	ebp, esp
	sub	esp, 372				; 00000174H
	push	ebx
	push	esi
	push	edi
	lea	edi, DWORD PTR [ebp-372]
	mov	ecx, 93					; 0000005dH
	mov	eax, -858993460				; ccccccccH
	rep stosd

; 12   : 	/*printf("Sorter called\n");*/
; 13   : 	float temp = 0.0f;

	xorps	xmm0, xmm0
	movss	DWORD PTR _temp$[ebp], xmm0

; 14   : 
; 15   : 	for (int i = 1; i < 24; i += 2) {

	mov	DWORD PTR _i$14[ebp], 1
	jmp	SHORT $LN4@odd_even_s
$LN2@odd_even_s:
	mov	eax, DWORD PTR _i$14[ebp]
	add	eax, 2
	mov	DWORD PTR _i$14[ebp], eax
$LN4@odd_even_s:
	cmp	DWORD PTR _i$14[ebp], 24		; 00000018H
	jge	SHORT $LN3@odd_even_s

; 16   : 		if (data[i] > data[i + 1])

	mov	eax, DWORD PTR _i$14[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$14[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+4]
	jbe	SHORT $LN44@odd_even_s

; 17   : 		{
; 18   : 			SWAP(data[i], data[i + 1]);

	mov	eax, DWORD PTR _i$14[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$14[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$14[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+4]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$14[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+4], xmm0
$LN44@odd_even_s:

; 19   : 		}
; 20   : 	}

	jmp	SHORT $LN2@odd_even_s
$LN3@odd_even_s:

; 21   : 
; 22   : 	for (int i = 1; i < 22; i += 4) {

	mov	DWORD PTR _i$13[ebp], 1
	jmp	SHORT $LN7@odd_even_s
$LN5@odd_even_s:
	mov	eax, DWORD PTR _i$13[ebp]
	add	eax, 4
	mov	DWORD PTR _i$13[ebp], eax
$LN7@odd_even_s:
	cmp	DWORD PTR _i$13[ebp], 22		; 00000016H
	jge	$LN6@odd_even_s

; 23   : 		if (data[i] > data[i + 2])

	mov	eax, DWORD PTR _i$13[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$13[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+8]
	jbe	SHORT $LN45@odd_even_s

; 24   : 		{
; 25   : 			SWAP(data[i], data[i + 2]);

	mov	eax, DWORD PTR _i$13[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$13[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$13[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+8]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$13[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+8], xmm0
$LN45@odd_even_s:

; 26   : 		}
; 27   : 		if (data[i + 1] > data[i + 3])

	mov	eax, DWORD PTR _i$13[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$13[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	comiss	xmm0, DWORD PTR [esi+edx*4+12]
	jbe	SHORT $LN46@odd_even_s

; 28   : 		{
; 29   : 			SWAP(data[i + 1], data[i + 3]);

	mov	eax, DWORD PTR _i$13[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$13[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$13[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+12]
	mov	DWORD PTR [ecx+eax*4+4], edx
	mov	eax, DWORD PTR _i$13[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+12], xmm0
$LN46@odd_even_s:

; 30   : 		}
; 31   : 	}

	jmp	$LN5@odd_even_s
$LN6@odd_even_s:

; 32   : 
; 33   : 	for (int i = 2; i < 23; i += 4) {

	mov	DWORD PTR _i$12[ebp], 2
	jmp	SHORT $LN10@odd_even_s
$LN8@odd_even_s:
	mov	eax, DWORD PTR _i$12[ebp]
	add	eax, 4
	mov	DWORD PTR _i$12[ebp], eax
$LN10@odd_even_s:
	cmp	DWORD PTR _i$12[ebp], 23		; 00000017H
	jge	SHORT $LN9@odd_even_s

; 34   : 		if (data[i] > data[i + 1])

	mov	eax, DWORD PTR _i$12[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$12[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+4]
	jbe	SHORT $LN47@odd_even_s

; 35   : 		{
; 36   : 			SWAP(data[i], data[i + 1]);

	mov	eax, DWORD PTR _i$12[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$12[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$12[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+4]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$12[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+4], xmm0
$LN47@odd_even_s:

; 37   : 		}
; 38   : 	}

	jmp	SHORT $LN8@odd_even_s
$LN9@odd_even_s:

; 39   : 
; 40   : 	for (int i = 1; i < 22; i += 8) {

	mov	DWORD PTR _i$11[ebp], 1
	jmp	SHORT $LN13@odd_even_s
$LN11@odd_even_s:
	mov	eax, DWORD PTR _i$11[ebp]
	add	eax, 8
	mov	DWORD PTR _i$11[ebp], eax
$LN13@odd_even_s:
	cmp	DWORD PTR _i$11[ebp], 22		; 00000016H
	jge	$LN12@odd_even_s

; 41   : 		if (data[i] > data[i + 4])

	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$11[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+16]
	jbe	SHORT $LN48@odd_even_s

; 42   : 		{
; 43   : 			SWAP(data[i], data[i + 4]);

	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$11[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+16]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+16], xmm0
$LN48@odd_even_s:

; 44   : 		}
; 45   : 		if (data[i + 1] > data[i + 5])

	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$11[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	comiss	xmm0, DWORD PTR [esi+edx*4+20]
	jbe	SHORT $LN49@odd_even_s

; 46   : 		{
; 47   : 			SWAP(data[i + 1], data[i + 5]);

	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$11[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+20]
	mov	DWORD PTR [ecx+eax*4+4], edx
	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+20], xmm0
$LN49@odd_even_s:

; 48   : 		}
; 49   : 		if (data[i + 2] > data[i + 6])

	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$11[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+8]
	comiss	xmm0, DWORD PTR [esi+edx*4+24]
	jbe	SHORT $LN50@odd_even_s

; 50   : 		{
; 51   : 			SWAP(data[i + 2], data[i + 6]);

	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+8]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$11[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+24]
	mov	DWORD PTR [ecx+eax*4+8], edx
	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+24], xmm0
$LN50@odd_even_s:

; 52   : 		}
; 53   : 		if (data[i + 3] > data[i + 7])

	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$11[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+12]
	comiss	xmm0, DWORD PTR [esi+edx*4+28]
	jbe	SHORT $LN51@odd_even_s

; 54   : 		{
; 55   : 			SWAP(data[i + 3], data[i + 7]);

	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+12]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$11[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+28]
	mov	DWORD PTR [ecx+eax*4+12], edx
	mov	eax, DWORD PTR _i$11[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+28], xmm0
$LN51@odd_even_s:

; 56   : 		}
; 57   : 
; 58   : 
; 59   : 	}

	jmp	$LN11@odd_even_s
$LN12@odd_even_s:

; 60   : 
; 61   : 	for (int i = 3; i < 22; i += 8) {

	mov	DWORD PTR _i$10[ebp], 3
	jmp	SHORT $LN16@odd_even_s
$LN14@odd_even_s:
	mov	eax, DWORD PTR _i$10[ebp]
	add	eax, 8
	mov	DWORD PTR _i$10[ebp], eax
$LN16@odd_even_s:
	cmp	DWORD PTR _i$10[ebp], 22		; 00000016H
	jge	$LN15@odd_even_s

; 62   : 		if (data[i] > data[i + 2])

	mov	eax, DWORD PTR _i$10[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$10[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+8]
	jbe	SHORT $LN52@odd_even_s

; 63   : 		{
; 64   : 			SWAP(data[i], data[i + 2]);

	mov	eax, DWORD PTR _i$10[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$10[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$10[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+8]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$10[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+8], xmm0
$LN52@odd_even_s:

; 65   : 		}
; 66   : 		if (data[i + 1] > data[i + 3])

	mov	eax, DWORD PTR _i$10[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$10[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	comiss	xmm0, DWORD PTR [esi+edx*4+12]
	jbe	SHORT $LN53@odd_even_s

; 67   : 		{
; 68   : 			SWAP(data[i + 1], data[i + 3]);

	mov	eax, DWORD PTR _i$10[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$10[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$10[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+12]
	mov	DWORD PTR [ecx+eax*4+4], edx
	mov	eax, DWORD PTR _i$10[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+12], xmm0
$LN53@odd_even_s:

; 69   : 		}
; 70   : 	}

	jmp	$LN14@odd_even_s
$LN15@odd_even_s:

; 71   : 
; 72   : 	for (int i = 2; i < 22; i += 8) {

	mov	DWORD PTR _i$9[ebp], 2
	jmp	SHORT $LN19@odd_even_s
$LN17@odd_even_s:
	mov	eax, DWORD PTR _i$9[ebp]
	add	eax, 8
	mov	DWORD PTR _i$9[ebp], eax
$LN19@odd_even_s:
	cmp	DWORD PTR _i$9[ebp], 22			; 00000016H
	jge	$LN18@odd_even_s

; 73   : 		if (data[i] > data[i + 1])

	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$9[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+4]
	jbe	SHORT $LN54@odd_even_s

; 74   : 		{
; 75   : 			SWAP(data[i], data[i + 1]);

	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$9[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+4]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+4], xmm0
$LN54@odd_even_s:

; 76   : 		}
; 77   : 		if (data[i + 2] > data[i + 3])

	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$9[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+8]
	comiss	xmm0, DWORD PTR [esi+edx*4+12]
	jbe	SHORT $LN55@odd_even_s

; 78   : 		{
; 79   : 			SWAP(data[i + 2], data[i + 3]);

	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+8]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$9[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+12]
	mov	DWORD PTR [ecx+eax*4+8], edx
	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+12], xmm0
$LN55@odd_even_s:

; 80   : 		}
; 81   : 		if (data[i + 4] > data[i + 5])

	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$9[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+16]
	comiss	xmm0, DWORD PTR [esi+edx*4+20]
	jbe	SHORT $LN56@odd_even_s

; 82   : 		{
; 83   : 			SWAP(data[i + 4], data[i + 5]);

	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+16]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$9[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+20]
	mov	DWORD PTR [ecx+eax*4+16], edx
	mov	eax, DWORD PTR _i$9[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+20], xmm0
$LN56@odd_even_s:

; 84   : 		}
; 85   : 	}

	jmp	$LN17@odd_even_s
$LN18@odd_even_s:

; 86   : 
; 87   : 	if (data[0] > data[8])

	mov	eax, 4
	imul	ecx, eax, 0
	mov	edx, 4
	shl	edx, 3
	mov	eax, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [eax+ecx]
	comiss	xmm0, DWORD PTR [esi+edx]
	jbe	SHORT $LN57@odd_even_s

; 88   : 	{
; 89   : 		SWAP(data[0], data[8]);

	mov	eax, 4
	imul	ecx, eax, 0
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	shl	eax, 3
	mov	ecx, 4
	imul	edx, ecx, 0
	mov	ecx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	eax, DWORD PTR [esi+eax]
	mov	DWORD PTR [ecx+edx], eax
	mov	eax, 4
	shl	eax, 3
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax], xmm0
$LN57@odd_even_s:

; 90   : 	}
; 91   : 
; 92   : 	for (int i = 9; i < 17; i++) {

	mov	DWORD PTR _i$8[ebp], 9
	jmp	SHORT $LN22@odd_even_s
$LN20@odd_even_s:
	mov	eax, DWORD PTR _i$8[ebp]
	add	eax, 1
	mov	DWORD PTR _i$8[ebp], eax
$LN22@odd_even_s:
	cmp	DWORD PTR _i$8[ebp], 17			; 00000011H
	jge	SHORT $LN21@odd_even_s

; 93   : 		if (data[i] > data[i + 8])

	mov	eax, DWORD PTR _i$8[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$8[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+32]
	jbe	SHORT $LN58@odd_even_s

; 94   : 		{
; 95   : 			SWAP(data[i], data[i + 8]);

	mov	eax, DWORD PTR _i$8[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$8[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$8[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+32]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$8[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+32], xmm0
$LN58@odd_even_s:

; 96   : 		}
; 97   : 	}

	jmp	SHORT $LN20@odd_even_s
$LN21@odd_even_s:

; 98   : 
; 99   : 	if (data[0] > data[4])

	mov	eax, 4
	imul	ecx, eax, 0
	mov	edx, 4
	shl	edx, 2
	mov	eax, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [eax+ecx]
	comiss	xmm0, DWORD PTR [esi+edx]
	jbe	SHORT $LN59@odd_even_s

; 100  : 	{
; 101  : 		SWAP(data[0], data[4]);

	mov	eax, 4
	imul	ecx, eax, 0
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	shl	eax, 2
	mov	ecx, 4
	imul	edx, ecx, 0
	mov	ecx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	eax, DWORD PTR [esi+eax]
	mov	DWORD PTR [ecx+edx], eax
	mov	eax, 4
	shl	eax, 2
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax], xmm0
$LN59@odd_even_s:

; 102  : 	}
; 103  : 
; 104  : 	for (int i = 13; i < 17; i++) {

	mov	DWORD PTR _i$7[ebp], 13			; 0000000dH
	jmp	SHORT $LN25@odd_even_s
$LN23@odd_even_s:
	mov	eax, DWORD PTR _i$7[ebp]
	add	eax, 1
	mov	DWORD PTR _i$7[ebp], eax
$LN25@odd_even_s:
	cmp	DWORD PTR _i$7[ebp], 17			; 00000011H
	jge	SHORT $LN24@odd_even_s

; 105  : 		if (data[i] > data[i + 4])

	mov	eax, DWORD PTR _i$7[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$7[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+16]
	jbe	SHORT $LN60@odd_even_s

; 106  : 		{
; 107  : 			SWAP(data[i], data[i + 4]);

	mov	eax, DWORD PTR _i$7[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$7[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$7[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+16]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$7[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+16], xmm0
$LN60@odd_even_s:

; 108  : 		}
; 109  : 	}

	jmp	SHORT $LN23@odd_even_s
$LN24@odd_even_s:

; 110  : 
; 111  : 	if (data[0] > data[2])

	mov	eax, 4
	imul	ecx, eax, 0
	mov	edx, 4
	shl	edx, 1
	mov	eax, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [eax+ecx]
	comiss	xmm0, DWORD PTR [esi+edx]
	jbe	SHORT $LN61@odd_even_s

; 112  : 	{
; 113  : 		SWAP(data[0], data[2]);

	mov	eax, 4
	imul	ecx, eax, 0
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	shl	eax, 1
	mov	ecx, 4
	imul	edx, ecx, 0
	mov	ecx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	eax, DWORD PTR [esi+eax]
	mov	DWORD PTR [ecx+edx], eax
	mov	eax, 4
	shl	eax, 1
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax], xmm0
$LN61@odd_even_s:

; 114  : 	}
; 115  : 
; 116  : 	if (data[3] > data[5])

	mov	eax, 4
	imul	ecx, eax, 3
	mov	edx, 4
	imul	eax, edx, 5
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	comiss	xmm0, DWORD PTR [esi+eax]
	jbe	SHORT $LN62@odd_even_s

; 117  : 	{
; 118  : 		SWAP(data[3], data[5]);

	mov	eax, 4
	imul	ecx, eax, 3
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	imul	ecx, eax, 5
	mov	edx, 4
	imul	eax, edx, 3
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	ecx, DWORD PTR [esi+ecx]
	mov	DWORD PTR [edx+eax], ecx
	mov	eax, 4
	imul	ecx, eax, 5
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [edx+ecx], xmm0
$LN62@odd_even_s:

; 119  : 	}
; 120  : 
; 121  : 	if (data[4] > data[6])

	mov	eax, 4
	shl	eax, 2
	mov	ecx, 4
	imul	edx, ecx, 6
	mov	ecx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax]
	comiss	xmm0, DWORD PTR [esi+edx]
	jbe	SHORT $LN63@odd_even_s

; 122  : 	{
; 123  : 		SWAP(data[4], data[6]);

	mov	eax, 4
	shl	eax, 2
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	imul	ecx, eax, 6
	mov	edx, 4
	shl	edx, 2
	mov	eax, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	ecx, DWORD PTR [esi+ecx]
	mov	DWORD PTR [eax+edx], ecx
	mov	eax, 4
	imul	ecx, eax, 6
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [edx+ecx], xmm0
$LN63@odd_even_s:

; 124  : 	}
; 125  : 
; 126  : 	for (int i = 11; i < 20; i += 4) {

	mov	DWORD PTR _i$6[ebp], 11			; 0000000bH
	jmp	SHORT $LN28@odd_even_s
$LN26@odd_even_s:
	mov	eax, DWORD PTR _i$6[ebp]
	add	eax, 4
	mov	DWORD PTR _i$6[ebp], eax
$LN28@odd_even_s:
	cmp	DWORD PTR _i$6[ebp], 20			; 00000014H
	jge	$LN27@odd_even_s

; 127  : 		if (data[i] > data[i + 2])

	mov	eax, DWORD PTR _i$6[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$6[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+8]
	jbe	SHORT $LN64@odd_even_s

; 128  : 		{
; 129  : 			SWAP(data[i], data[i + 2]);

	mov	eax, DWORD PTR _i$6[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$6[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$6[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+8]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$6[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+8], xmm0
$LN64@odd_even_s:

; 130  : 		}
; 131  : 		if (data[i + 1] > data[i + 3])

	mov	eax, DWORD PTR _i$6[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$6[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	comiss	xmm0, DWORD PTR [esi+edx*4+12]
	jbe	SHORT $LN65@odd_even_s

; 132  : 		{
; 133  : 			SWAP(data[i + 1], data[i + 3]);

	mov	eax, DWORD PTR _i$6[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$6[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$6[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+12]
	mov	DWORD PTR [ecx+eax*4+4], edx
	mov	eax, DWORD PTR _i$6[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+12], xmm0
$LN65@odd_even_s:

; 134  : 		}
; 135  : 	}

	jmp	$LN26@odd_even_s
$LN27@odd_even_s:

; 136  : 
; 137  : 	for (int i = 0; i < 7; i += 2) {

	mov	DWORD PTR _i$5[ebp], 0
	jmp	SHORT $LN31@odd_even_s
$LN29@odd_even_s:
	mov	eax, DWORD PTR _i$5[ebp]
	add	eax, 2
	mov	DWORD PTR _i$5[ebp], eax
$LN31@odd_even_s:
	cmp	DWORD PTR _i$5[ebp], 7
	jge	SHORT $LN30@odd_even_s

; 138  : 		if (data[i] > data[i + 1])

	mov	eax, DWORD PTR _i$5[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$5[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+4]
	jbe	SHORT $LN66@odd_even_s

; 139  : 		{
; 140  : 			SWAP(data[i], data[i + 1]);

	mov	eax, DWORD PTR _i$5[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$5[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$5[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+4]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$5[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+4], xmm0
$LN66@odd_even_s:

; 141  : 		}
; 142  : 	}

	jmp	SHORT $LN29@odd_even_s
$LN30@odd_even_s:

; 143  : 
; 144  : 	for (int i = 9; i < 23; i += 2) {

	mov	DWORD PTR _i$4[ebp], 9
	jmp	SHORT $LN34@odd_even_s
$LN32@odd_even_s:
	mov	eax, DWORD PTR _i$4[ebp]
	add	eax, 2
	mov	DWORD PTR _i$4[ebp], eax
$LN34@odd_even_s:
	cmp	DWORD PTR _i$4[ebp], 23			; 00000017H
	jge	SHORT $LN33@odd_even_s

; 145  : 		if (data[i] > data[i + 1])

	mov	eax, DWORD PTR _i$4[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$4[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+4]
	jbe	SHORT $LN67@odd_even_s

; 146  : 		{
; 147  : 			SWAP(data[i], data[i + 1]);

	mov	eax, DWORD PTR _i$4[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$4[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$4[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+4]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$4[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+4], xmm0
$LN67@odd_even_s:

; 148  : 		}
; 149  : 	}

	jmp	SHORT $LN32@odd_even_s
$LN33@odd_even_s:

; 150  : 
; 151  : 	for (int i = 0; i < 8; i++) {

	mov	DWORD PTR _i$3[ebp], 0
	jmp	SHORT $LN37@odd_even_s
$LN35@odd_even_s:
	mov	eax, DWORD PTR _i$3[ebp]
	add	eax, 1
	mov	DWORD PTR _i$3[ebp], eax
$LN37@odd_even_s:
	cmp	DWORD PTR _i$3[ebp], 8
	jge	SHORT $LN36@odd_even_s

; 152  : 		if (data[i] > data[i + 16])

	mov	eax, DWORD PTR _i$3[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$3[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+64]
	jbe	SHORT $LN68@odd_even_s

; 153  : 		{
; 154  : 			SWAP(data[i], data[i + 16]);

	mov	eax, DWORD PTR _i$3[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$3[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$3[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+64]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$3[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+64], xmm0
$LN68@odd_even_s:

; 155  : 		}
; 156  : 	}

	jmp	SHORT $LN35@odd_even_s
$LN36@odd_even_s:

; 157  : 
; 158  : 	for (int i = 1; i < 9; i++) {

	mov	DWORD PTR _i$2[ebp], 1
	jmp	SHORT $LN40@odd_even_s
$LN38@odd_even_s:
	mov	eax, DWORD PTR _i$2[ebp]
	add	eax, 1
	mov	DWORD PTR _i$2[ebp], eax
$LN40@odd_even_s:
	cmp	DWORD PTR _i$2[ebp], 9
	jge	SHORT $LN39@odd_even_s

; 159  : 		if (data[i] > data[i + 8])

	mov	eax, DWORD PTR _i$2[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$2[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+32]
	jbe	SHORT $LN69@odd_even_s

; 160  : 		{
; 161  : 			SWAP(data[i], data[i + 8]);

	mov	eax, DWORD PTR _i$2[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$2[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$2[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+32]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$2[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+32], xmm0
$LN69@odd_even_s:

; 162  : 		}
; 163  : 	}

	jmp	SHORT $LN38@odd_even_s
$LN39@odd_even_s:

; 164  : 
; 165  : 	for (int i = 5; i < 16; i += 8) {

	mov	DWORD PTR _i$1[ebp], 5
	jmp	SHORT $LN43@odd_even_s
$LN41@odd_even_s:
	mov	eax, DWORD PTR _i$1[ebp]
	add	eax, 8
	mov	DWORD PTR _i$1[ebp], eax
$LN43@odd_even_s:
	cmp	DWORD PTR _i$1[ebp], 16			; 00000010H
	jge	$LN42@odd_even_s

; 166  : 		if (data[i] > data[i + 4])

	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$1[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	comiss	xmm0, DWORD PTR [esi+edx*4+16]
	jbe	SHORT $LN70@odd_even_s

; 167  : 		{
; 168  : 			SWAP(data[i], data[i + 4]);

	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$1[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+16]
	mov	DWORD PTR [ecx+eax*4], edx
	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+16], xmm0
$LN70@odd_even_s:

; 169  : 		}
; 170  : 		if (data[i + 1] > data[i + 5])

	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$1[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	comiss	xmm0, DWORD PTR [esi+edx*4+20]
	jbe	SHORT $LN71@odd_even_s

; 171  : 		{
; 172  : 			SWAP(data[i + 1], data[i + 5]);

	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+4]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$1[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+20]
	mov	DWORD PTR [ecx+eax*4+4], edx
	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+20], xmm0
$LN71@odd_even_s:

; 173  : 		}
; 174  : 		if (data[i + 2] > data[i + 6])

	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$1[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+8]
	comiss	xmm0, DWORD PTR [esi+edx*4+24]
	jbe	SHORT $LN72@odd_even_s

; 175  : 		{
; 176  : 			SWAP(data[i + 2], data[i + 6]);

	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+8]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$1[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+24]
	mov	DWORD PTR [ecx+eax*4+8], edx
	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+24], xmm0
$LN72@odd_even_s:

; 177  : 		}
; 178  : 		if (data[i + 3] > data[i + 7])

	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$1[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+12]
	comiss	xmm0, DWORD PTR [esi+edx*4+28]
	jbe	SHORT $LN73@odd_even_s

; 179  : 		{
; 180  : 			SWAP(data[i + 3], data[i + 7]);

	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax*4+12]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR _i$1[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	edx, DWORD PTR [esi+edx*4+28]
	mov	DWORD PTR [ecx+eax*4+12], edx
	mov	eax, DWORD PTR _i$1[ebp]
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [ecx+eax*4+28], xmm0
$LN73@odd_even_s:

; 181  : 		}
; 182  : 	}

	jmp	$LN41@odd_even_s
$LN42@odd_even_s:

; 183  : 
; 184  : 	if (data[11] > data[13])

	mov	eax, 4
	imul	ecx, eax, 11
	mov	edx, 4
	imul	eax, edx, 13
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	comiss	xmm0, DWORD PTR [esi+eax]
	jbe	SHORT $LN74@odd_even_s

; 185  : 	{
; 186  : 		SWAP(data[11], data[13]);

	mov	eax, 4
	imul	ecx, eax, 11
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	imul	ecx, eax, 13
	mov	edx, 4
	imul	eax, edx, 11
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	ecx, DWORD PTR [esi+ecx]
	mov	DWORD PTR [edx+eax], ecx
	mov	eax, 4
	imul	ecx, eax, 13
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [edx+ecx], xmm0
$LN74@odd_even_s:

; 187  : 	}
; 188  : 	if (data[12] > data[14])

	mov	eax, 4
	imul	ecx, eax, 12
	mov	edx, 4
	imul	eax, edx, 14
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	comiss	xmm0, DWORD PTR [esi+eax]
	jbe	SHORT $LN75@odd_even_s

; 189  : 	{
; 190  : 		SWAP(data[12], data[14]);

	mov	eax, 4
	imul	ecx, eax, 12
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	imul	ecx, eax, 14
	mov	edx, 4
	imul	eax, edx, 12
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	ecx, DWORD PTR [esi+ecx]
	mov	DWORD PTR [edx+eax], ecx
	mov	eax, 4
	imul	ecx, eax, 14
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [edx+ecx], xmm0
$LN75@odd_even_s:

; 191  : 	}
; 192  : 	if (data[12] > data[13])

	mov	eax, 4
	imul	ecx, eax, 12
	mov	edx, 4
	imul	eax, edx, 13
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	comiss	xmm0, DWORD PTR [esi+eax]
	jbe	SHORT $LN76@odd_even_s

; 193  : 	{
; 194  : 		SWAP(data[12], data[13]);

	mov	eax, 4
	imul	ecx, eax, 12
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	imul	ecx, eax, 13
	mov	edx, 4
	imul	eax, edx, 12
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	ecx, DWORD PTR [esi+ecx]
	mov	DWORD PTR [edx+eax], ecx
	mov	eax, 4
	imul	ecx, eax, 13
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [edx+ecx], xmm0
$LN76@odd_even_s:

; 195  : 	}
; 196  : 
; 197  : 	if (data[10] > data[12])

	mov	eax, 4
	imul	ecx, eax, 10
	mov	edx, 4
	imul	eax, edx, 12
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	comiss	xmm0, DWORD PTR [esi+eax]
	jbe	SHORT $LN77@odd_even_s

; 198  : 	{
; 199  : 		SWAP(data[10], data[12]);

	mov	eax, 4
	imul	ecx, eax, 10
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [edx+ecx]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	imul	ecx, eax, 12
	mov	edx, 4
	imul	eax, edx, 10
	mov	edx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	ecx, DWORD PTR [esi+ecx]
	mov	DWORD PTR [edx+eax], ecx
	mov	eax, 4
	imul	ecx, eax, 12
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [edx+ecx], xmm0
$LN77@odd_even_s:

; 200  : 	}
; 201  : 	if (data[8] > data[12])

	mov	eax, 4
	shl	eax, 3
	mov	ecx, 4
	imul	edx, ecx, 12
	mov	ecx, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax]
	comiss	xmm0, DWORD PTR [esi+edx]
	jbe	SHORT $LN78@odd_even_s

; 202  : 	{
; 203  : 		SWAP(data[8], data[12]);

	mov	eax, 4
	shl	eax, 3
	mov	ecx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR [ecx+eax]
	movss	DWORD PTR _temp$[ebp], xmm0
	mov	eax, 4
	imul	ecx, eax, 12
	mov	edx, 4
	shl	edx, 3
	mov	eax, DWORD PTR _data$[ebp]
	mov	esi, DWORD PTR _data$[ebp]
	mov	ecx, DWORD PTR [esi+ecx]
	mov	DWORD PTR [eax+edx], ecx
	mov	eax, 4
	imul	ecx, eax, 12
	mov	edx, DWORD PTR _data$[ebp]
	movss	xmm0, DWORD PTR _temp$[ebp]
	movss	DWORD PTR [edx+ecx], xmm0
$LN78@odd_even_s:

; 204  : 	}
; 205  : }

	pop	edi
	pop	esi
	pop	ebx
	mov	esp, ebp
	pop	ebp
	ret	0
?odd_even_sort@@YAXPAM@Z ENDP				; odd_even_sort
_TEXT	ENDS
END