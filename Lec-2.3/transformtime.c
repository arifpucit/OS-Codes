#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char* argv[])
{
   if (argc != 2){
      printf("usage- ./a.out n /n where n are the number of seconds.\n");
      exit(1);
   }
   long secs = atoi(argv[1]);
   printf("Date for %ld secs since epoch: %s\n",secs, ctime(&secs));
   return 0;
} 
