; Listing generated by Microsoft (R) Optimizing Compiler Version 19.23.28106.4 

include listing.inc

INCLUDELIB MSVCRT
INCLUDELIB OLDNAMES

PUBLIC	?set@MAT4@DATA@XGK@@3P6AXPEAXMMMMMMMMMMMMMMMM@ZEA ; XGK::DATA::MAT4::set
PUBLIC	?premul@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA		; XGK::DATA::MAT4::premul
PUBLIC	?postmul@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA		; XGK::DATA::MAT4::postmul
PUBLIC	?makeTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA	; XGK::DATA::MAT4::makeTrans
PUBLIC	?preTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA		; XGK::DATA::MAT4::preTrans
PUBLIC	?postTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA	; XGK::DATA::MAT4::postTrans
PUBLIC	?makeTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA	; XGK::DATA::MAT4::makeTransValue
PUBLIC	?preTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA	; XGK::DATA::MAT4::preTransValue
PUBLIC	?postTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA	; XGK::DATA::MAT4::postTransValue
PUBLIC	?makeRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA	; XGK::DATA::MAT4::makeRotQuat
PUBLIC	?preRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA	; XGK::DATA::MAT4::preRotQuat
PUBLIC	?postRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA	; XGK::DATA::MAT4::postRotQuat
PUBLIC	?transp@MAT4@DATA@XGK@@3P6AXPEAX@ZEA		; XGK::DATA::MAT4::transp
PUBLIC	?invns@MAT4@DATA@XGK@@3P6AXPEAX@ZEA		; XGK::DATA::MAT4::invns
PUBLIC	?makeProjPersp@MAT4@DATA@XGK@@3P6AXPEAXMMMMM@ZEA ; XGK::DATA::MAT4::makeProjPersp
_BSS	SEGMENT
?set@MAT4@DATA@XGK@@3P6AXPEAXMMMMMMMMMMMMMMMM@ZEA DQ 01H DUP (?) ; XGK::DATA::MAT4::set
?premul@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA DQ 01H DUP (?)	; XGK::DATA::MAT4::premul
?postmul@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA DQ 01H DUP (?)	; XGK::DATA::MAT4::postmul
?makeTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA DQ 01H DUP (?)	; XGK::DATA::MAT4::makeTrans
?preTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA DQ 01H DUP (?)	; XGK::DATA::MAT4::preTrans
?postTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA DQ 01H DUP (?)	; XGK::DATA::MAT4::postTrans
?makeTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA DQ 01H DUP (?) ; XGK::DATA::MAT4::makeTransValue
?preTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA DQ 01H DUP (?) ; XGK::DATA::MAT4::preTransValue
?postTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA DQ 01H DUP (?) ; XGK::DATA::MAT4::postTransValue
?makeRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA DQ 01H DUP (?) ; XGK::DATA::MAT4::makeRotQuat
?preRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA DQ 01H DUP (?) ; XGK::DATA::MAT4::preRotQuat
?postRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA DQ 01H DUP (?) ; XGK::DATA::MAT4::postRotQuat
?transp@MAT4@DATA@XGK@@3P6AXPEAX@ZEA DQ 01H DUP (?)	; XGK::DATA::MAT4::transp
?invns@MAT4@DATA@XGK@@3P6AXPEAX@ZEA DQ 01H DUP (?)	; XGK::DATA::MAT4::invns
?makeProjPersp@MAT4@DATA@XGK@@3P6AXPEAXMMMMM@ZEA DQ 01H DUP (?) ; XGK::DATA::MAT4::makeProjPersp
_BSS	ENDS
CONST	SEGMENT
?IDENT@MAT4@DATA@XGK@@3QBMB DD 03f800000r	; 1	; XGK::DATA::MAT4::IDENT
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	03f800000r			; 1
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	03f800000r			; 1
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	000000000r			; 0
	DD	03f800000r			; 1
CONST	ENDS
PUBLIC	__local_stdio_printf_options
PUBLIC	_vfprintf_l
PUBLIC	printf
PUBLIC	?copy@MAT4@DATA@XGK@@YAXPEAX0@Z			; XGK::DATA::MAT4::copy
PUBLIC	?reset@MAT4@DATA@XGK@@YAXPEAX@Z			; XGK::DATA::MAT4::reset
PUBLIC	?ident@MAT4@DATA@XGK@@YAXPEAX@Z			; XGK::DATA::MAT4::ident
PUBLIC	?simd32@MAT4@DATA@XGK@@YAXXZ			; XGK::DATA::MAT4::simd32
PUBLIC	?simd128@MAT4@DATA@XGK@@YAXXZ			; XGK::DATA::MAT4::simd128
PUBLIC	?print@MAT4@DATA@XGK@@YAXPEAX@Z			; XGK::DATA::MAT4::print
PUBLIC	?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA ; `__local_stdio_printf_options'::`2'::_OptionsStorage
PUBLIC	??_C@_0N@MDOCIACE@?$CFf?5?$CFf?5?$CFf?5?$CFf?6@	; `string'
EXTRN	__imp___acrt_iob_func:PROC
EXTRN	__imp___stdio_common_vfprintf:PROC
EXTRN	?set32@MAT4@DATA@XGK@@YAXPEAXMMMMMMMMMMMMMMMM@Z:PROC ; XGK::DATA::MAT4::set32
EXTRN	?premul32@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::premul32
EXTRN	?postmul32@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::postmul32
EXTRN	?makeTrans32@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::makeTrans32
EXTRN	?preTrans32@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::preTrans32
EXTRN	?postTrans32@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::postTrans32
EXTRN	?makeTransValue32@MAT4@DATA@XGK@@YAXPEAX0M@Z:PROC ; XGK::DATA::MAT4::makeTransValue32
EXTRN	?preTransValue32@MAT4@DATA@XGK@@YAXPEAX0M@Z:PROC ; XGK::DATA::MAT4::preTransValue32
EXTRN	?postTransValue32@MAT4@DATA@XGK@@YAXPEAX0M@Z:PROC ; XGK::DATA::MAT4::postTransValue32
EXTRN	?makeRotQuat32@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::makeRotQuat32
EXTRN	?preRotQuat32@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::preRotQuat32
EXTRN	?postRotQuat32@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::postRotQuat32
EXTRN	?transp32@MAT4@DATA@XGK@@YAXPEAX@Z:PROC		; XGK::DATA::MAT4::transp32
EXTRN	?invns32@MAT4@DATA@XGK@@YAXPEAX@Z:PROC		; XGK::DATA::MAT4::invns32
EXTRN	?makeProjPersp32@MAT4@DATA@XGK@@YAXPEAXMMMMM@Z:PROC ; XGK::DATA::MAT4::makeProjPersp32
EXTRN	?set128@MAT4@DATA@XGK@@YAXPEAXMMMMMMMMMMMMMMMM@Z:PROC ; XGK::DATA::MAT4::set128
EXTRN	?premul128@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::premul128
EXTRN	?postmul128@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::postmul128
EXTRN	?makeTrans128@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::makeTrans128
EXTRN	?preTrans128@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::preTrans128
EXTRN	?postTrans128@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::postTrans128
EXTRN	?makeTransValue128@MAT4@DATA@XGK@@YAXPEAX0M@Z:PROC ; XGK::DATA::MAT4::makeTransValue128
EXTRN	?preTransValue128@MAT4@DATA@XGK@@YAXPEAX0M@Z:PROC ; XGK::DATA::MAT4::preTransValue128
EXTRN	?postTransValue128@MAT4@DATA@XGK@@YAXPEAX0M@Z:PROC ; XGK::DATA::MAT4::postTransValue128
EXTRN	?makeRotQuat128@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::makeRotQuat128
EXTRN	?preRotQuat128@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::preRotQuat128
EXTRN	?postRotQuat128@MAT4@DATA@XGK@@YAXPEAX0@Z:PROC	; XGK::DATA::MAT4::postRotQuat128
EXTRN	?transp128@MAT4@DATA@XGK@@YAXPEAX@Z:PROC	; XGK::DATA::MAT4::transp128
EXTRN	?invns128@MAT4@DATA@XGK@@YAXPEAX@Z:PROC		; XGK::DATA::MAT4::invns128
EXTRN	?makeProjPersp128@MAT4@DATA@XGK@@YAXPEAXMMMMM@Z:PROC ; XGK::DATA::MAT4::makeProjPersp128
EXTRN	_fltused:DWORD
;	COMDAT ?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA
_BSS	SEGMENT
?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA DQ 01H DUP (?) ; `__local_stdio_printf_options'::`2'::_OptionsStorage
_BSS	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$_vfprintf_l DD imagerel $LN4
	DD	imagerel $LN4+81
	DD	imagerel $unwind$_vfprintf_l
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$printf DD imagerel $LN6
	DD	imagerel $LN6+85
	DD	imagerel $unwind$printf
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?print@MAT4@DATA@XGK@@YAXPEAX@Z DD imagerel $LN4
	DD	imagerel $LN4+274
	DD	imagerel $unwind$?print@MAT4@DATA@XGK@@YAXPEAX@Z
pdata	ENDS
;	COMDAT ??_C@_0N@MDOCIACE@?$CFf?5?$CFf?5?$CFf?5?$CFf?6@
CONST	SEGMENT
??_C@_0N@MDOCIACE@?$CFf?5?$CFf?5?$CFf?5?$CFf?6@ DB '%f %f %f %f', 0aH, 00H ; `string'
CONST	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?print@MAT4@DATA@XGK@@YAXPEAX@Z DD 020601H
	DD	030025206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$printf DD 041b01H
	DD	07017521bH
	DD	030156016H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$_vfprintf_l DD 081401H
	DD	0a6414H
	DD	095414H
	DD	083414H
	DD	070105214H
xdata	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?print@MAT4@DATA@XGK@@YAXPEAX@Z
_TEXT	SEGMENT
data$ = 64
?print@MAT4@DATA@XGK@@YAXPEAX@Z PROC			; XGK::DATA::MAT4::print, COMDAT
; File E:\reps\denis-belov\xgk\src\data\mat4\mat4.cpp
; Line 140
$LN4:
	push	rbx
	sub	rsp, 48					; 00000030H
	movss	xmm3, DWORD PTR [rcx+32]
	mov	rbx, rcx
	movss	xmm2, DWORD PTR [rcx+16]
	movss	xmm1, DWORD PTR [rcx]
	movss	xmm0, DWORD PTR [rcx+48]
; Line 144
	lea	rcx, OFFSET FLAT:??_C@_0N@MDOCIACE@?$CFf?5?$CFf?5?$CFf?5?$CFf?6@
	cvtps2pd xmm3, xmm3
	cvtps2pd xmm2, xmm2
	cvtps2pd xmm1, xmm1
	cvtps2pd xmm0, xmm0
	movq	r9, xmm3
	movq	r8, xmm2
	movq	rdx, xmm1
	movsd	QWORD PTR [rsp+32], xmm0
	call	printf
	movss	xmm3, DWORD PTR [rbx+36]
; Line 145
	lea	rcx, OFFSET FLAT:??_C@_0N@MDOCIACE@?$CFf?5?$CFf?5?$CFf?5?$CFf?6@
	movss	xmm2, DWORD PTR [rbx+20]
	movss	xmm1, DWORD PTR [rbx+4]
	movss	xmm0, DWORD PTR [rbx+52]
	cvtps2pd xmm3, xmm3
	cvtps2pd xmm2, xmm2
	cvtps2pd xmm1, xmm1
	cvtps2pd xmm0, xmm0
	movq	r9, xmm3
	movq	r8, xmm2
	movq	rdx, xmm1
	movsd	QWORD PTR [rsp+32], xmm0
	call	printf
	movss	xmm3, DWORD PTR [rbx+40]
; Line 146
	lea	rcx, OFFSET FLAT:??_C@_0N@MDOCIACE@?$CFf?5?$CFf?5?$CFf?5?$CFf?6@
	movss	xmm2, DWORD PTR [rbx+24]
	movss	xmm1, DWORD PTR [rbx+8]
	movss	xmm0, DWORD PTR [rbx+56]
	cvtps2pd xmm3, xmm3
	cvtps2pd xmm2, xmm2
	cvtps2pd xmm1, xmm1
	cvtps2pd xmm0, xmm0
	movq	r9, xmm3
	movq	r8, xmm2
	movq	rdx, xmm1
	movsd	QWORD PTR [rsp+32], xmm0
	call	printf
	movss	xmm3, DWORD PTR [rbx+44]
; Line 147
	lea	rcx, OFFSET FLAT:??_C@_0N@MDOCIACE@?$CFf?5?$CFf?5?$CFf?5?$CFf?6@
	movss	xmm2, DWORD PTR [rbx+28]
	movss	xmm1, DWORD PTR [rbx+12]
	movss	xmm0, DWORD PTR [rbx+60]
	cvtps2pd xmm3, xmm3
	cvtps2pd xmm2, xmm2
	cvtps2pd xmm1, xmm1
	cvtps2pd xmm0, xmm0
	movq	r9, xmm3
	movq	r8, xmm2
	movq	rdx, xmm1
	movsd	QWORD PTR [rsp+32], xmm0
	call	printf
; Line 148
	add	rsp, 48					; 00000030H
	pop	rbx
	ret	0
?print@MAT4@DATA@XGK@@YAXPEAX@Z ENDP			; XGK::DATA::MAT4::print
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?simd128@MAT4@DATA@XGK@@YAXXZ
_TEXT	SEGMENT
?simd128@MAT4@DATA@XGK@@YAXXZ PROC			; XGK::DATA::MAT4::simd128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\mat4\mat4.cpp
; Line 119
	lea	rax, OFFSET FLAT:?set128@MAT4@DATA@XGK@@YAXPEAXMMMMMMMMMMMMMMMM@Z ; XGK::DATA::MAT4::set128
	mov	QWORD PTR ?set@MAT4@DATA@XGK@@3P6AXPEAXMMMMMMMMMMMMMMMM@ZEA, rax ; XGK::DATA::MAT4::set
; Line 120
	lea	rax, OFFSET FLAT:?premul128@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::premul128
	mov	QWORD PTR ?premul@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::premul
; Line 121
	lea	rax, OFFSET FLAT:?postmul128@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::postmul128
	mov	QWORD PTR ?postmul@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::postmul
; Line 122
	lea	rax, OFFSET FLAT:?makeTrans128@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::makeTrans128
	mov	QWORD PTR ?makeTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::makeTrans
; Line 123
	lea	rax, OFFSET FLAT:?preTrans128@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::preTrans128
	mov	QWORD PTR ?preTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::preTrans
; Line 124
	lea	rax, OFFSET FLAT:?postTrans128@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::postTrans128
	mov	QWORD PTR ?postTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::postTrans
; Line 125
	lea	rax, OFFSET FLAT:?makeTransValue128@MAT4@DATA@XGK@@YAXPEAX0M@Z ; XGK::DATA::MAT4::makeTransValue128
	mov	QWORD PTR ?makeTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA, rax ; XGK::DATA::MAT4::makeTransValue
; Line 126
	lea	rax, OFFSET FLAT:?preTransValue128@MAT4@DATA@XGK@@YAXPEAX0M@Z ; XGK::DATA::MAT4::preTransValue128
	mov	QWORD PTR ?preTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA, rax ; XGK::DATA::MAT4::preTransValue
; Line 127
	lea	rax, OFFSET FLAT:?postTransValue128@MAT4@DATA@XGK@@YAXPEAX0M@Z ; XGK::DATA::MAT4::postTransValue128
	mov	QWORD PTR ?postTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA, rax ; XGK::DATA::MAT4::postTransValue
; Line 128
	lea	rax, OFFSET FLAT:?makeRotQuat128@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::makeRotQuat128
	mov	QWORD PTR ?makeRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::makeRotQuat
; Line 129
	lea	rax, OFFSET FLAT:?preRotQuat128@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::preRotQuat128
	mov	QWORD PTR ?preRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::preRotQuat
; Line 130
	lea	rax, OFFSET FLAT:?postRotQuat128@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::postRotQuat128
	mov	QWORD PTR ?postRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::postRotQuat
; Line 131
	lea	rax, OFFSET FLAT:?transp128@MAT4@DATA@XGK@@YAXPEAX@Z ; XGK::DATA::MAT4::transp128
	mov	QWORD PTR ?transp@MAT4@DATA@XGK@@3P6AXPEAX@ZEA, rax ; XGK::DATA::MAT4::transp
; Line 132
	lea	rax, OFFSET FLAT:?invns128@MAT4@DATA@XGK@@YAXPEAX@Z ; XGK::DATA::MAT4::invns128
	mov	QWORD PTR ?invns@MAT4@DATA@XGK@@3P6AXPEAX@ZEA, rax ; XGK::DATA::MAT4::invns
; Line 133
	lea	rax, OFFSET FLAT:?makeProjPersp128@MAT4@DATA@XGK@@YAXPEAXMMMMM@Z ; XGK::DATA::MAT4::makeProjPersp128
	mov	QWORD PTR ?makeProjPersp@MAT4@DATA@XGK@@3P6AXPEAXMMMMM@ZEA, rax ; XGK::DATA::MAT4::makeProjPersp
; Line 134
	ret	0
?simd128@MAT4@DATA@XGK@@YAXXZ ENDP			; XGK::DATA::MAT4::simd128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?simd32@MAT4@DATA@XGK@@YAXXZ
_TEXT	SEGMENT
?simd32@MAT4@DATA@XGK@@YAXXZ PROC			; XGK::DATA::MAT4::simd32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\mat4\mat4.cpp
; Line 100
	lea	rax, OFFSET FLAT:?set32@MAT4@DATA@XGK@@YAXPEAXMMMMMMMMMMMMMMMM@Z ; XGK::DATA::MAT4::set32
	mov	QWORD PTR ?set@MAT4@DATA@XGK@@3P6AXPEAXMMMMMMMMMMMMMMMM@ZEA, rax ; XGK::DATA::MAT4::set
; Line 101
	lea	rax, OFFSET FLAT:?premul32@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::premul32
	mov	QWORD PTR ?premul@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::premul
; Line 102
	lea	rax, OFFSET FLAT:?postmul32@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::postmul32
	mov	QWORD PTR ?postmul@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::postmul
; Line 103
	lea	rax, OFFSET FLAT:?makeTrans32@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::makeTrans32
	mov	QWORD PTR ?makeTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::makeTrans
; Line 104
	lea	rax, OFFSET FLAT:?preTrans32@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::preTrans32
	mov	QWORD PTR ?preTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::preTrans
; Line 105
	lea	rax, OFFSET FLAT:?postTrans32@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::postTrans32
	mov	QWORD PTR ?postTrans@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::postTrans
; Line 106
	lea	rax, OFFSET FLAT:?makeTransValue32@MAT4@DATA@XGK@@YAXPEAX0M@Z ; XGK::DATA::MAT4::makeTransValue32
	mov	QWORD PTR ?makeTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA, rax ; XGK::DATA::MAT4::makeTransValue
; Line 107
	lea	rax, OFFSET FLAT:?preTransValue32@MAT4@DATA@XGK@@YAXPEAX0M@Z ; XGK::DATA::MAT4::preTransValue32
	mov	QWORD PTR ?preTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA, rax ; XGK::DATA::MAT4::preTransValue
; Line 108
	lea	rax, OFFSET FLAT:?postTransValue32@MAT4@DATA@XGK@@YAXPEAX0M@Z ; XGK::DATA::MAT4::postTransValue32
	mov	QWORD PTR ?postTransValue@MAT4@DATA@XGK@@3P6AXPEAX0M@ZEA, rax ; XGK::DATA::MAT4::postTransValue
; Line 109
	lea	rax, OFFSET FLAT:?makeRotQuat32@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::makeRotQuat32
	mov	QWORD PTR ?makeRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::makeRotQuat
; Line 110
	lea	rax, OFFSET FLAT:?preRotQuat32@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::preRotQuat32
	mov	QWORD PTR ?preRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::preRotQuat
; Line 111
	lea	rax, OFFSET FLAT:?postRotQuat32@MAT4@DATA@XGK@@YAXPEAX0@Z ; XGK::DATA::MAT4::postRotQuat32
	mov	QWORD PTR ?postRotQuat@MAT4@DATA@XGK@@3P6AXPEAX0@ZEA, rax ; XGK::DATA::MAT4::postRotQuat
; Line 112
	lea	rax, OFFSET FLAT:?transp32@MAT4@DATA@XGK@@YAXPEAX@Z ; XGK::DATA::MAT4::transp32
	mov	QWORD PTR ?transp@MAT4@DATA@XGK@@3P6AXPEAX@ZEA, rax ; XGK::DATA::MAT4::transp
; Line 113
	lea	rax, OFFSET FLAT:?invns32@MAT4@DATA@XGK@@YAXPEAX@Z ; XGK::DATA::MAT4::invns32
	mov	QWORD PTR ?invns@MAT4@DATA@XGK@@3P6AXPEAX@ZEA, rax ; XGK::DATA::MAT4::invns
; Line 114
	lea	rax, OFFSET FLAT:?makeProjPersp32@MAT4@DATA@XGK@@YAXPEAXMMMMM@Z ; XGK::DATA::MAT4::makeProjPersp32
	mov	QWORD PTR ?makeProjPersp@MAT4@DATA@XGK@@3P6AXPEAXMMMMM@ZEA, rax ; XGK::DATA::MAT4::makeProjPersp
; Line 115
	ret	0
?simd32@MAT4@DATA@XGK@@YAXXZ ENDP			; XGK::DATA::MAT4::simd32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?ident@MAT4@DATA@XGK@@YAXPEAX@Z
_TEXT	SEGMENT
data$ = 8
?ident@MAT4@DATA@XGK@@YAXPEAX@Z PROC			; XGK::DATA::MAT4::ident, COMDAT
; File E:\reps\denis-belov\xgk\src\data\mat4\mat4.cpp
; Line 93
	movaps	xmm0, XMMWORD PTR ?IDENT@MAT4@DATA@XGK@@3QBMB
	movups	XMMWORD PTR [rcx], xmm0
	movaps	xmm1, XMMWORD PTR ?IDENT@MAT4@DATA@XGK@@3QBMB+16
	movups	XMMWORD PTR [rcx+16], xmm1
	movaps	xmm0, XMMWORD PTR ?IDENT@MAT4@DATA@XGK@@3QBMB+32
	movups	XMMWORD PTR [rcx+32], xmm0
	movaps	xmm1, XMMWORD PTR ?IDENT@MAT4@DATA@XGK@@3QBMB+48
	movups	XMMWORD PTR [rcx+48], xmm1
; Line 94
	ret	0
?ident@MAT4@DATA@XGK@@YAXPEAX@Z ENDP			; XGK::DATA::MAT4::ident
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?reset@MAT4@DATA@XGK@@YAXPEAX@Z
_TEXT	SEGMENT
data$ = 8
?reset@MAT4@DATA@XGK@@YAXPEAX@Z PROC			; XGK::DATA::MAT4::reset, COMDAT
; File E:\reps\denis-belov\xgk\src\data\mat4\mat4.cpp
; Line 84
	xorps	xmm0, xmm0
; Line 86
	movups	XMMWORD PTR [rcx], xmm0
	movups	XMMWORD PTR [rcx+16], xmm0
	movups	XMMWORD PTR [rcx+32], xmm0
	movups	XMMWORD PTR [rcx+48], xmm0
; Line 87
	ret	0
?reset@MAT4@DATA@XGK@@YAXPEAX@Z ENDP			; XGK::DATA::MAT4::reset
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?copy@MAT4@DATA@XGK@@YAXPEAX0@Z
_TEXT	SEGMENT
data0$ = 8
data1$ = 16
?copy@MAT4@DATA@XGK@@YAXPEAX0@Z PROC			; XGK::DATA::MAT4::copy, COMDAT
; File E:\reps\denis-belov\xgk\src\data\mat4\mat4.cpp
; Line 79
	movups	xmm0, XMMWORD PTR [rdx]
	movups	XMMWORD PTR [rcx], xmm0
	movups	xmm1, XMMWORD PTR [rdx+16]
	movups	XMMWORD PTR [rcx+16], xmm1
	movups	xmm0, XMMWORD PTR [rdx+32]
	movups	XMMWORD PTR [rcx+32], xmm0
	movups	xmm1, XMMWORD PTR [rdx+48]
	movups	XMMWORD PTR [rcx+48], xmm1
; Line 80
	ret	0
?copy@MAT4@DATA@XGK@@YAXPEAX0@Z ENDP			; XGK::DATA::MAT4::copy
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT printf
_TEXT	SEGMENT
_Format$ = 80
printf	PROC						; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.18362.0\ucrt\stdio.h
; Line 954
$LN6:
	mov	QWORD PTR [rsp+8], rcx
	mov	QWORD PTR [rsp+16], rdx
	mov	QWORD PTR [rsp+24], r8
	mov	QWORD PTR [rsp+32], r9
	push	rbx
	push	rsi
	push	rdi
	sub	rsp, 48					; 00000030H
	mov	rdi, rcx
; Line 957
	lea	rsi, QWORD PTR _Format$[rsp+8]
; Line 958
	mov	ecx, 1
	call	QWORD PTR __imp___acrt_iob_func
	mov	rbx, rax
; Line 643
	call	__local_stdio_printf_options
	xor	r9d, r9d
	mov	QWORD PTR [rsp+32], rsi
	mov	r8, rdi
	mov	rdx, rbx
	mov	rcx, QWORD PTR [rax]
	call	QWORD PTR __imp___stdio_common_vfprintf
; Line 961
	add	rsp, 48					; 00000030H
	pop	rdi
	pop	rsi
	pop	rbx
	ret	0
printf	ENDP
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT _vfprintf_l
_TEXT	SEGMENT
_Stream$ = 64
_Format$ = 72
_Locale$ = 80
_ArgList$ = 88
_vfprintf_l PROC					; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.18362.0\ucrt\stdio.h
; Line 642
$LN4:
	mov	QWORD PTR [rsp+8], rbx
	mov	QWORD PTR [rsp+16], rbp
	mov	QWORD PTR [rsp+24], rsi
	push	rdi
	sub	rsp, 48					; 00000030H
	mov	rbx, r9
	mov	rdi, r8
	mov	rsi, rdx
	mov	rbp, rcx
; Line 643
	call	__local_stdio_printf_options
	mov	r9, rdi
	mov	QWORD PTR [rsp+32], rbx
	mov	r8, rsi
	mov	rdx, rbp
	mov	rcx, QWORD PTR [rax]
	call	QWORD PTR __imp___stdio_common_vfprintf
; Line 644
	mov	rbx, QWORD PTR [rsp+64]
	mov	rbp, QWORD PTR [rsp+72]
	mov	rsi, QWORD PTR [rsp+80]
	add	rsp, 48					; 00000030H
	pop	rdi
	ret	0
_vfprintf_l ENDP
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT __local_stdio_printf_options
_TEXT	SEGMENT
__local_stdio_printf_options PROC			; COMDAT
; File C:\Program Files (x86)\Windows Kits\10\include\10.0.18362.0\ucrt\corecrt_stdio_config.h
; Line 88
	lea	rax, OFFSET FLAT:?_OptionsStorage@?1??__local_stdio_printf_options@@9@4_KA ; `__local_stdio_printf_options'::`2'::_OptionsStorage
; Line 89
	ret	0
__local_stdio_printf_options ENDP
_TEXT	ENDS
END
