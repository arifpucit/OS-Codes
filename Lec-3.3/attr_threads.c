/*
*  Video Lecture: 23
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  attr_threads.c: Creates a thread with attributes different than default
*  only change one attribute and that is a detached thread
*  compile: $ gcc attr_threads.c -lpthread
*  usage: $./a.out
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void* f1(void *);
int thread_finished = 0;
int main(){
   pthread_t tid;
//create a pthread attribute object
   pthread_attr_t thread_attr;
//Initialize the pthread attribute object 
   pthread_attr_init(&thread_attr);
//Modify the attribute object to contain the desired attribute(s)
   pthread_attr_setdetachstate(&thread_attr, PTHREAD_CREATE_DETACHED);
//Create thread with modified attributes
   pthread_create(&tid, &thread_attr, f1, NULL);
//Destroy pthread attribute object
   pthread_attr_destroy(&thread_attr);
   while(thread_finished == 0){
      printf("Waiting for child thread to finish...\n");
      sleep(2);
   }
   printf("Main thread exiting,Bye!\n");
   return 0;
}

void * f1(void* args){
   printf("Child thread is running...\n");
   sleep(8);
   printf("Child thread setting the finished flag, and exiting.\n");
   thread_finished = 1;
   pthread_exit(NULL);
}
