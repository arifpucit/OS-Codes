/*
*  Video Lecture: 23
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  t2.c: main thread creates two child threads and join them. 
*  One thread prints 1000 Xs and the other thread prints 800 Os 
*  and both executes concurrently.
*  compile: $ gcc t2.c -lpthread
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
int main(){
   pthread_t tid1, tid2;
//create two child threads
   pthread_create(&tid1, NULL, f1, NULL);
   pthread_create(&tid2, NULL, f2, NULL);
//join the two child threads
   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);
   printf("\nBye Bye from main thread\n");   
   return 0;
}

void * f1(void * arg){
   for(int i=0; i<1000; i++)
      fprintf(stderr, "%c", 'X');
   pthread_exit(NULL);
}
void * f2(void * arg){
   for(int i=0; i<800; i++)
      fprintf(stderr, "%c", 'O');
   pthread_exit(NULL);
}
