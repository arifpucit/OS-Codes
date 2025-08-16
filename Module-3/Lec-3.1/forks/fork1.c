/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  A hello world program on fork, note the parent executes first, then the shell and then the child
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   int cpid = fork();
   if (cpid == 0)
       printf("Hello I am child\n");
   else 
       printf("Hello I am parent\n");
   return 0;
}

