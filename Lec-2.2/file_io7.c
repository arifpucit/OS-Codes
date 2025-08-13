/* ex7.c
   Programmer's name: Arif Butt
   This program reads from standard input and writes to a file named "newdatafile.txt".
   It creates the file if that does not exist, truncates it if it does, and opens it in read-write mode.
   The program reads data from standard input and writes it to the file until an end-of-file (EOF) or error occurs.
   The file is created with permissions 0666, allowing read and write access for all users.
   The umask is set to  0 to ensure that the file is created with the specified permissions.
*/
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
int main()
{
  int n; char buff[1024];
  
  umask(0);
  int fd = open("newdatafile.txt",O_CREAT|O_TRUNC|O_RDWR,0666); //file opened in write mode
  if (fd == -1) {printf("Error in creating file\n"); exit(1);}
   for(;;)
   {
      n = read (0, buff, 1023);
      if (n<=0)    
      {
         printf("Error in reading source file.\n");
	      exit(-n);
      }
      write(fd, buff, n);
   }
   close(fd);
   return 0;
}
