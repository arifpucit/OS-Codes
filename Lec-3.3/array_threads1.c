/*
*  Video Lecture: 23
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  array_threads1.c: The main() creates an array of 3 threads
*  Pass a message to each thread and the thread function displays it
*  compile: $ gcc array_threads1.c -lpthread
*  usage: $./a.out
*/
#include <sys/types.h>
#include <linux/unistd.h>
#include <errno.h>
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void * f1(void * arg);
int main(int argc, char* argv[]){
   char* msg[] = {"Thread1", "Thread2", "Thread3", "Thread4", "Thread5"};
   pthread_t tids[5];
   for(int i=0; i<5; i++){
      pthread_create(&tids[i], NULL, f1, (void*)msg[i]);
      pthread_join(tids[i], NULL);
   }
   printf("main(): Reporting that all child threads have terminated\n");
   exit(0);
}

void * f1(void * arg){
   printf("I am child %s\n", (char*)arg);
   pthread_exit(NULL);
}
