/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  dyn_threads2.c: The main() receives an integer via command line arg
*  Creates two integer arrays of that size in heap
*  Get input in the two arrays from user
*  Create the size number of threads for addition of two location of the arrays
*  Each thread sum up two numbers and place the sum in third array
*  compile: $ gcc dyn_threads2.c -lpthread
*  usage: $./a.out <5>
*/

#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>  //exit
#include <math.h>
#include <unistd.h>

void * f1(void *);
int *arr1;
int *arr2;
int *result;
int main(int argc, char* argv[]){
   if(argc != 2){
      printf("Invalid arguments, must pass one integer value...\n");
      exit(1);
   }
   int size = atoi(argv[1]);
   //allocate memory for three integer arrays on heap
   arr1   = (int*)malloc(sizeof(int)*size);
   arr2   = (int*)malloc(sizeof(int)*size);
   result = (int*)malloc(sizeof(int)*size);
   //get input from user
   printf("\nEnter  %d values for array1\n",size);
   for(int i=0; i<size; i++)
      scanf("%d",&arr1[i]);
   printf("\nEnter  %d values for array2\n", size);
   for(int i=0; i<size; i++)
      scanf("%d",&arr2[i]);

//allocate memory for size number of thread IDs on heap
   pthread_t* tid =  (pthread_t*)malloc(sizeof(pthread_t)*size);
//create the threads and join them
   for(int i=0; i<size; i++){
      pthread_create(&tid[i], NULL, f1, (void*)&i);
      pthread_join(tid[i], NULL);
}
   printf("\nI am main thread.Sum of the two arrays is: \n");
   for(int i=0; i<size; i++)
	   printf("%d\n",result[i]);
   return 0;
}

void * f1(void * args){
   int n = *((int*)args);
   result[n] = arr1[n] + arr2[n];
   pthread_exit(NULL);
}
