.text

.global clock64

clock64:

  push %rdx

  rdtsc
  mov %edx, 4(%rsp)
  mov %eax, (%rsp)
  mov (%rsp), %rax

  pop %rdx

  ret
