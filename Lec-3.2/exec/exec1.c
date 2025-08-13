/*
*  Video Lecture: 19
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Basic usage of execlp()
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
int main(){
   int status;
   pid_t cpid = fork();
   if (cpid == 0){
      execlp("ls", "myls", "-l", "/home/", NULL);
      printf("This line will not be printed\n");
   }
   else{
      wait(&status);
      printf("Hello I m Parent.\n");
   }
   return 0;
}
