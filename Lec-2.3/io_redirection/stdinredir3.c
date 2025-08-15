/*
*  Programmer: Arif Butt
*  This program demonstrates how to redirect standard input using the open-dup2-close method.
*/

#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
int main(){
   char	line[100];
/* read and print one line from stdin */
   fgets(line, 100, stdin ); 
   printf("%s", line);
/* redirect stdin to passwd file using open-dup2-close*/
   int fd = open("/etc/passwd", O_RDONLY);
   int newfd = dup2(fd, 0);
   close(fd);		
/* read and print one line from stdin again*/
   fgets(line, 100, stdin); 
   printf("%s", line);
   return 0;
}

