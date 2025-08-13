/* ex6.c
   Programmer's name: Arif Butt
   This program is an example of reading a file using the system calls read() and write().
   It reads the contents of the file /etc/passwd and displays it on the standard output.
   It uses the open() system call to open the file in read mode, read() to read the contents,
   and write() to display the contents on the standard output.
   The program continues to read and write until the end of the file is reached.
   If an error occurs while reading or writing, the program will terminate.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h> // if you are using constant O_RDONLY
int main()
{
   char buff[2000];
   int fd = open ("/etc/passwd", O_RDONLY);//file opened in read mode
   int n;
   for(;;)
   {
      n = read (fd, buff, 1000);
      if (n <= 0){
         close(fd);
	 return 0;
      }
      write(1, buff, n);
   }
   return 0;
}
