/*
*  Video Lecture: 18
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Proves that after a vfork() call, child run in the address space of parent
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int gvar = 54; 
int main(){
   int lvar = 100;
   printf("Before fork()\n");
   pid_t cpid = vfork();
   if (cpid == 0){
      gvar++;
      lvar++;
      printf("I am child and I have incremented my gvar and lvar\n");
      printf("Global var= %d, Local var= %d\n",gvar,lvar);
      exit(0);
   }
   else{
      printf("\nI am parent now...\n");
      printf("Global var= %d, Local var= %d\n",gvar,lvar);
      exit(0);
   }
}
