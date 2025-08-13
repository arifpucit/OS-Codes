/*
*  Lecture: 1.4
*  Instructor: Arif Butt
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
//   printf("\n No of arguments passed:%d",argc);
   int i;
   printf("\n Environment variable passed are:\n");
   for (i = 0; envp[i] != NULL ; i++)
      printf("envp[%d]:%s\n", i, envp[i]);

   return 0;

}
