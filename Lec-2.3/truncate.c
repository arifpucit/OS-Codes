/*
*  truncate.c
*  Programmer: Arif Butt
*  This program truncates a file to a specified size.
*  Usage: ./a.out <filename> <new_size>
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main(int argc, char *argv[])
{
//ensure that user enters two cmd line parameters
   if (argc != 3)	{
		printf("Invalid number of arguments.\n");
		exit(1);
   }
    int fd, newfilesize, orig_size, trunc_size;
	newfilesize = atoi(argv[2]);
	fd = open(argv[1], O_WRONLY);
	orig_size = lseek(fd,0,SEEK_END);
//	truncate(argv[1], newfilesize);
	ftruncate(fd, newfilesize);
	trunc_size = lseek(fd, 0, SEEK_END);//size of truncated file
	printf("The size of original file is %d bytes.\n", orig_size);
	printf("The size of truncated file is %d bytes.\n", trunc_size);
	close(fd);
	
   return 0;
}
