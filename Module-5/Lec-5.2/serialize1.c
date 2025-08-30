/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  serialize1.c: The main() creates three threads,
*  each thread displays a string
*  compile: $ gcc serialize1.c -lpthread -D_REENTRANT
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
void * f1(void * arg);
int main(){
   pthread_t t1, t2, t3;
   int id1=1, id2=2, id3=3;
   pthread_create(&t1, NULL, f1, (void*)&id1); //pass thread no
   pthread_create(&t2, NULL, f1, (void*)&id2);
   pthread_create(&t3, NULL, f1, (void*)&id3);
   pthread_join(t1,NULL);
   pthread_join(t2,NULL);
   pthread_join(t3,NULL);
   printf("\n\n");
   return 0;
}
void * f1(void * arg){
   int tid = *(int*)arg;
   char* messages[] = {"", "Learning is ", "fun with ", "Arif Butt"};
   usleep(100000);
   fprintf(stderr, "%s", messages[tid]); //print message
   pthread_exit(NULL);
}
