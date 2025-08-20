/*
*  Programmer: Arif Butt
*  Course: Operatin Systems
*  Parent process sends a signal to child process using kill()
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
   pid_t cpid = fork();
   if (cpid ==0){
      for(;;){
         printf("I am child in an infinite loop\n");
         sleep(1);
      }
   }
   else{
      sleep(5);
      kill(cpid,SIGSEGV);
      printf("I have killed my child... Bye\n");
      exit(0);
   }
}
