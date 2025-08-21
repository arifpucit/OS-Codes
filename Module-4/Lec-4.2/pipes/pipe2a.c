/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  A program that simulate following shell command
*  ls | wc
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
   int fd[2];
   pipe(fd);
   pid_t cpid = fork();
   if (cpid != 0){  //parent process (ls)
      close(fd[0]); //not required so better close it
      dup2(fd[1], 1); //redirect stdout to write end of pipe
      close(fd[1]);  //close original write end
      execlp("ls","myls", NULL);
      wait(NULL);   //dead code
   }
   else{  //child process (wc)
      close(fd[1]);  //not required so better close it
      dup2(fd[0], 0); //redirect stdin to read end of pipe
      close(fd[0]);  //close original read end
      execlp("wc","mywc", NULL);
   }
}
