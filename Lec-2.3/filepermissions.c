/*
*  Video Lecture: 14
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  filepermissions.c: Receives file name via command line argument and display the nine characters of the permissions on the file
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char* argv[]){
   if(argc != 2){
      fprintf(stderr, "Incorrect number of arguments\n");
      exit(1);
   }
   struct stat buf;
   if (lstat(argv[1], &buf)<0){
      perror("Error in stat");
      exit(1);
   }
   int mode = buf.st_mode; 
   char str[10];
   strcpy(str, "---------");
//owner  permissions
   if((mode & 0000400) == 0000400) str[0] = 'r';
   if((mode & 0000200) == 0000200) str[1] = 'w';
   if((mode & 0000100) == 0000100) str[2] = 'x';
//group permissions
   if((mode & 0000040) == 0000040) str[3] = 'r';
   if((mode & 0000020) == 0000020) str[4] = 'w';
   if((mode & 0000010) == 0000010) str[5] = 'x';
//others  permissions
   if((mode & 0000004) == 0000004) str[6] = 'r';
   if((mode & 0000002) == 0000002) str[7] = 'w';
   if((mode & 0000001) == 0000001) str[8] = 'x';
//special  permissions
   if((mode & 0004000) == 0004000) str[2] = 's';
   if((mode & 0002000) == 0002000) str[5] = 's';
   if((mode & 0001000) == 0001000) str[8] = 't';
   printf("%s\n", str);
   return 0;
}
