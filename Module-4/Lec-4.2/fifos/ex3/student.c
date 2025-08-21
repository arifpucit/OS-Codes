/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  Program writes to a named pipe (fifo1) and then 
*  reads from another named pipe (fifo2)
*  usage: ./student
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/errno.h>
#define MESSAGE1 "\n\n\nThis is a message from student:\n\t This program is 2 difficult to understand sir!\n"

 int main(){
   char buff[1024];
   int readfd, writefd, n, size;
//open fifo1 for writing
   writefd = open ("/tmp/fifo1", 1); 
//open fifo2 for reading
   readfd = open ("/tmp/fifo2", 0); 
//Write a message in fifo1 to be sent to other process
   write(writefd, MESSAGE1, strlen(MESSAGE1) + 1); 
//Read a message from fifo2
   n = read(readfd, buff, 1024);

//Writes the msg sent by other program on screen
   write(1, buff, n);
   close (readfd);
   close (writefd);
//remove fifos now that we are done using them
   if(unlink("/tmp/fifo1") <0){
	perror("Client unlink FIFO1");
	exit (1);
   }
   if(unlink("/tmp/fifo2") <0){
	perror("Client unlink FIFO2");
	exit (1);
   }
   return 0;
}
