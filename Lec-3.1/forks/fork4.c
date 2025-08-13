/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Proves that the child inherits the copy of variables of the parent
*/

#include <stdio.h>
#include <unistd.h>

int gvar=555;
int main()
{
   int lvar = 54;
   int cpid = fork();
if (cpid == 0)
       printf("I am child process with PID=%ld, gvar=%d, lvar=%d a\n", (long)getpid(),gvar,lvar);
   else 
       printf("I am parent process with PID=%ld, gvar=%d, lvar=%d\n", (long)getpid(),gvar,lvar);
   
   return 0;
}
