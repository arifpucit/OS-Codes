/*
*  Video Lecture: 18
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of waitpid() system call
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
      printf("I am child and my PID is %ld\n", getpid());
   while(1);
 }
  else{
   int status;
   pid_t rv = waitpid(cpid, &status, WUNTRACED | WCONTINUED);
   printf ("Hello I m Parent.\n");
   disp_status(status);
   exit(54);
   }
}


void disp_status(int status){
//normal termination
   int low_7 = status & 0x7f;
   int high_8 = status >> 8;
   if(low_7 == 0)
      printf("My child terminated normally with exit value %d\n", high_8);
//killed by a signal
   if(high_8 == 0)
      printf("My child was killed by Signal Number = %d\n", low_7);
   int bit_7 = status & 0x80;
   bit_7 = bit_7 >> 7;
   if(bit_7 == 1)
      printf("Core Dump file generated.");
//stopped by a signal
   if(low_7 == 0x7F)
      printf("My child was stopped by Signal Number = %d\n", high_8);
//continued by SIGCONT
   int low_16 = status & 0xffff;
   if(low_16 == 0xffff)
      printf("My child continued its execution due to SIGCONT\n");
}
