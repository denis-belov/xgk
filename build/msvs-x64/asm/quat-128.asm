; Listing generated by Microsoft (R) Optimizing Compiler Version 19.23.28106.4 

include listing.inc

INCLUDELIB MSVCRT
INCLUDELIB OLDNAMES

CONST	SEGMENT
?CONST_MUL@QUAT@DATA@XGK@@3T__m128@@B DD 03f800000r ; 1	; XGK::DATA::QUAT::CONST_MUL
	DD	03f800000r			; 1
	DD	0bf800000r			; -1
	DD	0bf800000r			; -1
CONST	ENDS
PUBLIC	?cos@@YAMM@Z					; cos
PUBLIC	?sin@@YAMM@Z					; sin
PUBLIC	?premul128@QUAT@DATA@XGK@@YAXPEAX0@Z		; XGK::DATA::QUAT::premul128
PUBLIC	?postmul128@QUAT@DATA@XGK@@YAXPEAX0@Z		; XGK::DATA::QUAT::postmul128
PUBLIC	?makeRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z		; XGK::DATA::QUAT::makeRot128
PUBLIC	?preRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z		; XGK::DATA::QUAT::preRot128
PUBLIC	?postRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z		; XGK::DATA::QUAT::postRot128
PUBLIC	?makeRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::makeRotX128
PUBLIC	?preRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::preRotX128
PUBLIC	?postRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::postRotX128
PUBLIC	?makeRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::makeRotY128
PUBLIC	?preRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::preRotY128
PUBLIC	?postRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::postRotY128
PUBLIC	?makeRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::makeRotZ128
PUBLIC	?preRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::preRotZ128
PUBLIC	?postRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z		; XGK::DATA::QUAT::postRotZ128
PUBLIC	__real@3f000000
PUBLIC	__xmm@80000000800000008000000080000000
EXTRN	__GSHandlerCheck:PROC
EXTRN	__security_check_cookie:PROC
EXTRN	cosf:PROC
EXTRN	sinf:PROC
EXTRN	__security_cookie:QWORD
EXTRN	_fltused:DWORD
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z DD imagerel $LN9
	DD	imagerel $LN9+90
	DD	imagerel $unwind$?makeRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?preRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z DD imagerel $LN9
	DD	imagerel $LN9+210
	DD	imagerel $unwind$?preRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z DD imagerel $LN9
	DD	imagerel $LN9+224
	DD	imagerel $unwind$?postRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+67
	DD	imagerel $unwind$?makeRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?preRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+107
	DD	imagerel $unwind$?preRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+113
	DD	imagerel $unwind$?postRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+75
	DD	imagerel $unwind$?makeRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?preRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+132
	DD	imagerel $unwind$?preRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+132
	DD	imagerel $unwind$?postRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?makeRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+67
	DD	imagerel $unwind$?makeRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?preRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+132
	DD	imagerel $unwind$?preRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT pdata
pdata	SEGMENT
$pdata$?postRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z DD imagerel $LN9
	DD	imagerel $LN9+126
	DD	imagerel $unwind$?postRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z
pdata	ENDS
;	COMDAT __xmm@80000000800000008000000080000000
CONST	SEGMENT
__xmm@80000000800000008000000080000000 DB 00H, 00H, 00H, 080H, 00H, 00H, 00H
	DB	080H, 00H, 00H, 00H, 080H, 00H, 00H, 00H, 080H
CONST	ENDS
;	COMDAT __real@3f000000
CONST	SEGMENT
__real@3f000000 DD 03f000000r			; 0.5
CONST	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 082401H
	DD	028824H
	DD	037813H
	DD	04680bH
	DD	030029206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?preRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 082401H
	DD	028824H
	DD	037813H
	DD	04680bH
	DD	030029206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 040b01H
	DD	02680bH
	DD	030025206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 082401H
	DD	028824H
	DD	037813H
	DD	04680bH
	DD	030029206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?preRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 082401H
	DD	028824H
	DD	037813H
	DD	04680bH
	DD	030029206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 040b01H
	DD	02680bH
	DD	030025206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 061601H
	DD	027816H
	DD	03680bH
	DD	030027206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?preRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 061301H
	DD	027813H
	DD	03680bH
	DD	030027206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z DD 040b01H
	DD	02680bH
	DD	030025206H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?postRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z DD 082319H
	DD	047814H
	DD	05680fH
	DD	011340aH
	DD	07006b20aH
	DD	imagerel __GSHandlerCheck
	DD	030H
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?preRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z DD 0a2b01H
	DD	02882bH
	DD	03781aH
	DD	04680fH
	DD	0f340aH
	DD	07006920aH
xdata	ENDS
;	COMDAT xdata
xdata	SEGMENT
$unwind$?makeRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z DD 060f01H
	DD	02680fH
	DD	08340aH
	DD	07006520aH
xdata	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 96
angle$ = 104
?postRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::postRotZ128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 328
$LN9:
	push	rbx
	sub	rsp, 80					; 00000050H
	movaps	XMMWORD PTR [rsp+64], xmm6
	mov	rbx, rcx
	movaps	XMMWORD PTR [rsp+48], xmm7
	movaps	xmm7, xmm1
; Line 334
	mulss	xmm7, DWORD PTR __real@3f000000
	movaps	XMMWORD PTR [rsp+32], xmm8
	movups	xmm8, XMMWORD PTR [rcx]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm7
	call	sinf
	movaps	xmm6, xmm0
; Line 66
	movaps	xmm0, xmm7
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 346
	movaps	xmm7, XMMWORD PTR [rsp+48]
	movaps	xmm1, xmm6
	xorps	xmm1, DWORD PTR __xmm@80000000800000008000000080000000
	movaps	xmm2, xmm6
	movaps	xmm6, XMMWORD PTR [rsp+64]
	unpcklps xmm2, xmm1
	movaps	xmm1, xmm8
	shufps	xmm1, xmm8, 177				; 000000b1H
	movlhps	xmm2, xmm2
	shufps	xmm0, xmm0, 0
	mulps	xmm0, xmm8
	movaps	xmm8, XMMWORD PTR [rsp+32]
	mulps	xmm2, xmm1
	addps	xmm2, xmm0
	movups	XMMWORD PTR [rbx], xmm2
	add	rsp, 80					; 00000050H
	pop	rbx
	ret	0
?postRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::postRotZ128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?preRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 96
angle$ = 104
?preRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::preRotZ128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 306
$LN9:
	push	rbx
	sub	rsp, 80					; 00000050H
	movaps	XMMWORD PTR [rsp+64], xmm6
	mov	rbx, rcx
	movaps	XMMWORD PTR [rsp+48], xmm7
	movaps	xmm7, xmm1
; Line 312
	mulss	xmm7, DWORD PTR __real@3f000000
	movaps	XMMWORD PTR [rsp+32], xmm8
	movups	xmm8, XMMWORD PTR [rcx]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm7
	call	sinf
	movaps	xmm6, xmm0
; Line 66
	movaps	xmm0, xmm7
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 324
	movaps	xmm7, XMMWORD PTR [rsp+48]
	movaps	xmm3, xmm6
	xorps	xmm3, DWORD PTR __xmm@80000000800000008000000080000000
	movaps	xmm4, xmm6
	movaps	xmm1, xmm8
	unpcklps xmm4, xmm3
	shufps	xmm1, xmm8, 177				; 000000b1H
	movaps	xmm5, xmm3
	unpcklps xmm5, xmm6
	movaps	xmm6, XMMWORD PTR [rsp+64]
	movlhps	xmm5, xmm4
	shufps	xmm0, xmm0, 0
	mulps	xmm0, xmm8
	movaps	xmm8, XMMWORD PTR [rsp+32]
	mulps	xmm5, xmm1
	addps	xmm5, xmm0
	movups	XMMWORD PTR [rbx], xmm5
	add	rsp, 80					; 00000050H
	pop	rbx
	ret	0
?preRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::preRotZ128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 64
angle$ = 72
?makeRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::makeRotZ128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 292
$LN9:
	push	rbx
	sub	rsp, 48					; 00000030H
	movaps	XMMWORD PTR [rsp+32], xmm6
; Line 298
	xor	eax, eax
	movaps	xmm6, xmm1
	mov	QWORD PTR [rcx], rax
	mulss	xmm6, DWORD PTR __real@3f000000
	mov	rbx, rcx
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 300
	movss	DWORD PTR [rbx+8], xmm0
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 302
	movaps	xmm6, XMMWORD PTR [rsp+32]
	movss	DWORD PTR [rbx+12], xmm0
	add	rsp, 48					; 00000030H
	pop	rbx
	ret	0
?makeRotZ128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::makeRotZ128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 96
angle$ = 104
?postRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::postRotY128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 270
$LN9:
	push	rbx
	sub	rsp, 80					; 00000050H
	movaps	XMMWORD PTR [rsp+64], xmm6
	mov	rbx, rcx
	movaps	XMMWORD PTR [rsp+48], xmm7
	movaps	xmm7, xmm1
; Line 276
	mulss	xmm7, DWORD PTR __real@3f000000
	movaps	XMMWORD PTR [rsp+32], xmm8
	movups	xmm8, XMMWORD PTR [rcx]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm7
	call	sinf
	movaps	xmm6, xmm0
; Line 66
	movaps	xmm0, xmm7
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 288
	movaps	xmm7, XMMWORD PTR [rsp+48]
	movaps	xmm3, xmm6
	xorps	xmm3, DWORD PTR __xmm@80000000800000008000000080000000
	movaps	xmm4, xmm6
	movaps	xmm1, xmm8
	unpcklps xmm4, xmm3
	shufps	xmm1, xmm8, 78				; 0000004eH
	movaps	xmm5, xmm3
	unpcklps xmm5, xmm6
	movaps	xmm6, XMMWORD PTR [rsp+64]
	movlhps	xmm5, xmm4
	shufps	xmm0, xmm0, 0
	mulps	xmm0, xmm8
	movaps	xmm8, XMMWORD PTR [rsp+32]
	mulps	xmm5, xmm1
	addps	xmm5, xmm0
	movups	XMMWORD PTR [rbx], xmm5
	add	rsp, 80					; 00000050H
	pop	rbx
	ret	0
?postRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::postRotY128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?preRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 96
angle$ = 104
?preRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::preRotY128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 248
$LN9:
	push	rbx
	sub	rsp, 80					; 00000050H
	movaps	XMMWORD PTR [rsp+64], xmm6
	mov	rbx, rcx
	movaps	XMMWORD PTR [rsp+48], xmm7
	movaps	xmm7, xmm1
; Line 254
	mulss	xmm7, DWORD PTR __real@3f000000
	movaps	XMMWORD PTR [rsp+32], xmm8
	movups	xmm8, XMMWORD PTR [rcx]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm7
	call	sinf
	movaps	xmm6, xmm0
; Line 66
	movaps	xmm0, xmm7
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 266
	movaps	xmm7, XMMWORD PTR [rsp+48]
	movaps	xmm1, xmm6
	xorps	xmm1, DWORD PTR __xmm@80000000800000008000000080000000
	movaps	xmm4, xmm6
	unpcklps xmm4, xmm6
	movaps	xmm3, xmm1
	movaps	xmm6, XMMWORD PTR [rsp+64]
	unpcklps xmm3, xmm1
	movaps	xmm1, xmm8
	shufps	xmm1, xmm8, 78				; 0000004eH
	movlhps	xmm4, xmm3
	shufps	xmm0, xmm0, 0
	mulps	xmm0, xmm8
	movaps	xmm8, XMMWORD PTR [rsp+32]
	mulps	xmm4, xmm1
	addps	xmm4, xmm0
	movups	XMMWORD PTR [rbx], xmm4
	add	rsp, 80					; 00000050H
	pop	rbx
	ret	0
?preRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::preRotY128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
data$ = 64
angle$ = 72
?makeRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::makeRotY128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 234
$LN9:
	push	rbx
	sub	rsp, 48					; 00000030H
	movaps	XMMWORD PTR [rsp+32], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
; Line 240
	mov	DWORD PTR [rcx], 0
	mulss	xmm6, DWORD PTR __real@3f000000
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 241
	movss	DWORD PTR [rbx+4], xmm0
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 242
	mov	DWORD PTR [rbx+8], 0
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 244
	movaps	xmm6, XMMWORD PTR [rsp+32]
	movss	DWORD PTR [rbx+12], xmm0
	add	rsp, 48					; 00000030H
	pop	rbx
	ret	0
?makeRotY128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::makeRotY128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 80
angle$ = 88
?postRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::postRotX128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 214
$LN9:
	push	rbx
	sub	rsp, 64					; 00000040H
	movaps	XMMWORD PTR [rsp+48], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
	movaps	XMMWORD PTR [rsp+32], xmm7
; Line 218
	mulss	xmm6, DWORD PTR __real@3f000000
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
	movaps	xmm7, xmm0
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 230
	movaps	xmm6, XMMWORD PTR [rsp+48]
	movaps	xmm1, xmm7
	xorps	xmm1, DWORD PTR __xmm@80000000800000008000000080000000
	movaps	xmm4, xmm7
	unpcklps xmm4, xmm7
	movaps	xmm3, xmm1
	movaps	xmm7, XMMWORD PTR [rsp+32]
	unpcklps xmm3, xmm1
	movups	xmm1, XMMWORD PTR [rbx]
	movlhps	xmm4, xmm3
	shufps	xmm1, xmm1, 27
	shufps	xmm0, xmm0, 0
	mulps	xmm0, XMMWORD PTR [rbx]
	mulps	xmm4, xmm1
	addps	xmm4, xmm0
	movups	XMMWORD PTR [rbx], xmm4
	add	rsp, 64					; 00000040H
	pop	rbx
	ret	0
?postRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::postRotX128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?preRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 80
angle$ = 88
?preRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::preRotX128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 194
$LN9:
	push	rbx
	sub	rsp, 64					; 00000040H
	movaps	XMMWORD PTR [rsp+48], xmm6
	mov	rbx, rcx
	movaps	XMMWORD PTR [rsp+32], xmm7
	movaps	xmm7, xmm1
; Line 198
	mulss	xmm7, DWORD PTR __real@3f000000
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm7
	call	sinf
	movaps	xmm6, xmm0
; Line 66
	movaps	xmm0, xmm7
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 210
	movaps	xmm7, XMMWORD PTR [rsp+32]
	movaps	xmm1, xmm6
	xorps	xmm1, DWORD PTR __xmm@80000000800000008000000080000000
	movaps	xmm2, xmm6
	movaps	xmm6, XMMWORD PTR [rsp+48]
	unpcklps xmm2, xmm1
	movups	xmm1, XMMWORD PTR [rbx]
	movlhps	xmm2, xmm2
	shufps	xmm1, xmm1, 27
	shufps	xmm0, xmm0, 0
	mulps	xmm0, XMMWORD PTR [rbx]
	mulps	xmm2, xmm1
	addps	xmm2, xmm0
	movups	XMMWORD PTR [rbx], xmm2
	add	rsp, 64					; 00000040H
	pop	rbx
	ret	0
?preRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::preRotX128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 64
angle$ = 72
?makeRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z PROC		; XGK::DATA::QUAT::makeRotX128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 180
$LN9:
	push	rbx
	sub	rsp, 48					; 00000030H
	movaps	XMMWORD PTR [rsp+32], xmm6
	mov	rbx, rcx
	movaps	xmm6, xmm1
; Line 184
	mulss	xmm6, DWORD PTR __real@3f000000
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 186
	movss	DWORD PTR [rbx], xmm0
; Line 187
	xor	eax, eax
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 187
	mov	QWORD PTR [rbx+4], rax
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 190
	movaps	xmm6, XMMWORD PTR [rsp+32]
	movss	DWORD PTR [rbx+12], xmm0
	add	rsp, 48					; 00000030H
	pop	rbx
	ret	0
?makeRotX128@QUAT@DATA@XGK@@YAXPEAXM@Z ENDP		; XGK::DATA::QUAT::makeRotX128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z
_TEXT	SEGMENT
__$ArrayPad$ = 48
dst_quaternion_addr$ = 112
dst_vector_addr$ = 120
angle$ = 128
?postRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z PROC		; XGK::DATA::QUAT::postRot128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 143
$LN9:
	mov	QWORD PTR [rsp+32], rbx
	push	rdi
	sub	rsp, 96					; 00000060H
	movaps	XMMWORD PTR [rsp+80], xmm6
	movaps	XMMWORD PTR [rsp+64], xmm7
	mov	rax, QWORD PTR __security_cookie
	xor	rax, rsp
	mov	QWORD PTR __$ArrayPad$[rsp], rax
	movaps	xmm6, xmm2
	mov	rbx, rdx
; Line 149
	mulss	xmm6, DWORD PTR __real@3f000000
	mov	rdi, rcx
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 149
	movups	xmm1, XMMWORD PTR [rbx]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm7, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 149
	shufps	xmm1, xmm1, 27
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 149
	shufps	xmm7, xmm7, 0
	mulps	xmm7, xmm1
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 151
	movss	xmm1, DWORD PTR [rdi]
	shufps	xmm1, xmm1, 0
	shufps	xmm7, xmm7, 108				; 0000006cH
	movss	xmm7, xmm0
	movss	xmm0, DWORD PTR [rdi+12]
	shufps	xmm7, xmm7, 57				; 00000039H
	mulps	xmm1, xmm7
	movaps	xmm2, xmm7
	shufps	xmm2, xmm7, 27
	shufps	xmm0, xmm0, 0
	mulps	xmm2, xmm0
	movss	xmm0, DWORD PTR [rdi+4]
	shufps	xmm0, xmm0, 0
	addsubps xmm2, xmm1
	movaps	xmm1, xmm7
	shufps	xmm1, xmm7, 78				; 0000004eH
	mulps	xmm1, xmm0
	movss	xmm0, DWORD PTR [rdi+8]
	shufps	xmm0, xmm0, 0
	shufps	xmm7, xmm7, 177				; 000000b1H
	mulps	xmm7, xmm0
	shufps	xmm2, xmm2, 27
	addsubps xmm1, xmm7
	mulps	xmm1, XMMWORD PTR ?CONST_MUL@QUAT@DATA@XGK@@3T__m128@@B
	addps	xmm1, xmm2
	movups	XMMWORD PTR [rdi], xmm1
; Line 152
	mov	rcx, QWORD PTR __$ArrayPad$[rsp]
	xor	rcx, rsp
	call	__security_check_cookie
	mov	rbx, QWORD PTR [rsp+136]
	movaps	xmm6, XMMWORD PTR [rsp+80]
	movaps	xmm7, XMMWORD PTR [rsp+64]
	add	rsp, 96					; 00000060H
	pop	rdi
	ret	0
?postRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z ENDP		; XGK::DATA::QUAT::postRot128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?preRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 96
dst_vector_addr$ = 104
angle$ = 112
?preRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z PROC		; XGK::DATA::QUAT::preRot128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 130
$LN9:
	mov	QWORD PTR [rsp+32], rbx
	push	rdi
	sub	rsp, 80					; 00000050H
	movaps	XMMWORD PTR [rsp+64], xmm6
	mov	rbx, rdx
	movaps	xmm6, xmm2
	movaps	XMMWORD PTR [rsp+48], xmm7
; Line 136
	mulss	xmm6, DWORD PTR __real@3f000000
	mov	rdi, rcx
	movaps	XMMWORD PTR [rsp+32], xmm8
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 136
	movups	xmm1, XMMWORD PTR [rbx]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm8, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 138
	movups	xmm7, XMMWORD PTR [rdi]
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 136
	shufps	xmm8, xmm8, 0
	shufps	xmm1, xmm1, 27
	mulps	xmm8, xmm1
	shufps	xmm8, xmm8, 27
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 139
	mov	rbx, QWORD PTR [rsp+120]
	movaps	xmm1, xmm7
	movaps	xmm6, XMMWORD PTR [rsp+64]
	movaps	xmm2, xmm7
	shufps	xmm1, xmm7, 27
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm3, xmm0
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 138
	shufps	xmm2, xmm7, 78				; 0000004eH
	shufps	xmm3, xmm3, 0
	mulps	xmm3, xmm1
	movaps	xmm1, xmm8
	shufps	xmm1, xmm1, 0
	mulps	xmm1, xmm7
	shufps	xmm7, xmm7, 177				; 000000b1H
	addsubps xmm3, xmm1
	movaps	xmm1, xmm8
	shufps	xmm1, xmm8, 85				; 00000055H
	shufps	xmm8, xmm8, 170				; 000000aaH
	movaps	xmm0, xmm8
	shufps	xmm1, xmm1, 0
; Line 139
	movaps	xmm8, XMMWORD PTR [rsp+32]
	mulps	xmm2, xmm1
	shufps	xmm0, xmm0, 0
	mulps	xmm7, xmm0
	shufps	xmm3, xmm3, 27
	addsubps xmm2, xmm7
	movaps	xmm7, XMMWORD PTR [rsp+48]
	mulps	xmm2, XMMWORD PTR ?CONST_MUL@QUAT@DATA@XGK@@3T__m128@@B
	addps	xmm2, xmm3
	movups	XMMWORD PTR [rdi], xmm2
	add	rsp, 80					; 00000050H
	pop	rdi
	ret	0
?preRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z ENDP		; XGK::DATA::QUAT::preRot128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?makeRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 64
dst_vector_addr$ = 72
angle$ = 80
?makeRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z PROC		; XGK::DATA::QUAT::makeRot128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 120
$LN9:
	mov	QWORD PTR [rsp+8], rbx
	push	rdi
	sub	rsp, 48					; 00000030H
	movaps	XMMWORD PTR [rsp+32], xmm6
	mov	rbx, rdx
	movaps	xmm6, xmm2
	mov	rdi, rcx
; Line 125
	mulss	xmm6, DWORD PTR __real@3f000000
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 230
	movaps	xmm0, xmm6
	call	sinf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 125
	movups	xmm1, XMMWORD PTR [rbx]
	shufps	xmm0, xmm0, 0
	shufps	xmm1, xmm1, 27
	mulps	xmm0, xmm1
	shufps	xmm0, xmm0, 27
	movups	XMMWORD PTR [rdi], xmm0
; File C:\Program Files (x86)\Microsoft Visual Studio\2019\Community\VC\Tools\MSVC\14.23.28105\include\cmath
; Line 66
	movaps	xmm0, xmm6
	call	cosf
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 126
	mov	rbx, QWORD PTR [rsp+64]
	movaps	xmm6, XMMWORD PTR [rsp+32]
	movss	DWORD PTR [rdi+12], xmm0
	add	rsp, 48					; 00000030H
	pop	rdi
	ret	0
?makeRot128@QUAT@DATA@XGK@@YAXPEAX0M@Z ENDP		; XGK::DATA::QUAT::makeRot128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?postmul128@QUAT@DATA@XGK@@YAXPEAX0@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 8
src_quaternion_addr$ = 16
?postmul128@QUAT@DATA@XGK@@YAXPEAX0@Z PROC		; XGK::DATA::QUAT::postmul128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 115
	movups	xmm2, XMMWORD PTR [rdx]
	movss	xmm0, DWORD PTR [rcx+12]
	movaps	xmm3, xmm2
	movss	xmm1, DWORD PTR [rcx]
	shufps	xmm1, xmm1, 0
	mulps	xmm1, xmm2
	shufps	xmm3, xmm2, 27
	shufps	xmm0, xmm0, 0
	mulps	xmm3, xmm0
	movss	xmm0, DWORD PTR [rcx+4]
	shufps	xmm0, xmm0, 0
	addsubps xmm3, xmm1
	movaps	xmm1, xmm2
	shufps	xmm1, xmm2, 78				; 0000004eH
	mulps	xmm1, xmm0
	movss	xmm0, DWORD PTR [rcx+8]
	shufps	xmm0, xmm0, 0
	shufps	xmm2, xmm2, 177				; 000000b1H
	mulps	xmm2, xmm0
	shufps	xmm3, xmm3, 27
	addsubps xmm1, xmm2
	mulps	xmm1, XMMWORD PTR ?CONST_MUL@QUAT@DATA@XGK@@3T__m128@@B
	addps	xmm1, xmm3
	movups	XMMWORD PTR [rcx], xmm1
; Line 116
	ret	0
?postmul128@QUAT@DATA@XGK@@YAXPEAX0@Z ENDP		; XGK::DATA::QUAT::postmul128
_TEXT	ENDS
; Function compile flags: /Ogtpy
;	COMDAT ?premul128@QUAT@DATA@XGK@@YAXPEAX0@Z
_TEXT	SEGMENT
dst_quaternion_addr$ = 8
src_quaternion_addr$ = 16
?premul128@QUAT@DATA@XGK@@YAXPEAX0@Z PROC		; XGK::DATA::QUAT::premul128, COMDAT
; File E:\reps\denis-belov\xgk\src\data\quat\quat-128.cpp
; Line 105
	movups	xmm2, XMMWORD PTR [rcx]
	movss	xmm0, DWORD PTR [rdx+12]
	movaps	xmm3, xmm2
	movss	xmm1, DWORD PTR [rdx]
	shufps	xmm1, xmm1, 0
	mulps	xmm1, xmm2
	shufps	xmm3, xmm2, 27
	shufps	xmm0, xmm0, 0
	mulps	xmm3, xmm0
	movss	xmm0, DWORD PTR [rdx+4]
	shufps	xmm0, xmm0, 0
	addsubps xmm3, xmm1
	movaps	xmm1, xmm2
	shufps	xmm1, xmm2, 78				; 0000004eH
	mulps	xmm1, xmm0
	movss	xmm0, DWORD PTR [rdx+8]
	shufps	xmm0, xmm0, 0
	shufps	xmm2, xmm2, 177				; 000000b1H
	mulps	xmm2, xmm0
	shufps	xmm3, xmm3, 27
	addsubps xmm1, xmm2
	mulps	xmm1, XMMWORD PTR ?CONST_MUL@QUAT@DATA@XGK@@3T__m128@@B
	addps	xmm1, xmm3
	movups	XMMWORD PTR [rcx], xmm1
; Line 106
	ret	0
?premul128@QUAT@DATA@XGK@@YAXPEAX0@Z ENDP		; XGK::DATA::QUAT::premul128
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
