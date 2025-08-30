/*
*  Video Lecture: 32
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  counting_sems.c: Named Semaphores 
*  compile: $ gcc counting_sems.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>
void* f1(void* arg);
void* f2(void* arg);
sem_t *ctr;
int main(){
   char* name = "/sem1";
	ctr = sem_open(name, O_CREAT, 0666, 5);
   pthread_t tid[10];
   for(int i = 0; i<10; i++){
      pthread_create(&tid[i], NULL, f1, NULL);
      sleep(1);
   }
   for(int i = 0; i<10; i++)
      pthread_join(tid[i], NULL);
	sem_close(ctr);
   sem_unlink(name);
   return 0;
}
void* f1(void* arg){
   sem_wait(ctr);
   fprintf(stderr, "I am in the office of Arif\n");
   int val;
   sem_getvalue(ctr, &val);
   fprintf(stderr, "Semaphore = %ld\n", val);
   pthread_exit(NULL);
}
