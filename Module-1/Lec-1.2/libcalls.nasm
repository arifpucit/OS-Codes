;  libcalls.nasm
;  Assemble: nasm -felf64 libcalls.nasm
;  Link:     gcc -no-pie libcalls.o
;  usage:    ./a.out

SECTION .data
   msg  db "A hello to C library functions", 0
SECTION .bss
   ;nothing here
SECTION .text   
   global main
   extern printf, exit
main:
;display  message
   lea rdi, [msg] ; first argument to printf
   xor rax, rax ; clear rax as no floating point args to printf
   call printf
;make the exit library call
   mov rdi, 5
   call exit
