/*
*  Lecture: 1.4
*  Instructor: Arif Butt
*/
#include <stdio.h>
#include <stdlib.h>
extern char **environ;
int main()
{

    printf("\n Environment variable passed are:\n");
   for (int i = 0; environ[i] != NULL ; i++)
      printf("environ[%d]:%s\n", i, environ[i]);

   return 0;

}
