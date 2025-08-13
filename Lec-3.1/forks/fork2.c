/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Proves that both the child and parent executes concurrently
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   int cpid = fork();
   if (cpid == 0)
      while(1) putchar('x');
   else
      while(1) putc('o', stdout);
   return 0;
}
