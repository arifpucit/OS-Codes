/* file_io3.c
   Instructor: Arif Butt
   This program reads from standard input and writes to standard output.
   It reads up to 255 bytes from standard input and writes them to standard output.
   The program continues to read and write until the end of the input is reached.
   If an error occurs while reading or writing, the program will terminate.
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
   char buff[256];
   while(1){
   int n = read (0, buff, 255);
   write(1, buff, n); 
   }
   return 0;

}
