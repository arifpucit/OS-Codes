/* access.c
*  Programmer: Arif Butt
*  This program checks the existence and access permissions of a file specified on the command line.
*  It uses the `access` system call to check if the file exists, and if it has read, write, and execute permissions.
   Usage: ./access <filename>
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
//#include <fcntl.h> // if you are using constant O_RDONLY
//#include <sys/stat.h>
int main(int argc, char* argv[])
{
   if(argc != 2){
      fprintf(stderr, "Incorrect number of arguments\n");
      exit(1);
   }
   if (access(argv[1],F_OK) == 0)
      printf("This file exist\n");
   else{
      printf("This file do not exist\n");
      exit(1);
   }
   if (access(argv[1], R_OK) == 0)
      printf("You have read access to  this file\n");
   else
      printf("You do not have read access to this file\n");
   
   if (access(argv[1], W_OK) == 0)
      printf("You have write access to  this file\n");
   else
      printf("You do not have write access to this file\n");
   
   if (access(argv[1],X_OK) == 0)
      printf("You have execuete access to  this file\n");
   else
      printf("You do not have execute  access to this file\n");
   
   exit (0);
}
