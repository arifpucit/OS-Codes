/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  myread.c: Open the terminal file for reading
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
   int fd = open(argv[1], O_RDONLY);
   if (fd == -1){
	perror("open() failed"); 
        exit(1);
   }
   char	buf[512];	/* loop until EOF on input */
   ssize_t n;
   while((n=read(fd, buf, sizeof(buf)-1)) > 0){
      buf[n]='\0';
      printf("%s", buf);
      fflush(stdout);
   }
   close(fd);
   return 0;
}
