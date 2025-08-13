/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Describes  process fan
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>

int main(int argc, char *argv[])
{
   if(argc != 2){
      fprintf(stderr, "Incorrect number of arguments. Pl pass one integer\n");
      return 1;
   }
   
   int n = atoi(argv[1]);
   int i;
   for (i=1;i<=n;i++)
      if(fork() == 0){
         break;
      }
  fprintf(stderr, "PID=%ld, PPID=%ld\n",(long)getpid(), (long)getppid());
  while(1); 
   return 0;
}
