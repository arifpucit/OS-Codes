/*
*  Video Lecture: 32
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  solrace_threads.c: (Un-named Semaphores) The main() creates two threads,
*  one thread execute inc() and other execute dec()
*  both functions operate on a shared global variable balance
*  after achieving lock using mutex variable
*  Finally main thread displays the value of global variable
*  compile: $ gcc solrace_threads.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <semaphore.h>
long balance = 0;//global variable
void * inc(void * arg);
void * dec(void * arg);
sem_t mutex;
int main(){
   sem_init(&mutex, 0, 1); //initializing semaphore
   pthread_t t1, t2;
   pthread_create(&t1, NULL, inc,NULL);
   pthread_create(&t2, NULL, dec,NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
	sem_destroy(&mutex);
   printf("Value of balance is :%ld\n", balance);
   return 0;
}
void * inc(void * arg){
   for(long i=0;i<10000000;i++){
      sem_wait(&mutex);
		balance++;
		sem_post(&mutex);
   }
   pthread_exit(NULL);
}
void * dec(void * arg){
   for(long j=0;j<10000000;j++){
      sem_wait(&mutex);
		balance--;
		sem_post(&mutex);
    }
   pthread_exit(NULL);
}
