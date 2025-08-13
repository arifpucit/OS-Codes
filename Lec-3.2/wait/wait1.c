/*
*  Video Lecture: 18
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Use of wait() system call
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
   printf("Return value of wait is %ld, and status is %d\n",rv,status);
   exit(54);
   }
}
