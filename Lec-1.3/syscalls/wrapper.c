/*
*  Programmer: Arif Butt
*  Course: Operating System
* /usr/include/x86_64-linux-gnu/asm/unistd_64.h
*/
#include <unistd.h>
int main(){
   char str[]={"Welcome to learning OS with Arif Butt...\n"};
   int rv = write(1, str, sizeof str); 
   return rv;
}

