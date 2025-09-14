/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  race1.c: The main() creates two threads,
*  one thread execute inc() and other execute dec()
*  both functions operate on a shared global variable balance
*  Finally main thread displays the value of global variable
*  compile: $ gcc race1.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

long balance = 0;//global variable
void * inc(void * arg);
void * dec(void * arg);
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
//Instead of incrementing large number of time in a loop, I am making the CS longer to ensure more contention among threads   
   int temp = balance;           // Read
   usleep(10000);            // 10ms delay to increase race window
   temp = temp + 1;          // Modify  
   usleep(10000);            // Another delay
   balance = temp;              // Write back
   pthread_exit(NULL);
}
void * dec(void * arg){
//Instead of decrementing large number of times in a loop, I am making the CS longer to ensure more contention among threads   
   int temp = balance;           // Read
   usleep(10000);            // 10ms delay to increase race window
   temp = temp - 1;          // Modify  
   usleep(10000);            // Another delay
   balance = temp;              // Write back
   pthread_exit(NULL);
}
