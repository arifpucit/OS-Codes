/*
*  Programmer: Arif Butt
*  Course: Operatin Systems
*  Process sends itself SIGHUP using kill(), or using raise()
*/
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
int main(){
   printf("After five seconds, I will get a SIGHUP signal\n"); 
   sleep(5);
   kill(getpid(),1);
//   raise(1);
   printf("This will not be printed");
   return 0;
}
