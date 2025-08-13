/* ex8.c
   Programmer's name: Arif Butt
   This program reads the file given on command line 
   and copies its contents in another file whose name is received on cmd line
   prog6 srcfile destfile
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int main(int argc, char *argv[])
{
//ensure that user enters two cmd line parameters
   if (argc != 3)	{
		printf("Invalid number of arguments.\n Enter source file name and then destination file name.");
		exit(1);
   }
   char buff[1024];
//create the target file descriptor in read write mode
  int destfd = open(argv[2],O_CREAT|O_RDWR|O_TRUNC, 00600); //file opened in write mode
  if (destfd<0){perror("open dest");exit(1);}
//open the source file descriptor in read mode
  int srcfd = open (argv[1], O_RDONLY);//file opened in read mode
  if (srcfd<0){perror("open src");exit(1);}
   int n;

//read the source file and write in the destination file
   for(;;)
   {
      n = read (srcfd, buff, 1024);
      if (n <= 0) {close(srcfd); close(destfd); return 0;}
      write(destfd, buff, n);
   }
  // close(srcfd);
  // close(destfd);
  // return 0;
}
