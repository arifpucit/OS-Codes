;  condjump.nasm
;  Assemble: nasm -felf64 -g condjump.nasm
;  Link: gcc -no-pie condjump.o -o condjump
;  Usage: ./condjump

SECTION .data
    msg1: db "Negative Number!", 0
    msg2: db "Positive Number!", 0

SECTION .text   
   global main
   extern printf, exit   
main:  
      mov ax, -5d 
      cmp ax, 0
      jge _positive
      
      lea rdi, [msg1]
      xor rax, rax
      call printf
      jmp _end 
_positive:
      lea rdi, [msg2]
      xor rax, rax
      call printf
_end:
      mov rdi, 0
      call exit
