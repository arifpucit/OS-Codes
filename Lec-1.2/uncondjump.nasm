;  uncondjump.nasm
;  Assemble: nasm -felf64 -g uncondjump.nasm
;  Link: gcc uncondjump1.o -o uncondjump
;  Usage: ./condjump

SECTION .data   
   msg1 db "Study Cyber Security", 0
   msg2 db "Play Cricket", 0

SECTION .text   
   global main
   extern printf, exit   
main:  
      lea rdi, [msg1]
      xor rax, rax
      call printf
      jmp _end  
      lea rdi, [msg2]
      xor rax, rax
      call printf
_end:      
      mov rdi, 0
      call exit
