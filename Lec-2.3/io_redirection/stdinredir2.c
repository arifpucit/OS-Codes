/*
*  Programmer: Arif Butt
*  This program demonstrates how to redirect standard input using the open-close-dup-close method.
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
/* redirect stdin to passwd file using open-close-dup-close*/
   int fd = open("/etc/passwd", O_RDONLY);
   close(0);
   int newfd = dup(fd);
   close(fd);
/* read and print one line from stdin again*/
   fgets(line, 100, stdin); 
   printf("%s", line);
   return 0;
}
