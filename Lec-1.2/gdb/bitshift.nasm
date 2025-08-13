;  COAL Video Lecture: 38
;  bitshift.nasm
;  Assemble: nasm -felf64 bitshift.nasm
;  Link:     ld bitshift.o -o bitshift
;  usage:    gdb -q ./bitshift -tui

		
global _start	
section .text
_start:

;the maximum value that can be shifted is of 6 bits
   mov rax, -1d
   shl rax, 63
;shl/sal multiplies a signed/unsigned number by 2^n
   xor rax, rax
   stc
   mov rax, 5d
   shl rax, 2     ;rax=20, cf=0
;shl/sal multiplies a signed/unsigned number by 2^n
   xor rax, rax
   mov rax, -7d
   shl rax, 1     ;rax=-14, cf=1
;shr divides an unsigned number by 2^n
   xor rax, rax
   stc
   mov rax, 40d
   shr rax, 2      ;rax=10,  cf=0
;sar divides unsigned/signed number by 2^n
   xor rax, rax
   stc
   mov rax, -80d
   sar rax, 3      ;rax=-10, cf=0
;sar does not produce the same result as idiv
   xor rax, rax
   mov rax, -9d
   sar rax, 1      ;rax=-5, cf=1
   sar rax, 1      ;rax=-3, cf=1
;exit the program gracefully  
   mov rax, 60
   mov rdi, 0		
   syscall
