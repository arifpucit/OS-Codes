/*
*  Video Lecture: 32
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  sol_serialize.c: The main() creates three threads,
*  each thread displays a string in a serialized fashion
*  compile: $ gcc sol_serialize.c -lpthread -D_REENTRANT
*  usage: $./a.out 
*/
#include <pthread.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <semaphore.h>

void * f1(void *);
void * f2(void *);
void * f3(void *);
sem_t *semA, *semB;
int main() {
   char* name1 = "/sem1";
   char* name2 = "/sem2";
	semA = sem_open(name1, O_CREAT, 0666, 0);
   semB = sem_open(name2, O_CREAT, 0666, 0);
   pthread_t t1, t2,t3;
   pthread_create(&t1, NULL, f1, NULL);
   pthread_create(&t2, NULL, f2, NULL);
   pthread_create(&t3, NULL, f3, NULL);
   pthread_join(t1, NULL);
   pthread_join(t2, NULL);
   pthread_join(t3, NULL);
while(1);
   sem_close(semA);
   sem_close(semB);
   sem_unlink(name1);
   sem_unlink(name2);
   printf("\n");
  return 0;
}
void * f1(void * parm){
   sem_wait(semB);
   fprintf(stderr, " Arif Butt");
}    
void * f2(void * parm){
   sem_wait(semA);
   fprintf(stderr, " fun with");
   sem_post(semB);
}    
void * f3(void * parm){
   fprintf(stderr," Learning is");
   sem_post(semA);
}    
