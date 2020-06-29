.DATA

.CODE

  clock64 PROC

    push rdx

    rdtsc
    mov 4[rsp], edx
    mov [rsp], eax
    mov rax, [rsp]

    pop rdx

    ret 0
  clock64 ENDP
END
