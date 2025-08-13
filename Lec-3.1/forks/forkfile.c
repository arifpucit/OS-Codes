/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Proves that PPFDT of parent process is inherited in the child process
*  Proves that both points to the same entry in the SWFT (as cfo is shared)
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>

int main()
{
   int fd;
   char msg1[] = "System Programming is fun with Arif Butt\n";
   char msg2[] = "This is parent\n";
   char msg3[] = "This is child\n";
   fd = open("f1.txt", O_CREAT | O_WRONLY | O_TRUNC, 0644);
   if(fd==-1){
      printf("open failed\n");
      exit(1);
   }
   write(fd, msg1, strlen(msg1));
   int cpid = fork();
   if (cpid == 0)
      write(fd, msg3, strlen(msg3));
   else
      write(fd, msg2, strlen(msg2));
   close(fd);
   return 0;
}
