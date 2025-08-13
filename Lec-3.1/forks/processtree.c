/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Describes  process tree
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if(argc != 2){
      fprintf(stderr, "Incorrect number of arguments. Pl pass one integer\n");
      return 1;
   }
   pid_t cpid;
   int n = atoi(argv[1]);
   int i;
   for (i=1;i<=n;i++){
      fork();
}
//   fflush(0);
   fprintf(stderr,"PID=%ld, PPID=%ld\n",(long)getpid(), (long)getppid());
while(1);
   return 0;
}
