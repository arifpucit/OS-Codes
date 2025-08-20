/*
*  Programmer: Butt Arif
*  Course: Operating Systems
*  The process enters in an infinite loop, and use signal() to ignore SIGINT
*  When the user press <CTRL + C> the OS sends SIGINT<2> to the process
*  and the process ignores it and do not terminates
*/

#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
 signal(SIGINT,SIG_IGN);
 signal(SIGFPE, SIG_IGN);
 while(1) {
   printf("I am in an infinite loop!\n");
   printf("You can't kill me by SIGINT <2> or SIGFPE <8>\n");
   sleep(2);
 }
 return 0;
}
