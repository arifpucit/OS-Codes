/*
*  Video Lecture: 14
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  filetype.c: Receives file name via command line argument and determines the file type
   
*/
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h> // if you are using constant O_RDONLY
#include <sys/stat.h>
int main(int argc, char* argv[])
{
   if(argc != 2){
      fprintf(stderr, "Incorrect number of arguments\n");
      exit(1);
   }
   struct stat buf;
   if (lstat(argv[1], &buf)<0){
      perror("Error in stat");
      exit(1);
   }
   if ((buf.st_mode &  0170000) == 0010000) 
		printf("%s is a Named Pipe\n", argv[1]);
   else if ((buf.st_mode &  0170000) == 0020000) 
		printf("%s is a Character Special file\n", argv[1]);
   else if ((buf.st_mode &  0170000) == 0040000) 
		printf("%s is a Directory\n", argv[1]);
   else if ((buf.st_mode &  0170000) == 0060000) 
		printf("%s is a Block Special file\n", argv[1]);
   else if ((buf.st_mode &  0170000) == 0100000) 
		printf("%s is a Regular file\n", argv[1]);
   else if ((buf.st_mode &  0170000) == 0120000) 
		printf("%s is a Soft link\n", argv[1]);
   else if ((buf.st_mode &  0170000) == 0140000) 
		printf("%s is a Socket\n", argv[1]);
   else 
		printf("Unknwon mode\n");
   
   return 0;
}
