/*
*  Video Lecture: 18
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of wait() system call and retrieving the exit status
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
int main(){
   pid_t cpid = fork();
   if (cpid == 0){
      printf("Hello I m Child.\n");
      sleep(1);
      printf("I m Child again, and my PID is %ld\n", getpid());
      sleep(1);
      printf("I m Child again, and I am terminating...\n");
      sleep(1);
      exit(7);
   }
  else{
   int status;
   pid_t rv = wait (&status);
   printf ("Hello I m Parent.\n");
   int low_8 = status & 0xff;
   int high_8 = status >> 8;
   if(low_8 == 0)
   	printf("Return value of wait is %ld, and status is %d\n",rv, high_8);
   exit(54);
   }
}
