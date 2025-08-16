/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  array_threads2.c: The main() receives an integer via command line arg
*  Creates that much number of child threads
*  Pass thread number to each thread and it displays that number
*  compile: $ gcc array_threads2.c -lpthread
*  usage: $./a.out <5>
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
   if(argc != 2){
      printf("Invalid arguments, must pass one integer value...\n");
      exit(1);
   }
   int ctr = atoi(argv[1]);
   pthread_t* tid =  (pthread_t*)malloc(sizeof(pthread_t)*ctr);
   for(int i=0;i<ctr;i++){
      pthread_create(&tid[i], NULL, f1, (void*)&i);
      pthread_join(tid[i], NULL);
}
   printf("main(): Reporting that all child threads have terminated\n");
   exit(0);
}

void * f1(void * arg){
   int i = *((int*)arg);
   printf("I am child thread number %d \n", i);
   pthread_exit(NULL);
}
