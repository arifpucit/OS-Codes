/* file_io4.c
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
   int n1 = read (0, buff, 255);
   if (n1 == -1){
      perror("Error in reading file\n");
      exit(1);
   }
   int n2 = write(1, buff, n1); 
   if(n2 == -1){
      perror("Error in writing file\n");
      exit(1);
   }
   }
   return 0;

}
