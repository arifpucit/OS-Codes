/*
*  Video Lecture: 19
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Writing your own system() function
*/
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int mysystem(char*);
int main(){
   printf("Running ls command using mysystem()\n\n");
   mysystem("ls -l /home");
   printf("\nDone... Bye\n");
   exit(0);
}
int mysystem(char * cmd){
   pid_t cpid = fork();
   switch(cpid){
      case -1:
	      perror("fork failed");
	      return -1;
      case 0:
	      execlp("/bin/bash", "mybash","-c", cmd, '\0');
	      perror("execlp() failed");
         return -2;
      default:
	      waitpid(cpid, NULL, 0);
	      return 0;
   }
}
