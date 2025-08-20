/*
*  Programmer: Butt Arif
*  Course: Operating Systems
*  The process registers many signal handlers with one handler
*  and enters in a while(1) loop
*  On receipt of these signals, instead of default disposition
*  the the only handler function is called
*  which checks the signal number and acts appropriately
*/

#include <signal.h> 
#include <stdio.h>
#include <stdlib.h> 
#include <unistd.h>
void  myhandler(int signum){
   switch(signum){
      case SIGINT:
        printf("\nHey, I got SIGINT: %d\n\n",signum);
        break;
      case 3:
        printf("\nHey, I got SIGQUIT: %d\n\n",signum);
        break;
      case 20:
        printf("\nHey, I got SIGTSTP: %d\n\n",signum);
        break;
      case 8:
         printf("\nHey, I got SIGFPE: %d\n\n",signum);
         break;
      case 9:
        printf("\nHey, I got SIGKILL: %d\n\n",signum);
        break;
      case 19:
        printf("\nHey, I got SIGSTOP: %d\n\n",signum);
        break;
   }
}

int main(){
   signal(SIGINT,  myhandler);
   signal(SIGQUIT, myhandler);
   signal(SIGTSTP, myhandler);
   signal(SIGFPE,  myhandler);
   signal(SIGKILL, myhandler);
   signal(SIGSTOP, myhandler);
   while(1) {
	printf("I am in an infinite loop!\n");
	sleep(1);
   }
   return 0;
}
