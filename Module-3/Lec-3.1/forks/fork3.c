/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  Proves that parent and child execute the same code less the if-else structure
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   int cpid;
   cpid = fork();
   if (cpid == 0)
      printf("child here.\n");
   else
      printf("parent here.\n");
   printf("who is here.\n");
   return 0;
}
