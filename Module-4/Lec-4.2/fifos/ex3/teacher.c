/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  Program creates two named pipes, fifo1 and fifo2
*  reads from fifo1 and then writes to the fifo2
*  usage: ./teacher
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/errno.h>
#define MESSAGE2 "\nResponse from Teacher: \n\tThere is no short cut to hard work! So WORK HARD....\n\n\n\n"

 
int main(){
   char buff[1024];
   int rv, readfd, writefd, n, size;
   unlink("/tmp/fifo1");   
   unlink("/tmp/fifo2");
   mknod("/tmp/fifo1", S_IFIFO | 0666, 0);
   mkfifo("/tmp/fifo2", 0666);
//Open fifo1 for reading purpose
   readfd = open ("/tmp/fifo1", 0);
//Open fifo2 for writing purpose
   writefd = open ("/tmp/fifo2", 1);
//Make a blocking call on fifo1
   n=read(readfd, buff, 1024);
//Display that message on screen
   write(1, buff, n);
//Send a response to other program via fifo2
   sleep(20);
   write(writefd, MESSAGE2, strlen(MESSAGE2) + 1);
   close (readfd);
   close (writefd);
   return 0;
}
