/*
*  Video Lecture: 19
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Basic usage of execle()
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <wait.h>

int execute(char**);
int main(){
   char	*arglist[10];
   arglist[0] = "/bin/ls";
   arglist[1] = "-l";
   arglist[2] = "/home";
   arglist[2] = NULL;
   int rv = execute(arglist);
   return rv;
}

int execute(char *arglist[]){
   int status;
   pid_t cpid = fork();				
   switch(cpid){
      case -1:
         perror("fork failed");
         exit(1);
      case 0:
         execvp(arglist[0], arglist);
         perror("execvp failed");
	      exit(1);
      default:
	      waitpid(cpid, &status, 0);
         status = status >> 8;
         printf("Child exited with status %d\n", status);
         return status;
   }
}
