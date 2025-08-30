/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  serialize2.c: The main() creates three threads,
*  each thread displays a string, but now in a serialized fashion using condition variables
*  compile: $ gcc serialize2.c -lpthread -D_REENTRANT
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER; //protects shared state
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;    //condition variable for signaling
int turn = 1;  // Controls execution order (1, 2 and then 3)
void * f1(void * arg);

int main(){
   pthread_t t1, t2, t3;
   int id1=1, id2=2, id3=3;
   pthread_create(&t1, NULL, f1, (void*)&id1);  // Pass thread number
   pthread_create(&t2, NULL, f1, (void*)&id2);
   pthread_create(&t3, NULL, f1, (void*)&id3);
   
   pthread_join(t1, NULL);
   pthread_join(t2, NULL);
   pthread_join(t3, NULL);
   printf("\n\n");
   return 0;
}
/*
* Thread 1 prints "Learning is ", and then sets turn=2, and signal others
* Thread 2 wakes up, prints "fun with ", sets turn=3, and signal others
* Thread 3 wakes up, prints "Arif Butt", sets turn=2, and signal others
*/
void * f1(void * arg){
   int tid = *(int*)(long)arg;
   char* messages[] = {"", "Learning is ", "fun with ", "Arif Butt"};
   pthread_mutex_lock(&mutex);
   while(turn != tid)     //wait until it's this thread's turn
       pthread_cond_wait(&cond, &mutex);
       
   usleep(100000);
   fprintf(stderr, "%s", messages[tid]); //print message
   
   turn++;  //increase the turn
   pthread_cond_broadcast(&cond);//signal next thread
   pthread_mutex_unlock(&mutex);
   
   pthread_exit(NULL);
}
