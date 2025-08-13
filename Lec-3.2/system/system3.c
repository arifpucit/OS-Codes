/*
*  Video Lecture: 19
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  A shell interpreter using system()
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
   char cmd[50];
   int cpid;
   do{
      printf("PUCIT:- ");
      fgets(cmd, 50,stdin);
      system(cmd);
   }while(1);
   return 0;
}
