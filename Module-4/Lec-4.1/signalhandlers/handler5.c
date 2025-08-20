/*
*  Programmer: Butt Arif
*  Course: Operating Systems
*  This sample program shows that the signal() call
*  returns the previous handler function
*/
#include <signal.h> 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void sighup1(int signum){
  printf("This is HANDLER - I for SIGHUP\n");
}
void sighup2(int signum){
  printf("This is HANDLER - II for SIGHUP\n");
}
   
int main(){
   void (*old)(int);
   signal(SIGHUP, sighup1);
   sleep(3);
   raise(SIGHUP);
   old = signal(SIGHUP, sighup2);
   sleep(3);
   raise(SIGHUP);
   signal(SIGHUP, old);
   sleep(3);
   raise(SIGHUP);
   signal(SIGHUP, SIG_DFL);
   sleep(3);
   raise(SIGHUP);
   sleep(100);
   return 0;
}
