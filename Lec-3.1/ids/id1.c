/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
   printf("My PID is: %ld\n", (long)getpid());
   printf("My PPID is: %ld\n", (long)getppid());
   return 0;
}
