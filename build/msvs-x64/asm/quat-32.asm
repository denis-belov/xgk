; Listing generated by Microsoft (R) Optimizing Compiler Version 19.23.28106.4 

include listing.inc

INCLUDELIB MSVCRT
INCLUDELIB OLDNAMES

PUBLIC	?cos@@YAMM@Z					; cos
PUBLIC	?sin@@YAMM@Z					; sin
PUBLIC	?premul32@QUAT@DATA@XGK@@YAXPEAX0@Z		; XGK::DATA::QUAT::premul32
PUBLIC	?postmul32@QUAT@DATA@XGK@@YAXPEAX0@Z		; XGK::DATA::QUAT::postmul32
PUBLIC	?makeRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z		; XGK::DATA::QUAT::makeRot32
PUBLIC	?preRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z		; XGK::DATA::QUAT::preRot32
PUBLIC	?postRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z		; XGK::DATA::QUAT::postRot32
PUBLIC	?makeRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::makeRotX32
PUBLIC	?preRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::preRotX32
PUBLIC	?postRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::postRotX32
PUBLIC	?makeRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::makeRotY32
PUBLIC	?preRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::preRotY32
PUBLIC	?postRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::postRotY32
PUBLIC	?makeRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::makeRotZ32
PUBLIC	?preRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::preRotZ32
PUBLIC	?postRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::postRotZ32
PUBLIC	__real@3f000000
EXTRN	cosf:PROC
EXTRN	sinf:PROC
EXTRN	_fltused:DWORD
;	COMDAT pdata
pdata	SEGMENT
$pdata$?premul32@QUAT@DATA@XGK@@YAXPEAX0@Z DD imagerel $LN4
	DD	imagerel $LN4+225
	DD	imagerel $unwind$?premul32@QUAT@DATA@XGK@@YAXPEAX0@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postmul32@QUAT@DATA@XGK@@YAXPEAX0@Z DD imagerel $LN4
	DD	imagerel $LN4+225
	DD	imagerel $unwind$?postmul32@QUAT@DATA@XGK@@YAXPEAX0@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z DD imagerel $LN9
	DD	imagerel $LN9+103
	DD	imagerel $unwind$?makeRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?preRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z DD imagerel $LN9
	DD	imagerel $LN9+386
	DD	imagerel $unwind$?preRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z DD imagerel $LN9
	DD	imagerel $LN9+386
	DD	imagerel $unwind$?postRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+67
	DD	imagerel $unwind$?makeRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?preRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+203
	DD	imagerel $unwind$?preRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+203
	DD	imagerel $unwind$?postRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+75
	DD	imagerel $unwind$?makeRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?preRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+203
	DD	imagerel $unwind$?preRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+203
	DD	imagerel $unwind$?postRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+67
	DD	imagerel $unwind$?makeRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?preRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+200
	DD	imagerel $unwind$?preRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+200
	DD	imagerel $unwind$?postRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT __real@3f000000
CONST	SEGMENT
__real@3f000000 DD 03f000000r			; 0.5
CONST	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 0a3301H
	DD	02b833H
	DD	03a82aH
	DD	048817H
	DD	05680bH
	DD	03002b206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?preRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 0a3301H
	DD	02b833H
	DD	03a82aH
	DD	048817H
	DD	05680bH
	DD	03002b206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 040b01H
	DD	02680bH
	DD	030025206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 0a3301H
	DD	02b833H
	DD	03a82aH
	DD	049817H
	DD	05680bH
	DD	03002b206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?preRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 0a3301H
	DD	02b833H
	DD	03a82aH
	DD	049817H
	DD	05680bH
	DD	03002b206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 040b01H
	DD	02680bH
	DD	030025206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 0a3401H
	DD	02b834H
	DD	03a82bH
	DD	048817H
	DD	05680bH
	DD	03002b206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?preRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 0a3401H
	DD	02b834H
	DD	03a82bH
	DD	048817H
	DD	05680bH
	DD	03002b206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z DD 040b01H
	DD	02680bH
	DD	030025206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z DD 0154a01H
	DD	02d84aH
	DD	03c844H
	DD	04b83fH
	DD	05a837H
	DD	069832H
	DD	07882dH
	DD	08781aH
	DD	096813H
	DD	016340fH
	DD	014010fH
	DD	07008H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?preRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z DD 0154a01H
	DD	02d84aH
	DD	03c844H
	DD	04b83fH
	DD	05a837H
	DD	069832H
	DD	07882dH
	DD	08781aH
	DD	096813H
	DD	016340fH
	DD	014010fH
	DD	07008H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z DD 060f01H
	DD	02680fH
	DD	08340aH
	DD	07006520aH
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postmul32@QUAT@DATA@XGK@@YAXPEAX0@Z DD 052e01H
	DD	0782eH
	DD	016822H
	DD	04204H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?premul32@QUAT@DATA@XGK@@YAXPEAX0@Z DD 052601H
	DD	07826H
	DD	01681aH
	DD	04204H
xdata	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 112
angle$ = 120
?postRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::postRotZ32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 269
$LN9:
	push	rbx
	sub	rsp, 96					; 00000060H
	movaps	XMMWORD PTR [rsp+80], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
	movaps	XMMWORD PTR [rsp+64], xmm8
; Line 273
	mulss	xmm6, DWORD PTR __real@3f000000
; Line 275
	movss	xmm8, DWORD PTR [rcx]
	movaps	XMMWORD PTR [rsp+48], xmm10
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rsp+32], xmm11
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 277
	movss	xmm11, DWORD PTR [rcx+8]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	call	sinf
	movaps	xmm10, xmm0
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 287
	movaps	xmm6, XMMWORD PTR [rsp+80]
	movaps	xmm2, xmm10
	mulss	xmm2, DWORD PTR [rbx+4]
	movaps	xmm1, xmm0
	mulss	xmm1, xmm8
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm4, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 286
	mulss	xmm4, DWORD PTR [rbx+12]
	movaps	xmm3, xmm0
	mulss	xmm3, DWORD PTR [rbx+4]
	addss	xmm2, xmm1
	movaps	xmm1, xmm10
	mulss	xmm0, xmm11
	mulss	xmm1, xmm8
; Line 287
	movaps	xmm8, XMMWORD PTR [rsp+64]
	movss	DWORD PTR [rbx], xmm2
	movaps	xmm2, xmm10
	mulss	xmm2, DWORD PTR [rbx+12]
	subss	xmm3, xmm1
	mulss	xmm10, xmm11
	movaps	xmm11, XMMWORD PTR [rsp+32]
	addss	xmm2, xmm0
	movss	DWORD PTR [rbx+4], xmm3
	subss	xmm4, xmm10
	movaps	xmm10, XMMWORD PTR [rsp+48]
	movss	DWORD PTR [rbx+8], xmm2
	movss	DWORD PTR [rbx+12], xmm4
	add	rsp, 96					; 00000060H
	pop	rbx
	ret	0
?postRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::postRotZ32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?preRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 112
angle$ = 120
?preRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::preRotZ32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 247
$LN9:
	push	rbx
	sub	rsp, 96					; 00000060H
	movaps	XMMWORD PTR [rsp+80], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
	movaps	XMMWORD PTR [rsp+64], xmm8
; Line 251
	mulss	xmm6, DWORD PTR __real@3f000000
; Line 253
	movss	xmm8, DWORD PTR [rcx]
	movaps	XMMWORD PTR [rsp+48], xmm10
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rsp+32], xmm11
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 255
	movss	xmm11, DWORD PTR [rcx+8]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	call	sinf
	movaps	xmm10, xmm0
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 265
	movaps	xmm6, XMMWORD PTR [rsp+80]
	movaps	xmm1, xmm10
	mulss	xmm1, DWORD PTR [rbx+4]
	movaps	xmm2, xmm0
	mulss	xmm2, xmm8
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm4, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 264
	mulss	xmm4, DWORD PTR [rbx+12]
	movaps	xmm3, xmm0
	mulss	xmm3, DWORD PTR [rbx+4]
	subss	xmm2, xmm1
	movaps	xmm1, xmm10
	mulss	xmm0, xmm11
	mulss	xmm1, xmm8
; Line 265
	movaps	xmm8, XMMWORD PTR [rsp+64]
	movss	DWORD PTR [rbx], xmm2
	movaps	xmm2, xmm10
	mulss	xmm2, DWORD PTR [rbx+12]
	addss	xmm3, xmm1
	mulss	xmm10, xmm11
	movaps	xmm11, XMMWORD PTR [rsp+32]
	addss	xmm2, xmm0
	movss	DWORD PTR [rbx+4], xmm3
	subss	xmm4, xmm10
	movaps	xmm10, XMMWORD PTR [rsp+48]
	movss	DWORD PTR [rbx+8], xmm2
	movss	DWORD PTR [rbx+12], xmm4
	add	rsp, 96					; 00000060H
	pop	rbx
	ret	0
?preRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::preRotZ32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 64
angle$ = 72
?makeRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::makeRotZ32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 233
$LN9:
	push	rbx
	sub	rsp, 48					; 00000030H
	movaps	XMMWORD PTR [rsp+32], xmm6
; Line 239
	xor	eax, eax
	movaps	xmm6, xmm1
	mov	QWORD PTR [rcx], rax
	mulss	xmm6, DWORD PTR __real@3f000000
	mov	rbx, rcx
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 241
	movss	DWORD PTR [rbx+8], xmm0
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 243
	movaps	xmm6, XMMWORD PTR [rsp+32]
	movss	DWORD PTR [rbx+12], xmm0
	add	rsp, 48					; 00000030H
	pop	rbx
	ret	0
?makeRotZ32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::makeRotZ32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 112
angle$ = 120
?postRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::postRotY32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 211
$LN9:
	push	rbx
	sub	rsp, 96					; 00000060H
	movaps	XMMWORD PTR [rsp+80], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
	movaps	XMMWORD PTR [rsp+64], xmm9
; Line 215
	mulss	xmm6, DWORD PTR __real@3f000000
; Line 217
	movss	xmm9, DWORD PTR [rcx]
	movaps	XMMWORD PTR [rsp+48], xmm10
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rsp+32], xmm11
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 218
	movss	xmm11, DWORD PTR [rcx+4]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	call	sinf
	movaps	xmm10, xmm0
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 229
	movaps	xmm6, XMMWORD PTR [rsp+80]
	movaps	xmm2, xmm0
	mulss	xmm2, xmm9
	movaps	xmm1, xmm10
	mulss	xmm1, DWORD PTR [rbx+8]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm4, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 228
	mulss	xmm4, DWORD PTR [rbx+12]
	movaps	xmm3, xmm10
	mulss	xmm3, DWORD PTR [rbx+12]
	subss	xmm2, xmm1
	movaps	xmm1, xmm0
	mulss	xmm1, xmm11
	movss	DWORD PTR [rbx], xmm2
	movaps	xmm2, xmm0
	mulss	xmm2, DWORD PTR [rbx+8]
	movaps	xmm0, xmm10
	mulss	xmm10, xmm11
	addss	xmm3, xmm1
; Line 229
	movaps	xmm11, XMMWORD PTR [rsp+32]
	mulss	xmm0, xmm9
	movaps	xmm9, XMMWORD PTR [rsp+64]
	subss	xmm4, xmm10
	movaps	xmm10, XMMWORD PTR [rsp+48]
	addss	xmm2, xmm0
	movss	DWORD PTR [rbx+4], xmm3
	movss	DWORD PTR [rbx+12], xmm4
	movss	DWORD PTR [rbx+8], xmm2
	add	rsp, 96					; 00000060H
	pop	rbx
	ret	0
?postRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::postRotY32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?preRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 112
angle$ = 120
?preRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::preRotY32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 189
$LN9:
	push	rbx
	sub	rsp, 96					; 00000060H
	movaps	XMMWORD PTR [rsp+80], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
	movaps	XMMWORD PTR [rsp+64], xmm9
; Line 193
	mulss	xmm6, DWORD PTR __real@3f000000
; Line 195
	movss	xmm9, DWORD PTR [rcx]
	movaps	XMMWORD PTR [rsp+48], xmm10
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rsp+32], xmm11
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 196
	movss	xmm11, DWORD PTR [rcx+4]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	call	sinf
	movaps	xmm10, xmm0
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 207
	movaps	xmm6, XMMWORD PTR [rsp+80]
	movaps	xmm2, xmm10
	mulss	xmm2, DWORD PTR [rbx+8]
	movaps	xmm1, xmm0
	mulss	xmm1, xmm9
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm4, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 206
	mulss	xmm4, DWORD PTR [rbx+12]
	movaps	xmm3, xmm10
	mulss	xmm3, DWORD PTR [rbx+12]
	addss	xmm2, xmm1
	movaps	xmm1, xmm0
	mulss	xmm1, xmm11
	movss	DWORD PTR [rbx], xmm2
	movaps	xmm2, xmm0
	mulss	xmm2, DWORD PTR [rbx+8]
	movaps	xmm0, xmm10
	mulss	xmm10, xmm11
	addss	xmm3, xmm1
; Line 207
	movaps	xmm11, XMMWORD PTR [rsp+32]
	mulss	xmm0, xmm9
	movaps	xmm9, XMMWORD PTR [rsp+64]
	subss	xmm4, xmm10
	movaps	xmm10, XMMWORD PTR [rsp+48]
	subss	xmm2, xmm0
	movss	DWORD PTR [rbx+4], xmm3
	movss	DWORD PTR [rbx+12], xmm4
	movss	DWORD PTR [rbx+8], xmm2
	add	rsp, 96					; 00000060H
	pop	rbx
	ret	0
?preRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::preRotY32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 64
angle$ = 72
?makeRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::makeRotY32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 175
$LN9:
	push	rbx
	sub	rsp, 48					; 00000030H
	movaps	XMMWORD PTR [rsp+32], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
; Line 181
	mov	DWORD PTR [rcx], 0
	mulss	xmm6, DWORD PTR __real@3f000000
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 182
	movss	DWORD PTR [rbx+4], xmm0
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 183
	mov	DWORD PTR [rbx+8], 0
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 185
	movaps	xmm6, XMMWORD PTR [rsp+32]
	movss	DWORD PTR [rbx+12], xmm0
	add	rsp, 48					; 00000030H
	pop	rbx
	ret	0
?makeRotY32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::makeRotY32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 112
angle$ = 120
?postRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::postRotX32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 153
$LN9:
	push	rbx
	sub	rsp, 96					; 00000060H
	movaps	XMMWORD PTR [rsp+80], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
	movaps	XMMWORD PTR [rsp+64], xmm8
; Line 157
	mulss	xmm6, DWORD PTR __real@3f000000
; Line 160
	movss	xmm8, DWORD PTR [rcx+4]
	movaps	XMMWORD PTR [rsp+48], xmm10
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rsp+32], xmm11
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 159
	movss	xmm11, DWORD PTR [rcx]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	call	sinf
	movaps	xmm10, xmm0
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 171
	movaps	xmm6, XMMWORD PTR [rsp+80]
	movaps	xmm2, xmm10
	mulss	xmm2, DWORD PTR [rbx+12]
	movaps	xmm1, xmm0
	mulss	xmm1, xmm11
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm4, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 170
	mulss	xmm4, DWORD PTR [rbx+12]
	movaps	xmm3, xmm10
	mulss	xmm3, DWORD PTR [rbx+8]
	addss	xmm2, xmm1
	movaps	xmm1, xmm0
	mulss	xmm1, xmm8
	movss	DWORD PTR [rbx], xmm2
	movaps	xmm2, xmm0
	mulss	xmm2, DWORD PTR [rbx+8]
	movaps	xmm0, xmm10
	mulss	xmm10, xmm11
	addss	xmm3, xmm1
; Line 171
	movaps	xmm11, XMMWORD PTR [rsp+32]
	mulss	xmm0, xmm8
	movaps	xmm8, XMMWORD PTR [rsp+64]
	subss	xmm4, xmm10
	movaps	xmm10, XMMWORD PTR [rsp+48]
	subss	xmm2, xmm0
	movss	DWORD PTR [rbx+4], xmm3
	movss	DWORD PTR [rbx+12], xmm4
	movss	DWORD PTR [rbx+8], xmm2
	add	rsp, 96					; 00000060H
	pop	rbx
	ret	0
?postRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::postRotX32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?preRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 112
angle$ = 120
?preRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::preRotX32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 130
$LN9:
	push	rbx
	sub	rsp, 96					; 00000060H
	movaps	XMMWORD PTR [rsp+80], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
	movaps	XMMWORD PTR [rsp+64], xmm8
; Line 134
	mulss	xmm6, DWORD PTR __real@3f000000
; Line 137
	movss	xmm8, DWORD PTR [rcx+4]
	movaps	XMMWORD PTR [rsp+48], xmm10
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rsp+32], xmm11
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 136
	movss	xmm11, DWORD PTR [rcx]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	call	sinf
	movaps	xmm10, xmm0
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 149
	movaps	xmm6, XMMWORD PTR [rsp+80]
	movaps	xmm2, xmm10
	mulss	xmm2, DWORD PTR [rbx+12]
	movaps	xmm1, xmm0
	mulss	xmm1, xmm11
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm4, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 148
	mulss	xmm4, DWORD PTR [rbx+12]
	movaps	xmm3, xmm0
	addss	xmm2, xmm1
	mulss	xmm3, xmm8
	movaps	xmm1, xmm10
	mulss	xmm1, DWORD PTR [rbx+8]
	movss	DWORD PTR [rbx], xmm2
	movaps	xmm2, xmm0
	mulss	xmm2, DWORD PTR [rbx+8]
	movaps	xmm0, xmm10
	mulss	xmm10, xmm11
	subss	xmm3, xmm1
; Line 149
	movaps	xmm11, XMMWORD PTR [rsp+32]
	mulss	xmm0, xmm8
	movaps	xmm8, XMMWORD PTR [rsp+64]
	subss	xmm4, xmm10
	movaps	xmm10, XMMWORD PTR [rsp+48]
	addss	xmm2, xmm0
	movss	DWORD PTR [rbx+4], xmm3
	movss	DWORD PTR [rbx+12], xmm4
	movss	DWORD PTR [rbx+8], xmm2
	add	rsp, 96					; 00000060H
	pop	rbx
	ret	0
?preRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::preRotX32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 64
angle$ = 72
?makeRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::makeRotX32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 116
$LN9:
	push	rbx
	sub	rsp, 48					; 00000030H
	movaps	XMMWORD PTR [rsp+32], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
; Line 120
	mulss	xmm6, DWORD PTR __real@3f000000
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 122
	movss	DWORD PTR [rbx], xmm0
; Line 123
	xor	eax, eax
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 123
	mov	QWORD PTR [rbx+4], rax
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 126
	movaps	xmm6, XMMWORD PTR [rsp+32]
	movss	DWORD PTR [rbx+12], xmm0
	add	rsp, 48					; 00000030H
	pop	rbx
	ret	0
?makeRotX32@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::makeRotX32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 176
axis_addr$ = 184
angle$ = 192
?postRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z PROC		; XGK::DATA::QUAT::postRot32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 90
$LN9:
	mov	rax, rsp
	mov	QWORD PTR [rax+8], rbx
	push	rdi
	sub	rsp, 160				; 000000a0H
	movaps	XMMWORD PTR [rax-24], xmm6
	mov	rbx, rdx
	movaps	XMMWORD PTR [rax-40], xmm7
	movaps	xmm6, xmm2
; Line 95
	mulss	xmm6, DWORD PTR __real@3f000000
	mov	rdi, rcx
	movaps	XMMWORD PTR [rax-56], xmm8
	movaps	XMMWORD PTR [rax-72], xmm9
	movaps	XMMWORD PTR [rax-88], xmm10
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rax-104], xmm11
	movaps	XMMWORD PTR [rax-120], xmm12
	movaps	XMMWORD PTR [rsp+32], xmm13
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 98
	movss	xmm10, DWORD PTR [rdi]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm13, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 105
	mulss	xmm13, DWORD PTR [rbx+8]
	movaps	xmm8, xmm0
	mulss	xmm8, DWORD PTR [rbx]
	movaps	xmm9, xmm0
	mulss	xmm9, DWORD PTR [rbx+4]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 99
	movss	xmm11, DWORD PTR [rdi+4]
; Line 100
	movss	xmm12, DWORD PTR [rdi+8]
; Line 101
	movss	xmm7, DWORD PTR [rdi+12]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 108
	movaps	xmm1, xmm0
; Line 112
	lea	r11, QWORD PTR [rsp+160]
	mov	rbx, QWORD PTR [r11+16]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm4, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 112
	movaps	xmm6, XMMWORD PTR [r11-16]
	movaps	xmm3, xmm8
	mulss	xmm3, xmm7
	movaps	xmm2, xmm13
	mulss	xmm1, xmm10
	mulss	xmm0, xmm11
	addss	xmm3, xmm1
	mulss	xmm2, xmm11
	movaps	xmm1, xmm9
	mulss	xmm1, xmm12
	addss	xmm3, xmm2
	movaps	xmm2, xmm9
	mulss	xmm2, xmm7
	subss	xmm3, xmm1
	movaps	xmm1, xmm8
	addss	xmm2, xmm0
	mulss	xmm1, xmm12
	movaps	xmm0, xmm13
	mulss	xmm0, xmm10
	movss	DWORD PTR [rdi], xmm3
	addss	xmm2, xmm1
	movaps	xmm3, xmm13
	movaps	xmm1, xmm9
	mulss	xmm3, xmm7
	mulss	xmm9, xmm11
	subss	xmm2, xmm0
	mulss	xmm13, xmm12
	movaps	xmm0, xmm4
	mulss	xmm1, xmm10
	mulss	xmm0, xmm12
	movaps	xmm12, XMMWORD PTR [r11-112]
	mulss	xmm4, xmm7
	movaps	xmm7, XMMWORD PTR [r11-32]
	addss	xmm3, xmm0
	movaps	xmm0, xmm8
	movss	DWORD PTR [rdi+4], xmm2
	mulss	xmm8, xmm10
	movaps	xmm10, XMMWORD PTR [r11-80]
	mulss	xmm0, xmm11
	addss	xmm3, xmm1
	movaps	xmm11, XMMWORD PTR [r11-96]
	subss	xmm4, xmm8
	movaps	xmm8, XMMWORD PTR [r11-48]
	subss	xmm3, xmm0
	subss	xmm4, xmm9
	movaps	xmm9, XMMWORD PTR [r11-64]
	movss	DWORD PTR [rdi+8], xmm3
	subss	xmm4, xmm13
	movaps	xmm13, XMMWORD PTR [r11-128]
	movss	DWORD PTR [rdi+12], xmm4
	mov	rsp, r11
	pop	rdi
	ret	0
?postRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z ENDP		; XGK::DATA::QUAT::postRot32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?preRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 176
axis_addr$ = 184
angle$ = 192
?preRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z PROC		; XGK::DATA::QUAT::preRot32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 64
$LN9:
	mov	rax, rsp
	mov	QWORD PTR [rax+8], rbx
	push	rdi
	sub	rsp, 160				; 000000a0H
	movaps	XMMWORD PTR [rax-24], xmm6
	mov	rbx, rdx
	movaps	XMMWORD PTR [rax-40], xmm7
	movaps	xmm6, xmm2
; Line 69
	mulss	xmm6, DWORD PTR __real@3f000000
	mov	rdi, rcx
	movaps	XMMWORD PTR [rax-56], xmm8
	movaps	XMMWORD PTR [rax-72], xmm9
	movaps	XMMWORD PTR [rax-88], xmm10
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rax-104], xmm11
	movaps	XMMWORD PTR [rax-120], xmm12
	movaps	XMMWORD PTR [rsp+32], xmm13
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 72
	movss	xmm10, DWORD PTR [rdi]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm13, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 79
	mulss	xmm13, DWORD PTR [rbx+8]
	movaps	xmm8, xmm0
	mulss	xmm8, DWORD PTR [rbx]
	movaps	xmm9, xmm0
	mulss	xmm9, DWORD PTR [rbx+4]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 73
	movss	xmm11, DWORD PTR [rdi+4]
; Line 74
	movss	xmm12, DWORD PTR [rdi+8]
; Line 75
	movss	xmm7, DWORD PTR [rdi+12]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 82
	movaps	xmm1, xmm0
; Line 86
	lea	r11, QWORD PTR [rsp+160]
	mov	rbx, QWORD PTR [r11+16]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm4, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 86
	movaps	xmm6, XMMWORD PTR [r11-16]
	movaps	xmm3, xmm8
	mulss	xmm3, xmm7
	movaps	xmm2, xmm9
	mulss	xmm1, xmm10
	mulss	xmm0, xmm11
	addss	xmm3, xmm1
	mulss	xmm2, xmm12
	movaps	xmm1, xmm13
	mulss	xmm1, xmm11
	addss	xmm3, xmm2
	movaps	xmm2, xmm9
	mulss	xmm2, xmm7
	subss	xmm3, xmm1
	movaps	xmm1, xmm13
	addss	xmm2, xmm0
	mulss	xmm1, xmm10
	movaps	xmm0, xmm8
	mulss	xmm0, xmm12
	movss	DWORD PTR [rdi], xmm3
	addss	xmm2, xmm1
	movaps	xmm3, xmm13
	movaps	xmm1, xmm8
	mulss	xmm3, xmm7
	mulss	xmm8, xmm10
	subss	xmm2, xmm0
	mulss	xmm13, xmm12
	movaps	xmm0, xmm4
	mulss	xmm1, xmm11
	mulss	xmm0, xmm12
	movaps	xmm12, XMMWORD PTR [r11-112]
	mulss	xmm4, xmm7
	movaps	xmm7, XMMWORD PTR [r11-32]
	addss	xmm3, xmm0
	movaps	xmm0, xmm9
	movss	DWORD PTR [rdi+4], xmm2
	subss	xmm4, xmm8
	mulss	xmm9, xmm11
	movaps	xmm8, XMMWORD PTR [r11-48]
	movaps	xmm11, XMMWORD PTR [r11-96]
	addss	xmm3, xmm1
	mulss	xmm0, xmm10
	movaps	xmm10, XMMWORD PTR [r11-80]
	subss	xmm4, xmm9
	movaps	xmm9, XMMWORD PTR [r11-64]
	subss	xmm3, xmm0
	subss	xmm4, xmm13
	movaps	xmm13, XMMWORD PTR [r11-128]
	movss	DWORD PTR [rdi+8], xmm3
	movss	DWORD PTR [rdi+12], xmm4
	mov	rsp, r11
	pop	rdi
	ret	0
?preRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z ENDP		; XGK::DATA::QUAT::preRot32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z
_TEXT	SEGMENT
data$ = 64
axis$ = 72
angle$ = 80
?makeRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z PROC		; XGK::DATA::QUAT::makeRot32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 48
$LN9:
	mov	QWORD PTR [rsp+8], rbx
	push	rdi
	sub	rsp, 48					; 00000030H
	movaps	XMMWORD PTR [rsp+32], xmm6
	mov	rbx, rdx
	movaps	xmm6, xmm2
	mov	rdi, rcx
; Line 53
	mulss	xmm6, DWORD PTR __real@3f000000
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 56
	movaps	xmm1, xmm0
; Line 57
	movaps	xmm2, xmm0
	mulss	xmm1, DWORD PTR [rbx]
	movss	DWORD PTR [rdi], xmm1
	mulss	xmm2, DWORD PTR [rbx+4]
	movss	DWORD PTR [rdi+4], xmm2
; Line 58
	mulss	xmm0, DWORD PTR [rbx+8]
	movss	DWORD PTR [rdi+8], xmm0
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 60
	mov	rbx, QWORD PTR [rsp+64]
	movaps	xmm6, XMMWORD PTR [rsp+32]
	movss	DWORD PTR [rdi+12], xmm0
	add	rsp, 48					; 00000030H
	pop	rdi
	ret	0
?makeRot32@QUAT@DATA@XGK@@YAXPEAX0M@Z ENDP		; XGK::DATA::QUAT::makeRot32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postmul32@QUAT@DATA@XGK@@YAXPEAX0@Z
_TEXT	SEGMENT
data0$ = 48
data1$ = 56
?postmul32@QUAT@DATA@XGK@@YAXPEAX0@Z PROC		; XGK::DATA::QUAT::postmul32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 30
$LN4:
	sub	rsp, 40					; 00000028H
; Line 35
	movss	xmm4, DWORD PTR [rcx]
; Line 36
	movss	xmm5, DWORD PTR [rcx+4]
; Line 40
	movaps	xmm2, xmm4
	mulss	xmm2, DWORD PTR [rdx+12]
	movaps	xmm1, xmm5
	mulss	xmm1, DWORD PTR [rdx+8]
	movaps	XMMWORD PTR [rsp+16], xmm6
	movss	xmm6, DWORD PTR [rcx+12]
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rsp], xmm7
	mulss	xmm0, DWORD PTR [rdx]
; Line 41
	movaps	xmm3, xmm6
	movss	xmm7, DWORD PTR [rcx+8]
	addss	xmm2, xmm0
	movaps	xmm0, xmm7
	mulss	xmm0, DWORD PTR [rdx+4]
	addss	xmm2, xmm1
	movaps	xmm1, xmm7
	subss	xmm2, xmm0
	movaps	xmm0, xmm5
	movss	DWORD PTR [rcx], xmm2
; Line 42
	movaps	xmm2, xmm6
	mulss	xmm0, DWORD PTR [rdx+12]
	mulss	xmm3, DWORD PTR [rdx+4]
	mulss	xmm1, DWORD PTR [rdx]
	addss	xmm3, xmm0
	movaps	xmm0, xmm4
	mulss	xmm0, DWORD PTR [rdx+8]
	addss	xmm3, xmm1
	movaps	xmm1, xmm4
	subss	xmm3, xmm0
	movaps	xmm0, xmm7
	movss	DWORD PTR [rcx+4], xmm3
	mulss	xmm2, DWORD PTR [rdx+8]
	mulss	xmm0, DWORD PTR [rdx+12]
	mulss	xmm1, DWORD PTR [rdx+4]
	addss	xmm2, xmm0
	movaps	xmm0, xmm5
	mulss	xmm0, DWORD PTR [rdx]
	addss	xmm2, xmm1
	subss	xmm2, xmm0
	movss	DWORD PTR [rcx+8], xmm2
; Line 43
	mulss	xmm6, DWORD PTR [rdx+12]
	mulss	xmm7, DWORD PTR [rdx+8]
	mulss	xmm4, DWORD PTR [rdx]
	mulss	xmm5, DWORD PTR [rdx+4]
	subss	xmm6, xmm4
	subss	xmm6, xmm5
	subss	xmm6, xmm7
; Line 44
	movaps	xmm7, XMMWORD PTR [rsp]
	movss	DWORD PTR [rcx+12], xmm6
	movaps	xmm6, XMMWORD PTR [rsp+16]
	add	rsp, 40					; 00000028H
	ret	0
?postmul32@QUAT@DATA@XGK@@YAXPEAX0@Z ENDP		; XGK::DATA::QUAT::postmul32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?premul32@QUAT@DATA@XGK@@YAXPEAX0@Z
_TEXT	SEGMENT
data0$ = 48
data1$ = 56
?premul32@QUAT@DATA@XGK@@YAXPEAX0@Z PROC		; XGK::DATA::QUAT::premul32, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-32.cpp
; Line 12
$LN4:
	sub	rsp, 40					; 00000028H
; Line 17
	movss	xmm4, DWORD PTR [rcx]
; Line 18
	movss	xmm5, DWORD PTR [rcx+4]
; Line 22
	movaps	xmm2, xmm4
	mulss	xmm2, DWORD PTR [rdx+12]
	movaps	XMMWORD PTR [rsp+16], xmm6
	movss	xmm6, DWORD PTR [rcx+12]
	movaps	xmm0, xmm6
	movaps	XMMWORD PTR [rsp], xmm7
	mulss	xmm0, DWORD PTR [rdx]
; Line 23
	movaps	xmm3, xmm6
	movss	xmm7, DWORD PTR [rcx+8]
	movaps	xmm1, xmm7
	mulss	xmm1, DWORD PTR [rdx+4]
	addss	xmm2, xmm0
	movaps	xmm0, xmm5
	mulss	xmm0, DWORD PTR [rdx+8]
	addss	xmm2, xmm1
	movaps	xmm1, xmm4
	subss	xmm2, xmm0
	movaps	xmm0, xmm5
	movss	DWORD PTR [rcx], xmm2
; Line 24
	movaps	xmm2, xmm6
	mulss	xmm0, DWORD PTR [rdx+12]
	mulss	xmm3, DWORD PTR [rdx+4]
	mulss	xmm1, DWORD PTR [rdx+8]
	addss	xmm3, xmm0
	movaps	xmm0, xmm7
	mulss	xmm0, DWORD PTR [rdx]
	addss	xmm3, xmm1
	movaps	xmm1, xmm5
	subss	xmm3, xmm0
	movaps	xmm0, xmm7
	movss	DWORD PTR [rcx+4], xmm3
	mulss	xmm2, DWORD PTR [rdx+8]
	mulss	xmm0, DWORD PTR [rdx+12]
	mulss	xmm1, DWORD PTR [rdx]
	addss	xmm2, xmm0
	movaps	xmm0, xmm4
	mulss	xmm0, DWORD PTR [rdx+4]
	addss	xmm2, xmm1
	subss	xmm2, xmm0
	movss	DWORD PTR [rcx+8], xmm2
; Line 25
	mulss	xmm6, DWORD PTR [rdx+12]
	mulss	xmm7, DWORD PTR [rdx+8]
	mulss	xmm4, DWORD PTR [rdx]
	mulss	xmm5, DWORD PTR [rdx+4]
	subss	xmm6, xmm4
	subss	xmm6, xmm5
	subss	xmm6, xmm7
; Line 26
	movaps	xmm7, XMMWORD PTR [rsp]
	movss	DWORD PTR [rcx+12], xmm6
	movaps	xmm6, XMMWORD PTR [rsp+16]
	add	rsp, 40					; 00000028H
	ret	0
?premul32@QUAT@DATA@XGK@@YAXPEAX0@Z ENDP		; XGK::DATA::QUAT::premul32
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?sin@@YAMM@Z
_TEXT	SEGMENT
_Xx$ = 8
?sin@@YAMM@Z PROC					; sin, COMDAT
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	jmp	sinf
?sin@@YAMM@Z ENDP					; sin
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?cos@@YAMM@Z
_TEXT	SEGMENT
_Xx$ = 8
?cos@@YAMM@Z PROC					; cos, COMDAT
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	jmp	cosf
?cos@@YAMM@Z ENDP					; cos
_TEXT	ENDS
END