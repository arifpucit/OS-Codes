/*
*  Lecture: 1.6
*  Instructor: Arif Butt
*/
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
   int i;
   printf("\n Environment variable passed are:\n");
   for (i = 0; envp[i] != NULL ; i++)
      printf("envp[%d]:%s\n", i, envp[i]);

   return 0;

}
