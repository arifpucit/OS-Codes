/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  race3.c:
*  compile: $ gcc race3.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char** ptr;
void * thread_function(void * localarg);
int main(){
   pthread_t tid[2];
   int thread_ids[2] = {0,1};
   char* msg[2] = {"Hello from Arif", "Hello from PUCIT"};
   ptr = msg;
   for(int i=0;i<2;i++)
      pthread_create(&tid[i], NULL, thread_function, (void*)&thread_ids[i]);
   for(int i=0;i<2;i++)
      pthread_join(tid[i], NULL);
   return 0;
}


void * thread_function(void * localarg){
   int myid = *((int*)localarg);
   static int svar = 0; 
   printf("Thread %d starting...\n", myid);
//Instead of just svar++, I am making the CS longer to ensure more contention among threads   
   int temp = svar;           // Read
   usleep(10000);            // 10ms delay to increase race window
   temp = temp + 1;          // Modify  
   usleep(10000);            // Another delay
   svar = temp;              // Write back
  
   printf("[%d]: %s (svar = %d)\n", myid, ptr[myid], svar);
   printf("Thread %d finishing...\n", myid);
   pthread_exit(NULL);
}
