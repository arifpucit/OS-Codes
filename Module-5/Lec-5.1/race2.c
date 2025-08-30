/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  rv2.c: The main() receives two file names via cmd line arg
*  Creates two threads and pass each a filename
*  Each thread update a global variable for the number of xters counted
*  in the two files
*  Finally main thread displays the character count
*  compile: $ gcc race2.c -lpthread
*  usage: $./a.out <file1> <file2> 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
int wordcount = 0;
void* f1(void * arg);
int main(int argc, char* argv[]){
   if(argc != 3){
      printf("Invalid number of arguments. Must pass two file names.\n");
      exit(1);
   }
   pthread_t tid1, tid2;
   pthread_create(&tid1, NULL, f1, (void*)argv[1]);
   pthread_create(&tid2, NULL, f1, (void*)argv[2]);
   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);
   printf("Number of characters in both files: %d\n", wordcount);
   return 0;
}
void* f1(void* args){
   char* filename = (char*)args;
   char ch;
   int fd = open(filename, O_RDONLY);
   while((read(fd, &ch, 1)) != 0){ 
	   wordcount++;
   }
   close(fd);
   pthread_exit(NULL);
}
