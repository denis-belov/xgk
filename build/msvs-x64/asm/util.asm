; Listing generated by Microsoft (R) Optimizing Compiler Version 19.23.28106.4 

include listing.inc

INCLUDELIB MSVCRT
INCLUDELIB OLDNAMES

PUBLIC	?makeBezierCurve3Point@UTIL@XGK@@YAXMMMMMMMMMPEAM@Z ; XGK::UTIL::makeBezierCurve3Point
PUBLIC	?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z ; XGK::UTIL::makeBezierCurve3Sequence
PUBLIC	?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z ; XGK::UTIL::makeBezierCurve3Sequence2
PUBLIC	__real@3f800000
PUBLIC	__real@40400000
EXTRN	_fltused:DWORD
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeBezierCurve3Point@UTIL@XGK@@YAXMMMMMMMMMPEAM@Z DD imagerel $LN4
	DD	imagerel $LN4+311
	DD	imagerel $unwind$?makeBezierCurve3Point@UTIL@XGK@@YAXMMMMMMMMMPEAM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z DD imagerel $LN20
	DD	imagerel $LN20+42
	DD	imagerel $unwind$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$3$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z DD imagerel $LN20+42
	DD	imagerel $LN20+335
	DD	imagerel $chain$3$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$4$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z DD imagerel $LN20+335
	DD	imagerel $LN20+368
	DD	imagerel $chain$4$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z DD imagerel $LN20
	DD	imagerel $LN20+42
	DD	imagerel $unwind$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$2$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z DD imagerel $LN20+42
	DD	imagerel $LN20+308
	DD	imagerel $chain$2$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$3$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z DD imagerel $LN20+308
	DD	imagerel $LN20+341
	DD	imagerel $chain$3$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z
pdata	ENDS
;	COMDAT __real@40400000
CONST	SEGMENT
__real@40400000 DD 040400000r			; 3
CONST	ENDS
;	COMDAT __real@3f800000
CONST	SEGMENT
__real@3f800000 DD 03f800000r			; 1
CONST	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$3$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z DD 021H
	DD	imagerel $LN20
	DD	imagerel $LN20+42
	DD	imagerel $unwind$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$2$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z DD 061321H
	DD	028813H
	DD	03780dH
	DD	046805H
	DD	imagerel $LN20
	DD	imagerel $LN20+42
	DD	imagerel $unwind$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z DD 051d01H
	DD	0a81dH
	DD	019814H
	DD	0a204H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$4$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z DD 021H
	DD	imagerel $LN20
	DD	imagerel $LN20+42
	DD	imagerel $unwind$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$chain$3$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z DD 081921H
	DD	029819H
	DD	038813H
	DD	04780dH
	DD	056805H
	DD	imagerel $LN20
	DD	imagerel $LN20+42
	DD	imagerel $unwind$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z DD 051d01H
	DD	0b81dH
	DD	01a814H
	DD	0c204H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeBezierCurve3Point@UTIL@XGK@@YAXMMMMMMMMMPEAM@Z DD 0126b01H
	DD	0d86bH
	DD	01c862H
	DD	02b85aH
	DD	03a851H
	DD	04983fH
	DD	058836H
	DD	06782dH
	DD	07681fH
	DD	011010aH
xdata	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z
_TEXT	SEGMENT
x2$ = 96
y2$ = 104
x3$ = 112
y3$ = 120
segment_count$ = 128
result$ = 136
?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z PROC ; XGK::UTIL::makeBezierCurve3Sequence2, COMDAT
; File E:\reps\denis-belov\xgk\src\util\util.cpp
; Line 73
$LN20:
	sub	rsp, 88					; 00000058H
; Line 79
	mov	r8, QWORD PTR segment_count$[rsp]
	xor	edx, edx
	movaps	XMMWORD PTR [rsp+16], xmm9
	movaps	xmm9, xmm3
	movaps	XMMWORD PTR [rsp], xmm10
	movaps	xmm10, xmm1
	test	r8, r8
	je	$LN18@makeBezier
	movaps	XMMWORD PTR [rsp+64], xmm6
	xorps	xmm5, xmm5
	movaps	XMMWORD PTR [rsp+48], xmm7
	movaps	XMMWORD PTR [rsp+32], xmm8
	js	SHORT $LN14@makeBezier
	cvtsi2ss xmm5, r8
	jmp	SHORT $LN17@makeBezier
$LN14@makeBezier:
	mov	rax, r8
	mov	rcx, r8
	shr	rcx, 1
	and	eax, 1
	or	rcx, rax
	cvtsi2ss xmm5, rcx
	addss	xmm5, xmm5
$LN17@makeBezier:
	mov	r9, QWORD PTR result$[rsp]
	xorps	xmm8, xmm8
	movss	xmm7, DWORD PTR __real@3f800000
	movss	xmm6, DWORD PTR __real@40400000
	npad	6
$LL16@makeBezier:
; Line 81
	xorps	xmm4, xmm4
	test	rdx, rdx
	js	SHORT $LN12@makeBezier
	cvtsi2ss xmm4, rdx
	jmp	SHORT $LN13@makeBezier
$LN12@makeBezier:
	mov	rax, rdx
	mov	rcx, rdx
	shr	rcx, 1
	and	eax, 1
	or	rcx, rax
	cvtsi2ss xmm4, rcx
	addss	xmm4, xmm4
$LN13@makeBezier:
	divss	xmm4, xmm5
; Line 23
	movaps	xmm1, xmm7
	subss	xmm1, xmm4
; Line 25
	movaps	xmm3, xmm4
	mulss	xmm3, xmm4
; Line 27
	movaps	xmm2, xmm4
	mulss	xmm2, xmm6
	movaps	xmm0, xmm1
	mulss	xmm0, xmm1
	mulss	xmm2, xmm0
	mulss	xmm0, xmm1
; Line 32
	mulss	xmm2, xmm10
	mulss	xmm0, xmm8
	addss	xmm2, xmm0
	movaps	xmm0, xmm3
	mulss	xmm0, xmm6
	mulss	xmm3, xmm4
	mulss	xmm0, xmm1
	mulss	xmm0, xmm9
	addss	xmm2, xmm0
	addss	xmm2, xmm3
; Line 83
	movss	DWORD PTR [r9+rdx*4], xmm2
	inc	rdx
	cmp	rdx, r8
	jb	$LL16@makeBezier
; Line 86
	movaps	xmm8, XMMWORD PTR [rsp+32]
	movaps	xmm7, XMMWORD PTR [rsp+48]
	movaps	xmm6, XMMWORD PTR [rsp+64]
	mov	DWORD PTR [r9+r8*4-4], 1065353216	; 3f800000H
; Line 87
	movaps	xmm9, XMMWORD PTR [rsp+16]
	movaps	xmm10, XMMWORD PTR [rsp]
	add	rsp, 88					; 00000058H
	ret	0
$LN18@makeBezier:
; Line 86
	mov	rax, QWORD PTR result$[rsp]
; Line 87
	movaps	xmm9, XMMWORD PTR [rsp+16]
	movaps	xmm10, XMMWORD PTR [rsp]
	mov	DWORD PTR [rax+r8*4-4], 1065353216	; 3f800000H
	add	rsp, 88					; 00000058H
	ret	0
?makeBezierCurve3Sequence2@UTIL@XGK@@YAXMMMM_KPEAM@Z ENDP ; XGK::UTIL::makeBezierCurve3Sequence2
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z
_TEXT	SEGMENT
x1$ = 112
y1$ = 120
x2$ = 128
y2$ = 136
x3$ = 144
y3$ = 152
x4$ = 160
y4$ = 168
segment_count$ = 176
result$ = 184
?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z PROC ; XGK::UTIL::makeBezierCurve3Sequence, COMDAT
; File E:\reps\denis-belov\xgk\src\util\util.cpp
; Line 48
$LN20:
	sub	rsp, 104				; 00000068H
; Line 54
	mov	r8, QWORD PTR segment_count$[rsp]
	xor	edx, edx
	movaps	XMMWORD PTR [rsp+16], xmm10
	movaps	xmm10, xmm3
	movaps	XMMWORD PTR [rsp], xmm11
	movaps	xmm11, xmm1
	test	r8, r8
	je	$LN18@makeBezier
	movaps	XMMWORD PTR [rsp+80], xmm6
	xorps	xmm5, xmm5
	movaps	XMMWORD PTR [rsp+64], xmm7
	movaps	XMMWORD PTR [rsp+48], xmm8
	movaps	XMMWORD PTR [rsp+32], xmm9
	js	SHORT $LN14@makeBezier
	cvtsi2ss xmm5, r8
	jmp	SHORT $LN17@makeBezier
$LN14@makeBezier:
	mov	rax, r8
	mov	rcx, r8
	shr	rcx, 1
	and	eax, 1
	or	rcx, rax
	cvtsi2ss xmm5, rcx
	addss	xmm5, xmm5
$LN17@makeBezier:
	mov	r9, QWORD PTR result$[rsp]
	movss	xmm7, DWORD PTR y4$[rsp]
	movss	xmm8, DWORD PTR y3$[rsp]
	movss	xmm9, DWORD PTR __real@3f800000
	movss	xmm6, DWORD PTR __real@40400000
$LL16@makeBezier:
; Line 56
	xorps	xmm4, xmm4
	test	rdx, rdx
	js	SHORT $LN12@makeBezier
	cvtsi2ss xmm4, rdx
	jmp	SHORT $LN13@makeBezier
$LN12@makeBezier:
	mov	rax, rdx
	mov	rcx, rdx
	shr	rcx, 1
	and	eax, 1
	or	rcx, rax
	cvtsi2ss xmm4, rcx
	addss	xmm4, xmm4
$LN13@makeBezier:
	divss	xmm4, xmm5
; Line 23
	movaps	xmm1, xmm9
	subss	xmm1, xmm4
; Line 25
	movaps	xmm3, xmm4
	mulss	xmm3, xmm4
; Line 27
	movaps	xmm2, xmm4
	mulss	xmm2, xmm6
	movaps	xmm0, xmm1
	mulss	xmm0, xmm1
	mulss	xmm2, xmm0
	mulss	xmm0, xmm1
; Line 32
	mulss	xmm2, xmm10
	mulss	xmm0, xmm11
	addss	xmm2, xmm0
	movaps	xmm0, xmm3
	mulss	xmm0, xmm6
	mulss	xmm3, xmm4
	mulss	xmm0, xmm1
	mulss	xmm3, xmm7
	mulss	xmm0, xmm8
	addss	xmm2, xmm0
	addss	xmm2, xmm3
; Line 58
	movss	DWORD PTR [r9+rdx*4], xmm2
	inc	rdx
	cmp	rdx, r8
	jb	$LL16@makeBezier
; Line 61
	movaps	xmm9, XMMWORD PTR [rsp+32]
	movaps	xmm8, XMMWORD PTR [rsp+48]
	movaps	xmm7, XMMWORD PTR [rsp+64]
	movaps	xmm6, XMMWORD PTR [rsp+80]
	mov	DWORD PTR [r9+r8*4-4], 1065353216	; 3f800000H
; Line 62
	movaps	xmm10, XMMWORD PTR [rsp+16]
	movaps	xmm11, XMMWORD PTR [rsp]
	add	rsp, 104				; 00000068H
	ret	0
$LN18@makeBezier:
; Line 61
	mov	rax, QWORD PTR result$[rsp]
; Line 62
	movaps	xmm10, XMMWORD PTR [rsp+16]
	movaps	xmm11, XMMWORD PTR [rsp]
	mov	DWORD PTR [rax+r8*4-4], 1065353216	; 3f800000H
	add	rsp, 104				; 00000068H
	ret	0
?makeBezierCurve3Sequence@UTIL@XGK@@YAXMMMMMMMM_KPEAM@Z ENDP ; XGK::UTIL::makeBezierCurve3Sequence
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeBezierCurve3Point@UTIL@XGK@@YAXMMMMMMMMMPEAM@Z
_TEXT	SEGMENT
x1$ = 144
y1$ = 152
x2$ = 160
y2$ = 168
x3$ = 176
y3$ = 184
x4$ = 192
y4$ = 200
t$ = 208
result$ = 216
?makeBezierCurve3Point@UTIL@XGK@@YAXMMMMMMMMMPEAM@Z PROC ; XGK::UTIL::makeBezierCurve3Point, COMDAT
; File E:\reps\denis-belov\xgk\src\util\util.cpp
; Line 21
$LN4:
	mov	r11, rsp
	sub	rsp, 136				; 00000088H
; Line 23
	movss	xmm5, DWORD PTR __real@3f800000
; Line 31
	mov	rax, QWORD PTR result$[rsp]
	movaps	XMMWORD PTR [rsp+112], xmm6
	movss	xmm6, DWORD PTR t$[rsp]
	movaps	XMMWORD PTR [rsp+96], xmm7
	subss	xmm5, xmm6
	movaps	XMMWORD PTR [r11-56], xmm8
	movaps	xmm8, xmm2
	movaps	XMMWORD PTR [r11-72], xmm9
	movaps	xmm9, xmm6
	mulss	xmm9, DWORD PTR __real@40400000
	movaps	XMMWORD PTR [r11-88], xmm10
	movaps	xmm10, xmm1
	movaps	XMMWORD PTR [r11-104], xmm11
	movaps	xmm4, xmm5
	movaps	XMMWORD PTR [r11-120], xmm12
	movaps	xmm12, xmm6
	movaps	XMMWORD PTR [rsp], xmm13
	movaps	xmm13, xmm3
; Line 33
	movaps	xmm7, XMMWORD PTR [rsp+96]
	mulss	xmm12, xmm6
	mulss	xmm4, xmm5
	movaps	xmm3, xmm12
	mulss	xmm12, xmm6
	mulss	xmm3, DWORD PTR __real@40400000
	movaps	xmm11, xmm4
	movaps	xmm6, XMMWORD PTR [rsp+112]
	mulss	xmm11, xmm5
	mulss	xmm9, xmm4
	movaps	xmm2, xmm11
	mulss	xmm3, xmm5
	mulss	xmm2, xmm0
	movaps	xmm0, xmm9
	mulss	xmm11, xmm10
	movaps	xmm1, xmm3
	mulss	xmm3, DWORD PTR y3$[rsp]
	mulss	xmm1, DWORD PTR x3$[rsp]
	movaps	xmm10, XMMWORD PTR [r11-88]
	mulss	xmm0, xmm8
	movaps	xmm8, XMMWORD PTR [r11-56]
	mulss	xmm9, xmm13
	movaps	xmm13, XMMWORD PTR [rsp]
	addss	xmm2, xmm0
	movaps	xmm0, xmm12
	mulss	xmm12, DWORD PTR y4$[rsp]
	mulss	xmm0, DWORD PTR x4$[rsp]
	addss	xmm11, xmm9
	movaps	xmm9, XMMWORD PTR [r11-72]
	addss	xmm2, xmm1
	addss	xmm11, xmm3
	addss	xmm2, xmm0
	addss	xmm11, xmm12
	movaps	xmm12, XMMWORD PTR [r11-120]
	movss	DWORD PTR [rax], xmm2
	movss	DWORD PTR [rax+4], xmm11
	movaps	xmm11, XMMWORD PTR [r11-104]
	add	rsp, 136				; 00000088H
	ret	0
?makeBezierCurve3Point@UTIL@XGK@@YAXMMMMMMMMMPEAM@Z ENDP ; XGK::UTIL::makeBezierCurve3Point
_TEXT	ENDS
END
