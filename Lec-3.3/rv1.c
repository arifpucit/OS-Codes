/*
*  Video Lecture: 23
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  rv1.c: The main() receives two numbers via cmd line arg
*  Creates two threads and pass one number to each
*  Each thread computes the nth prime number and the result
*  Finally main thread displays the two prime numbers
*  compile: $ gcc rv1.c -lpthread -lm
*  usage: $./a.out <n1> <n2> 
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <math.h>
void* f1(void *);
int main(int argc, char* argv[]){
   if (argc != 3){
      printf("Invalid arguments. Pl enter two integers\n");
      exit(1);
   }
   int num1 = atoi(argv[1]);
   int num2 = atoi(argv[2]);
   pthread_t tid1, tid2;
   pthread_create(&tid1, NULL, f1, (void*)&num1);
   pthread_create(&tid2, NULL, f1, (void*)&num2);
   void* rv1, *rv2;
   pthread_join(tid1, &rv1);
   pthread_join(tid2, &rv2);
   long prime1 = *(long*)rv1;
   long prime2 = *(long*)rv2;
   printf("\nThe %dth prime number as returned by child thread is: %ld\n",num1,prime1);
printf("\nThe %dth prime number as returned by child thread is: %ld\n",num2,prime2);
   return 0;
}

void * f1(void * args){
   int n = *((int*)args);
   long *candidate = (long*)malloc(sizeof(long));
   *candidate = 2;
   while(1){
      long factor;
      int is_prime = 1;
      for (factor = 2; factor <= sqrt((*candidate)); ++factor){
         if((*candidate)%2 == 0)
            { is_prime = 0; break; }
         if((*candidate) % factor == 0)
            { is_prime = 0; break; }
      }//end of for loop
      if(is_prime == 1)
         n--;
      if(n == 0)
         pthread_exit((void*)(candidate));
      ++(*candidate);
   }//end of while loop
}
