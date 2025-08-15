/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  A tricky example, fork() is called multiple times with logical short circuiting AND operator
*/


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
   fork() && fork();
   fprintf(stderr, "%s\n","PUCIT");
   return 0;
}
