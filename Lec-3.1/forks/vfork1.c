/*
*  Video Lecture: 18
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Proves that after a vfork() call, child execute first and the parent automatically waits, and starts its execution after the child terminates
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
   pid_t cpid = vfork();
   if (cpid == 0){
      sleep(1);
      printf("Hello I am child..\n");
      sleep(2);
      printf("Hello I am child again, I am exitting.\n");
      sleep(2);
      exit(0);
   }
   else{
      printf("\nHello I am parent, my child has terminated\n");
      exit(0);
   }
}
