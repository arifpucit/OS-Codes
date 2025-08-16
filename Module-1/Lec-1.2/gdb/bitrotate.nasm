;  COAL Video Lecture: 38
;  bitrotate.nasm
;  Assemble: nasm -felf64 bitrotate.nasm
;  Link:     ld bitrotate.o -o bitrotate
;  usage:    gdb -q ./bitrotate -tui

		
global _start	
section .text
_start:

;rotate left example 
   mov al, 11110000b 
   rol al, 1     ; al=11100001 (e1), cf=1
;rotate through carry left example
   clc   
   mov al, 88h      ; al=10001000
   rcl al, 1        ; cf=1, al=00010000(10h)
   rcl al, 1        ; cf=0, al=00100001(21h)

;rotate right example
   mov al,11110000b  ; al=f0
   ror al,1          ; al=01111000(78), cf=0
;rotate through carry right example
   stc 
   mov al, 10h     ; al=00010000
   rcr al, 1       ;cf=0, al=10001000(88h)

;exit the program gracefully  
   mov rax, 60
   mov rdi, 0		
   syscall
