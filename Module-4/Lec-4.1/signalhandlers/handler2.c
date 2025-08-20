/*
*  Programmer: Butt Arif
*  Course: Operating Systems
*  The process registers three signal handlers and enters in a while(1) loop
*  On receipt of these signals, instead of default disposition
*  the appropriate signal handler function is called
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void sigint_handler(int signum){
  printf("\nHey, I got SIGINT: %d\n\n",signum);
  signal(SIGINT,SIG_DFL);
}
void sigquit_handler(int signum){
  printf("\nHey, I got SIGQUIT: %d\n\n",signum);
  signal(SIGQUIT,SIG_DFL);   
}
void sigtstp_handler(int signum){
  printf("\nHey, I got SIGTSTP: %d\n\n",signum);
  signal(SIGTSTP,SIG_DFL);   
}
        
int main(){
   signal(SIGINT,sigint_handler);
   signal(SIGQUIT, sigquit_handler);
   signal(SIGTSTP, sigtstp_handler);
   while(1) {
	printf("I am in an infinite loop!\n");
	sleep(1);
   }
   return 0;
}
