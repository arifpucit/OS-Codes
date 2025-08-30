/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  attr2.c: 
*  compile: $ gcc attr2.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
void * f1(void * arg);
pthread_mutex_t mut;
int main(){
   pthread_mutexattr_t mutattr;
   pthread_mutexattr_init(&mutattr);
   pthread_mutexattr_settype(&mutattr, PTHREAD_MUTEX_ERRORCHECK_NP);
   pthread_mutex_init(&mut, &mutattr);
   pthread_t t1;
   pthread_create(&t1, NULL, f1,NULL);
   pthread_join(t1,NULL);
   printf("Bye Bye from main\n");
   return 0;
}
void * f1(void * arg){
   pthread_mutex_lock(&mut);
   pthread_mutex_lock(&mut);
   printf("Locking an already locked error checking mutex returns with error\n");
   pthread_mutex_unlock(&mut);
   pthread_exit(NULL);
}
