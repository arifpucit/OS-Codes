/*
*  Video Lecture: 32
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  race_processes.c: The main() creates two threads,
*  allocate shared memory segment for a long variable balance 
*  parent do a fork and child process calls  inc() 
*  parent process calls dec() and then wait for termination of child
*  Finally main thread displays the value of global variable
*  compile: $ gcc race_processes.c -lpthread
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
long *balance;
int main(){
//balance variable should be located in shared memory
   key_t key1 = ftok("file1", 65);
   int shm_id1=shmget(key1, 8, IPC_CREAT | 0666);
   balance = (long*)shmat(shm_id1, NULL, 0);
   *balance=0;   //initializing balance

int cpid = fork();
   if (cpid == 0){
       inc();
       shmdt(balance);
       exit(0);
   }
   else{
       dec();
       waitpid(cpid,NULL,0);
       printf("Value of balance is: %ld\n", *balance);
       shmdt(balance);
       shmctl(shm_id1, IPC_RMID, NULL);
       return 0;
   }
}

void inc(){
   for(long i=0;i<100000000;i++){
		*balance = *balance + 1;
   }
}
void dec(){
   for(long j=0;j<100000000;j++){
		*balance = *balance - 1;
    }
}
