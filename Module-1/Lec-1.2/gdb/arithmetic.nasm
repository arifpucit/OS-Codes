;  arithmetic.nasm
;  Assemble: nasm -felf64 arithmetic.nasm
;  Link:     ld arithmetic.o -o arithmetic
;  usage:    gdb -q ./arithmetic -tui

section .data
	var1	dq	0x1
	var2    dq      0x0

section .text
global main
main:
; add/sub with destination operand as register
   mov rax, 0x01           ;moving an immediate value inside register
   add rax, qword [var1]   ;adding a memory value to a register value
   mov rax, 0xffffffffffffffff
   add rax, 0x01           ;adding an immediate value to a register
   mov rbx, 0x09
   sub rax, rbx            ;rax = rax - rbx
   
;add/sub with destination operand as memory
   mov rax, qword [var1]
   add qword [var2], rax
   add qword [var2], 0x02

; clear / set / complement carry flag 
   clc
   stc
   cmc

;add with carry 
   mov rax, 0
   stc
   adc rax, 0x1
   stc
   adc rax, 0x2

;subtract  with borrow
   mov rax, 0x10
   sub rax, 0x5
   stc
   sbb rax, 0x4
	
;increment and decrement
   inc rax
   dec rax

;negate
   mov rax, 0x1
   neg rax

;compare
   mov rax, 0x5
   mov rbx, 0x5
   cmp rax, rbx
	
;exit the program gracefully  
   mov rax, 0x3c
   mov rdi, 0		
   syscall
