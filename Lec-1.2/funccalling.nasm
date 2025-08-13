;  funccalling.nasm
;  Assemble: nasm -felf64 funccalling.nasm
;  Link:     gcc -no-pie funccalling.o -o myexe
;  usage:    ./myexe

Section .data
   msg db "Cyber Security Course is fun", 0

SECTION .text
   global main
   extern printf, exit
   main:
      call printmsg 
      mov rdi, 0
      call exit         
printmsg:
      lea rdi, [msg]
      xor rax, rax
      call printf  
      ret
