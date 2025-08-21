/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  A program that simulate following shell command
*  ls /home | wc -l
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
   int fd[2];
   pipe(fd);
   
   //Parent do a first fork to execute ls /home
   if (fork() == 0){
      dup2(fd[1], 1);
      close(fd[0]);
      close(fd[1]);
      char *args[] = {"ls", "/home", NULL};
      execvp(args[0], args);
   }

   //parent do a second fork and make the child to execute wc -l 
   pid_t cpid2 = fork();
   if (cpid2 == 0){  //process wc (child -l)
      dup2(fd[0], 0);
      close(fd[0]);
      close(fd[1]);
      char *args[] = {"wc", "-l", NULL};
      execvp(args[0], args);
   }
   //parent process: close both ends of pipe
   close(fd[0]);
   close(fd[1]);
   //parent process wait for termination of both its children
   wait(NULL);
   wait(NULL);
   fprintf(stderr, "Parent: Both children have completed their task.\n");
   return 0;  
}
