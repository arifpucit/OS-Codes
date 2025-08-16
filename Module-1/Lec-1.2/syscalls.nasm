;  syscalls.nasm
;  Assemble: nasm -felf64 syscalls.nasm
;  Link:     ld/gcc syscalls.o -o myexe 
;  usage:    ./myexe

Section .data
   msg db "Learning is fun with Arif", 0xA

Section .bss
;nothing here

SECTION .text
   global _start
   _start:
;display a message on stdout
      mov rax,1    ;system call ID of write
      mov rdi,1    ;file descriptor of stdout
      mov rsi,msg  ;message to be displayed
      mov rdx,26   ;length of the message
      syscall      ;write(fd, msg, size) 
;exit the program
      mov rax,60   ;system call ID of exit
      mov rdi,77
      syscall      ;exit(77)   
