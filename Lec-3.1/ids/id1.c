/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
   printf("My PID is: %ld\n", (long)getpid());
   printf("My PPID is: %ld\n", (long)getppid());
   return 0;
}
