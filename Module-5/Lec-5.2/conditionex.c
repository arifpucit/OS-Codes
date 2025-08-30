/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  conditionex.c: Demonstrate the use of condition variable
 * The main thread creates a child thread which decrements a shared variable.
 * The main thread waits for a condition i.e. till the shared variable becomes zero
*  compile: $ gcc conditionex.c -lpthread
*  usage: $./a.out 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

pthread_mutex_t mutex;  
pthread_cond_t is_zero;   
long long  shared_data = 100000000;  
void* thread_function(void*);
int main (){
   pthread_t tid;
   pthread_cond_init(&is_zero, NULL);
   pthread_mutex_init(&mutex, NULL);
   pthread_create (&tid, NULL, thread_function, NULL);
//main thread waits till the shared data reaches zero
   pthread_mutex_lock(&mutex);
   if (shared_data != 0) 
      pthread_cond_wait(&is_zero, &mutex);
   pthread_mutex_unlock(&mutex);
    
   printf("shared_data = %lld \n", shared_data);
   pthread_mutex_destroy(&mutex);
   pthread_cond_destroy(&is_zero);
   return 0;
}
void* thread_function(void* arg){
   while(shared_data > 0){
      pthread_mutex_lock(&mutex);
      shared_data--;   
      pthread_mutex_unlock(&mutex);
   }
   pthread_cond_signal(&is_zero);
   return NULL;
}
