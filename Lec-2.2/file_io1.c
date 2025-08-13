/* ex1.c
   Programmer's name: Arif Butt
   This program reads from standard input and writes to standard output.
*/
#include <stdlib.h>
#include <unistd.h>

int main()
{
   char buff[256];
   read (0, buff, 255);
   write(1, buff, 255); 
   return 0;

}
