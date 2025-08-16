/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  id_threads.1c: main thread creates two child threads 
*  All the three threads displays their IDs using gettid()
*  and enter in an infinite loop
*  compile: $ gcc id_threads.c -lpthread
*  usage: $./a.out
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h> 
#include <errno.h> 
#include <unistd.h> 
#include <sys/types.h>
#include <sys/syscall.h>

void * f1(void *);
int main(){
   pthread_t tid1, tid2;
   printf("PID using getpid(): %ld\n",(long)getpid());
   printf("Main TID using gettid():%ld\n",(long)syscall(SYS_gettid));
   pthread_create(&tid1, NULL, f1, NULL);
   pthread_create(&tid2, NULL, f1, NULL);
   while(1);
   return 0;
}
void* f1(void* arg){
   printf("Child TID using gettid():%ld\n",(long)syscall(SYS_gettid));
   while(1);
   pthread_exit(NULL);
}
