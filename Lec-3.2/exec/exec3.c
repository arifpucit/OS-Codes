/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  Basic usage of execle()
*/
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <wait.h>
extern char ** environ;
int main(){
   int status;
   pid_t cpid = fork();
   if (cpid == 0){
      execle("/usr/bin/gnome-calculator","mycalc",NULL, environ);
      perror("exec failed");
   }
   else{
      wait(&status);
      printf("Hello I m Parent.\n");
   }
   return 0;
}
