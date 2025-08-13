/* ex5.c
   This program reads from a file named "data.txt" and writes the content to standard output.
   It reads 255 bytes starting from the 5th byte of the file.
   If an error occurs while reading or writing, the program will terminate.
   The program uses the pread() system call to read from the file descriptor.
   The pread() function allows reading from a file at a specific offset without changing the file
   pointer, which is useful for reading from a specific position in the file.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for STDIN_FILNO
#include <fcntl.h>
int main()
{
   char buff[256];
   int fd = open("data.txt",O_RDONLY);
   int n = pread (fd, buff, 255,5);
   write(STDOUT_FILENO, buff, n); 
   return 0;

}
