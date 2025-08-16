/* file_io2.c
   Instructor: Arif Butt
   This program reads from standard input and writes to standard output.
   The program reads up to 255 bytes from standard input and writes them to standard output.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> // for STDIN_FILNO
int main()
{
   char buff[256];
   int n = read (STDIN_FILENO, buff, 255);
   write(STDOUT_FILENO, buff, n); 
   return 0;

}
