; Listing generated by Microsoft (R) Optimizing Compiler Version 19.14.26430.0 

include listing.inc

INCLUDELIB OLDNAMES

PUBLIC	??_C@_09HDLCNAPM@input?4jpg?$AA@		; `string'
PUBLIC	??_C@_0BL@EIJCCJGD@Input?5resolution?3?5?$CF4dx?$CF4d?6?$AA@ ; `string'
PUBLIC	??_C@_0BD@NGKMKCMP@C?5CPU?5TIME?3?5?$CF4?44f?6?$AA@ ; `string'
PUBLIC	??_C@_0BD@CKJPLJHO@C?5Mpixel?1s?3?5?$CF4?44f?6?$AA@ ; `string'
PUBLIC	??_C@_0L@DMOPMCBB@output?4jpg?$AA@		; `string'
EXTRN	__imp_ilGenImages:PROC
EXTRN	__imp_ilGetInteger:PROC
EXTRN	__imp_ilGetData:PROC
EXTRN	__imp_ilBindImage:PROC
EXTRN	__imp_ilInit:PROC
EXTRN	__stdio_common_vfprintf:PROC
EXTRN	__imp_iluInit:PROC
EXTRN	_aligned_malloc:PROC
EXTRN	__imp_ilDeleteImages:PROC
EXTRN	__imp_ilLoadImage:PROC
EXTRN	__acrt_iob_func:PROC
EXTRN	__imp_ilSetData:PROC
EXTRN	__imp_ilEnable:PROC
EXTRN	__imp_ilSaveImage:PROC
EXTRN	clock:PROC
EXTRN	_aligned_free:PROC
;	COMDAT ??_C@_0L@DMOPMCBB@output?4jpg?$AA@
CONST	SEGMENT
??_C@_0L@DMOPMCBB@output?4jpg?$AA@ DB 'output.jpg', 00H	; `string'
CONST	ENDS
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
PUBLIC	main
PUBLIC	printf
PUBLIC	_vfprintf_l
PUBLIC	__local_stdio_printf_options
PUBLIC	?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA ; `__local_stdio_printf_options'::`2'::_OptionsStorage
;	COMDAT ?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA
_BSS	SEGMENT
?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA DQ 01H DUP (?) ; `__local_stdio_printf_options'::`2'::_OptionsStorage
_BSS	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$main DD	imagerel $LN102@main
	DD	imagerel $LN102@main+37
	DD	imagerel $unwind$main
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$0$main DD imagerel $LN102@main+37
	DD	imagerel $LN102@main+303
	DD	imagerel $chain$0$main
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$2$main DD imagerel $LN102@main+303
	DD	imagerel $LN102@main+1543
	DD	imagerel $chain$2$main
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$3$main DD imagerel $LN102@main+1543
	DD	imagerel $LN102@main+2249
	DD	imagerel $chain$3$main
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$printf DD imagerel $LN6@printf
	DD	imagerel $LN6@printf+83
	DD	imagerel $unwind$printf
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$_vfprintf_l DD imagerel $LN4@vfprintf_l
	DD	imagerel $LN4@vfprintf_l+67
	DD	imagerel $unwind$_vfprintf_l
pdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$_vfprintf_l DD 060f01H
	DD	09640fH
	DD	08340fH
	DD	0700b520fH
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$printf DD 041b01H
	DD	07017521bH
	DD	030156016H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$3$main DD 040021H
	DD	02ff400H
	DD	02ee400H
	DD	imagerel $LN102@main
	DD	imagerel $LN102@main+37
	DD	imagerel $unwind$main
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$2$main DD 041021H
	DD	02ff410H
	DD	02ee408H
	DD	imagerel $LN102@main+37
	DD	imagerel $LN102@main+303
	DD	imagerel $chain$0$main
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$0$main DD 020921H
	DD	0136809H
	DD	imagerel $LN102@main
	DD	imagerel $LN102@main+37
	DD	imagerel $unwind$main
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$main DD	092519H
	DD	0303413H
	DD	0280113H
	DD	0c00ad00cH
	DD	060077008H
	DD	05006H
	DD	imagerel __GSHandlerCheck
	DD	0120H
END
