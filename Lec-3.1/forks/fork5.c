/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Proves that both parent and child have their own copy of variables
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
   int i,cpid, ctr=0;
   cpid = fork();
   if (cpid == 0){
      ctr = 100;
      for (i = 0; i< 3; i++)
         printf("Child counter is:%d\n", ctr++);
   }
   else{
      for(i = 0; i< 3; i++)
         printf("Parent counter is:%d\n",ctr++);     
   }
   return 0;
}
