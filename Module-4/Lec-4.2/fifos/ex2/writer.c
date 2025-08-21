/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  Program creates a named pipe, myfifo and
*  opens it in write mode and 
*  gets input from user and continuously writes in myfifo
*  usage: ./writer
*/
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
int main(){
   char buff[1024];  
   unlink("mkfifo");
   mknod("myfifo", S_IFIFO | 0666, 0);
   printf("Waiting for readers....\n");
   int writefd = open("myfifo", O_WRONLY); //will block until a reader opens it
   printf("Got a reader -- type some text to be sent\n");
   //read from stdin and write to the fifo
   while(fgets(buff, sizeof(buff), stdin)!= NULL) 
      write(writefd, buff, strlen(buff));
   close(writefd);
   return 0;  
}
