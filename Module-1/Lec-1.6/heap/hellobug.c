/*
*  Lecture: 1.6
*  Instructor: Arif Butt
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
extern int errno;
int main(){
   char * arr  = (char*) malloc (sizeof(char)*10);
   if(arr==NULL){
      perror("malloc failed:");
      exit(errno);
   }
   arr[0]='a';
   arr[1]='r';
   arr[2]='i';
   arr[3]='f';
   arr[4]='\0';
   printf("%s\n",arr);
   free(arr);
   arr[0] = 'b';
   return 0;
}
