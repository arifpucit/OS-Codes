/*
*  Video Lecture: 32
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  race_serialize.c: The main() creates three threads,
*  each thread displays a string in a random fashion
*  compile: $ gcc race_serialize.c -lpthread -D_REENTRANT
*  usage: $./a.out 
*/

#include <pthread.h>
#include <semaphore.h>
#include <stdio.h>

void * f1(void *);
void * f2(void *);
void * f3(void *);
int main() {
   pthread_t t1, t2,t3;
   pthread_create(&t1, NULL, f1, NULL);
   pthread_create(&t2, NULL, f2, NULL);
   pthread_create(&t3, NULL, f3, NULL);
   pthread_join(t1, NULL);
   pthread_join(t2, NULL);
   pthread_join(t3, NULL);
   printf("\n");
   return 0;
}
void * f1(void * parm){
   printf(" Arif Butt");
}    
void * f2(void * parm){
   printf(" fun with");
}    
void * f3(void * parm){
   printf(" Learning is");
}    
