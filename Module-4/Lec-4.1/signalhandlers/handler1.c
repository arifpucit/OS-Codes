/*
*  Programmer: Butt Arif
*  Course: Operating Systems
*  The process registers a handler for SIGINT and enters in a while(1) loop
*  When the user presses <ctrl+c>, instead of default disposition
*  the signal handler function is called
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void  myhandler(int signum){
   printf("\nHey, I got a signal: %d\n\n",signum);
}

int main(){
   signal( SIGINT, &myhandler );
   while(1) {
	printf("I am in an infinite loop!\n");
	sleep(1);
   }
   return 0;
}
