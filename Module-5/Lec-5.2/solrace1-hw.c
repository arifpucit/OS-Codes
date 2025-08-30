/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  solrace1-hw.c: The main() creates two threads,
*  one thread execute inc() and other execute dec()
*  both functions operate on a shared global variable balance
*  after achieving lock using mutex variable
*  Finally main thread displays the value of global variable
*  compile: $ gcc solrace1-hw.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
long balance = 0;//global variable
void * inc(void * arg);
void * dec(void * arg);
void acquire_lock();
void release_lock();
volatile int lock = 0;
int main(){
   pthread_t t1, t2;
   pthread_create(&t1, NULL, inc,NULL);
   pthread_create(&t2, NULL, dec,NULL);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   printf("Value of balance is :%ld\n", balance);
   return 0;
}

void * inc(void * arg){
   for(long i=0;i<100000000;i++){
      acquire_lock();
      balance++;
      release_lock();
   }
   pthread_exit(NULL);
}
void * dec(void * arg){
   for(long j=0;j<100000000;j++){
      acquire_lock();
      balance--;
      release_lock();
    }
   pthread_exit(NULL);
}

void acquire_lock(){
   while(1){
      int expected = 0;
      if(__sync_bool_compare_and_swap(&lock, expected, 1))
         break;
   }
}
void release_lock(){
   __sync_lock_release(&lock);
}
