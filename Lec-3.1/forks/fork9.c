/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  A tricky example, fork() is called multiple times
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
