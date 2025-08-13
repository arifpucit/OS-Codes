/*
*  Video Lecture: 19
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Basic usage of execv()
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
extern char ** environ;
int main(){
   int status;
   pid_t cpid = fork();
   if (cpid == 0){
      char *argv[]={"myls","-l","/home",'\0'};
      execv("/bin/ls",argv);
      perror("exec failed");   
  }
   else{
      wait(&status);
      printf("Hello I m Parent.\n");
   }
   return 0;
}
