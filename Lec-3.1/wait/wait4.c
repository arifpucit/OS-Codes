/*
*  Video Lecture: 18
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use macros to decipher the status argument of wait() system call
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
void disp_status(int);
int main(){
   pid_t cpid = fork();
   if (cpid == 0){
      printf("I am child process and I am running...\n");
//      exit(7);
      int j = 0;
      int i = (2 / j);
 }
  else{
   int status;
   pid_t rv = wait (&status);
   printf ("Hello I m Parent.\n");
   disp_status(status);
   exit(54);
   }
}


void disp_status(int status){
//normal termination
if(WIFEXITED(status))
      printf("My child terminated normally with exit value %d\n", WEXITSTATUS(status));
//killed by a signal
  else if (WIFSIGNALED(status)){
     printf("My child was killed by Signal Number = %d\n",WTERMSIG(status));
     if(WCOREDUMP(status))
        printf("Core Dump file generated.\n");
}
//stopped by a signal
  else if (WIFSTOPPED(status))
     printf("My child was stopped by Signal Number = %d\n", WSTOPSIG(status));
//continued by SIGCONT
  else if (WIFCONTINUED(status))
printf("My child continued its execution due to SIGCONT\n");
}
