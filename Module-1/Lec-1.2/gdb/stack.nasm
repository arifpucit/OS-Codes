;  COAL Video Lecture: 33
;  stack.nasm
;  Assemble: nasm -felf64 stack.nasm
;  Link:     ld stack.o -o stack
;  usage:    gdb -q ./stack -tui


section .data
  var db 0xaa, 0xbb, 0xcc, 0xdd, 0xee, 0xff, 0x11, 0x22


section .text
global _start			
_start:
   mov rax, 0x1122334455667788
   push rax
   push var 
   push qword [var]
   pop r8
   pop r9
   pop rbx	

; exit the program gracefully  
   mov rax, 0x3c
   mov rdi, 0		
   syscall


