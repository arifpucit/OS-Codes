/*
*  Video Lecture: 23
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  t3.c: main thread creates two child threads and join them. 
*  The main thread pass an integer value to each thred function 
*  which is the count of the characters to be printed. 
*  Both executes concurrently.
*  compile: $ gcc t3.c -lpthread
*  usage: $./a.out
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> 
extern int errno;
void * f1(void *);
void * f2(void *);
int main(int argc, char* argv[]){
   int countofX = atoi(argv[1]);
   int countofO = atoi(argv[2]); 
   pthread_t tid1, tid2;
//create the two child threads
   pthread_create(&tid1, NULL, f1, (void*)&countofX);
   pthread_create(&tid2, NULL, f2, (void*)&countofO);
//joing the two child threads   
   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);
   printf("\nBye Bye from main thread\n");
   return 0;
}

void * f1(void * arg){
   int ctr = *((int*)arg);
   for(int i=0; i<ctr; i++)
      fprintf(stderr, "%c", 'X');
   pthread_exit(NULL);
}
void * f2(void * arg){
   int ctr = *((int*)arg);
   for(int i=0; i<ctr; i++)
      fprintf(stderr, "%c", 'O');
   pthread_exit(NULL);
}
