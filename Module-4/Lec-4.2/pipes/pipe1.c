/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  pipe1.c
*  Use of pipe between two related processes
*  child is a reader process while parent is a writer process
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 1024
int main(){
   int fd[2];
   int rv = pipe(fd);
//create a child process
   pid_t cpid = fork();
//parent code (parent is writer process)
   if (cpid != 0) {
      close(fd[0]);
      const char * msg = "Welcome to data passing using pipe\n";
      write(fd[1], msg,strlen(msg));
      waitpid(cpid, NULL, 0);
      fprintf(stderr, "\nParent exiting...");
      exit(0);
   }
//child code (child is reader process)
   else { 
      close(fd[1]);
      char buff[SIZE];
      memset(buff, '\0',SIZE);
      read(fd[0], buff, SIZE);
      fprintf(stderr,"Message sent from parent is: "); 
      write(1, buff, SIZE);
      fprintf(stderr, "Child exiting...");
      exit(0);
   }
}
