/*
*  Programmer: Arif Butt
*  Course: Operating System
*/

#include <unistd.h>
int main(){
   char str[]="Welcome to Operating System Arif Butt...\n";
   int rv = syscall(1, 1, str, sizeof str); 
   return rv;
}

