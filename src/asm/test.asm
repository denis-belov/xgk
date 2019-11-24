.DATA

.CODE

  ; C prototype: void uniform1 (void* uniform_attr);

  ; GL function prototypes:
  ; void glUniform1f (GLint location, GLfloat v0);
  ; void glUniform1i (GLint location, GLint v0);
  ; void glUniform1ui (GLint location, GLuint v0);

  uniform1 PROC
    ; prologue
    push rbx ; save
    push rdx ; save
    ;

    mov rbx, rcx ; save rcx (uniform_attr) in rbx
    mov rcx, 8[rbx] ; GL function arg # 0 (uniform_attr.location)
    ; GL function arg # 1 (uniform_attr.data_ptr[0])
    mov rdx, 16[rbx] ; moving address of data to rdx
    mov rdx, [rdx] ; moving value at memory address stored in rdx to rdx

    call rbx ; call GL function since its address is stored in rbx

    ; epilogue
    pop rdx ; restore
    pop rbx ; restore
    ret 0
    ;
  uniform1 ENDP



  ; C prototype: void uniform2 (void* uniform_attr);



  ; C prototype: void uniform3 (void* uniform_attr);



  ; C prototype: void uniform4 (void* uniform_attr);



  ; C prototype: void uniformv (void* uniform_attr);

  ; GL function prototypes:
  ; void glUniform1fv (GLint location, GLsizei size, GLfloat v0);
  ; void glUniform2fv (GLint location, GLsizei size, GLfloat v0);
  ; void glUniform3fv (GLint location, GLsizei size, GLfloat v0);
  ; void glUniform4fv (GLint location, GLsizei size, GLfloat v0);
  ; void glUniform1iv (GLint location, GLsizei size, GLint v0);
  ; void glUniform2iv (GLint location, GLsizei size, GLint v0);
  ; void glUniform3iv (GLint location, GLsizei size, GLint v0);
  ; void glUniform4iv (GLint location, GLsizei size, GLint v0);
  ; void glUniform1uiv (GLint location, GLsizei size, GLuint v0);
  ; void glUniform2uiv (GLint location, GLsizei size, GLuint v0);
  ; void glUniform3uiv (GLint location, GLsizei size, GLuint v0);
  ; void glUniform4uiv (GLint location, GLsizei size, GLuint v0);

  uniformv PROC
    ; prologue
    push rbx ; save
    push rdx ; save
    push r8 ; save
    ;

    mov rbx, rcx ; save rcx (uniform_attr) in rbx
    mov rcx, 8[rbx] ; GL function arg # 0 (uniform_attr.location)
    mov rdx, 16[rbx] ; GL function arg # 1 (uniform_attr.size)
    mov r8, 24[rbx] ; GL function arg # 2 (uniform_attr.data_ptr)

    call rbx ; call GL function since its address is stored in rbx

    ; epilogue
    pop r8 ; store
    pop rdx ; restore
    pop rbx ; restore
    ret 0
    ;
  uniformv ENDP

END
