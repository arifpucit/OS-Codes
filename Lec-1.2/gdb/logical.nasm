;  COAL Video Lecture: 37
;  logical.nasm
;  Assemble: nasm -felf64 logical.nasm
;  Link:     ld mul.o -o logical
;  usage:    gdb -q ./logical -tui

section .text
global _start
_start:

; convert lower case alphabet to upper case using AND
   MOV al, 61h   ; 0110 0001 (97d or a)
   AND al, 0xdf  ; 1101 1111 , AL = 0100 0001 (65d or A)
; convert ascii to integer using AND
   MOV al, 32h  ; 0011 0010 (50d)
   AND al, 0fh  ; 0000 1111 , AL = 0000 0010 (2d)

; convert upper case alphabet to lower case using OR
   MOV al, 5ah  ; 0101 1010 (90d or Z)
   OR  al, 20h  ; 0010 0000 , AL = 0111 1010 (7ah or 122d or z)
; convert integer to ascii using OR  
   MOV al, 5d  ; 0000 0101 
   OR  al, 30h ; 0011 0000 ,  AL = 0011 0101 (53d)

; To clear entire register contents to zero using XOR
   MOV rax, 12345678abcdefh 
   XOR rax, rax

; To check if a number is positive or negative using test
   MOV  al, -5d  ; 1111 1011  
   TEST al, 80h  ; 1000 0000  , ZF = 0
; To check if a register contains even or odd number using test
   MOV  al, 6d  ; 0000 0110  
   TEST al, 01h ; 0000 0001 , ZF = 1

; exit the program gracefully  
   mov rax, 60
   mov rdi, 0		
   syscall
