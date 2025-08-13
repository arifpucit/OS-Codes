/*
*  Video Lecture: 18
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Proves that vfork() is efficient than fork() system call
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(){
   for(int i = 0; i < 100; i++){
      fork();
//      vfork();
   }
   exit(0);
   }
