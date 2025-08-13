/*
*  Video Lecture: 16
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  mywrite.c: Open the terminal file for output and then read keyboard and write to the terminal file
 * shows: a terminal is just a file supporting regular i/o
 * usage: $./a.out /dev/pts/n 

*/
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
   if (argc != 2 ){
	fprintf(stderr,"usage: ./a.out ttyname\n");
	exit(1);
   }
   int fd = open(argv[1], 1);
   if (fd == -1){
	perror("open() failed"); 
        exit(1);
   }
   char	buf[512];	/* loop until EOF on input */
   while(fgets(buf, 512, stdin) != NULL )
      if (write(fd, buf, strlen(buf)) == -1 )
	break;
   close(fd);
   return 0;
}
