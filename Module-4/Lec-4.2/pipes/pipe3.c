/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  Bidirectional communication using two pipes between two related processes
*  Parent writes first and child reads
*  Child writes later and parent reads
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

#define SIZE 1024
int main(){
   int fd1[2];
   int fd2[2];
   pipe(fd1);
   pipe(fd2);
//create a child process
   pid_t cpid = fork();
//***Child will read from fd2[0] and write into fd1[1] 
   if (cpid == 0) {
      close(fd1[0]);
      close(fd2[1]);
      char childbuff[SIZE];
      memset(childbuff, '\0',SIZE);
      const char *msgfromchild = "Zalaid Mujahid Butt";
//child receives a message from parent
      int n = read(fd2[0],childbuff,SIZE);
      printf("\nI am child.");
      printf("\nParent asked: "); 
      fflush(stdout);
      write(1,childbuff,n);    
//child sends a response to parent
      write(fd1[1],msgfromchild,strlen(msgfromchild));
      exit(0);
   }
//***Parent will write into fd2[1] and read from fd1[0]
   else {
      close(fd1[1]);
      close(fd2[0]);
      char parentbuff[SIZE];
      memset(parentbuff, '\0',SIZE);
      const char * msgfromparent = "What is your name child?";
//parent sends a message to child
      write(fd2[1], msgfromparent,strlen(msgfromparent));
//parent receives a message from child
      int n = read(fd1[0],parentbuff,SIZE); 
      printf("\n\nI am parent, and have received my child's name.");
      printf("\nWelcome Mr. ");
      fflush(stdout);
      write(1,parentbuff,n);
      printf("\n");
	   exit(0);
   }
}
