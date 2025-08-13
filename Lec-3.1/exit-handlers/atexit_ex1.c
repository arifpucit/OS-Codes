/*
*  Video Lecture: 08
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>   //for perror function
#include <stdlib.h> //for exit and atexit function
#include <unistd.h> //for _exit system call

void exit_handler(){
   printf("Exit handler\n");
}
int main(){
   atexit(exit_handler);
   printf("Main is done!\n");
  // return 0; // or exit(0);
   _exit(0);
}
