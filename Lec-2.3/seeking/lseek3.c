/*
*  Programmer: Arif Butt
*  This program creates a file with holes in it by writing data at specific offsets.

	Usage: ./a.out <number_of_holes>
	$ ls -l data
	$ ./a.out data 3
	$ ls -l data
	$ less data
	$ od data | less
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main(int argc, char *argv[]){
   int holes = atoi(argv[1]);
	int fd = open("filewithholes",O_CREAT|O_WRONLY|O_TRUNC, 0644);
	write(fd, "PUCIT", 5);
	for(int i = 0; i < holes; i++){
		lseek(fd, 10, SEEK_CUR);
		write(fd, "PUCIT", 5);
	}
	close(fd);
   return 0;
}
