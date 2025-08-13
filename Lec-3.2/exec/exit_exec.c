/*
*  Video Lecture: 19
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Proof of concept: Exit handlers are not inherited after exec()
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
void exit_handler(){
   printf("Exit handler\n");
}
int main(){
   atexit(exit_handler);

pid_t cpid = fork();
   if (cpid == 0){
      execlp("/bin/ls", "myls", "/home", '\0');
      printf("This is child process.\n");
      exit(0);
   }
   else{
      wait(NULL);
      printf("This is parent process.\n");
      exit(0);
   }
}
