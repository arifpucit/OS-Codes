/*
*  Video Lecture: 23
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  t1.c: main thread creates two child threads and join them. 
*  One thread calls f1() and other calls f2()
*  f1() prints string PUCIT five times with a delay of 1 sec
*  f2() prints string ARIF five times with a delay of 1 sec
*  Both f1() and f2() executes concurrently.
*  compile: $ gcc t1.c -lpthread
*  usage: $ time ./a.out
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h> 
void * f1(void *);
void * f2(void *);
int main(){
   pthread_t tid1, tid2;
//create two child threads and wait for their termination
   pthread_create(&tid1, NULL, f1, NULL);
   pthread_create(&tid2, NULL, f2, NULL);
   pthread_join(tid1, NULL);
   pthread_join(tid2, NULL);
   printf("\nBye Bye from main thread\n");   
   return 0;
}

void * f1(void * arg){
   for(int i=0; i<5; i++){
      printf("%s", "PUCIT");
      fflush(stdout);
      sleep(1);
   }
   pthread_exit(NULL);
}
void * f2(void * arg){
   for(int i=0; i<5; i++){
      printf("%s", "ARIF");
      fflush(stdout);
      sleep(1);
   }
   return NULL;
}
