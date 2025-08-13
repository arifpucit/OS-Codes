/*
*  Video Lecture: 08
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>   //for perror function
#include <stdlib.h> //for exit and atexit function
#include <unistd.h> //for _exit system call

void myexit1(){
   printf("First exit handler\n");
}

void myexit2(){
   printf("Second exit handler\n");
}

int main(){
   atexit(myexit1);
   atexit(myexit1);
   atexit(myexit2);
   printf("Main is done!\n");
   exit(0);
}
