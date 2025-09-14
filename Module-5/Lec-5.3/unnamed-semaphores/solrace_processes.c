/*
*  Video Lecture: 32
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  solrace_processes.c: (Un-named semaphore among processes)
*  compile: $ gcc solrace_processes.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <semaphore.h>
#include <sys/ipc.h>
#include <sys/shm.h>

void inc();
void dec();
sem_t *mutex;
long *balance;
int main(){
//balance variable should be located in shared memory
   key_t key1 = ftok("file1", 65);
   int shm_id1=shmget(key1, 8, IPC_CREAT | 0666);
   balance = (long*)shmat(shm_id1, NULL, 0);
   *balance=0;   //initializing balance

//mutex variable should be located in shared memory
   key_t key2 = ftok("file2",66);
   int shm_id2=shmget(key2, 8, IPC_CREAT | 0666);
   mutex = (sem_t*)shmat(shm_id2, NULL, 0);	
   sem_init(mutex, 2, 1); //initializing semaphore
int cpid = fork();
   if (cpid == 0){
       inc();
       shmdt(balance);
       shmdt(&mutex);
       exit(0);
   }
   else{
       dec();
       waitpid(cpid,NULL,0);
       printf("Value of balance is: %ld\n", *balance);
       shmdt(balance);
       shmdt(&mutex);
       shmctl(shm_id1, IPC_RMID, NULL);
       shmctl(shm_id2, IPC_RMID, NULL);
       return 0;
   }
}

void inc(){
   for(long i=0;i<10000000;i++){
      sem_wait(mutex);
		*balance = *balance + 1;
		sem_post(mutex);
   }
}
void dec(){
   for(long j=0;j<10000000;j++){
      sem_wait(mutex);
		*balance = *balance - 1;
		sem_post(mutex);
    }
}
