/*
*  Video Lecture: 23
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  rv2.c: The main() receives two file names via cmd line arg
*  Creates two threads and pass each a filename
*  Each thread computes and return the number of xters in the file
*  Finally main thread displays the character count
*  compile: $ gcc rv2.c -lpthread
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

void* f1(void * arg);
int main(int argc, char* argv[]){
   if(argc != 3){
      printf("Invalid number of arguments. Must pass two file names.\n");
      exit(1);
   }
   pthread_t tid1, tid2;
   void *rv1, *rv2;
   pthread_create(&tid1, NULL, f1, (void*)argv[1]);
   pthread_create(&tid2, NULL, f1, (void*)argv[2]);
   pthread_join(tid1, &rv1);
   pthread_join(tid2, &rv2);
   int count1 = *((int*)rv1);
   int count2 = *((int*)rv2);
   printf("Characters in %s: %d\n", argv[1], count1);
   printf("Characters in %s: %d\n", argv[2], count2);
   return 0;
}
void* f1(void* args){
   char* filename = (char*)args;
   int *result = (int*)malloc(sizeof(int));
   *result = 0;
   char ch;
   int fd = open(filename, O_RDONLY);
   while((read(fd, &ch, 1)) != 0){ 
	   (*result)++;
   }
   close(fd);
   pthread_exit((void*)result);
}
