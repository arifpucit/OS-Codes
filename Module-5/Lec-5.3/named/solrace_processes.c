/*
*  Video Lecture: 32
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  solrace_processes.c: The main() creates two threads,
*  allocate shared memory segment for a long variable balance
*  allocate shared memory segment for sem_t variable 
*  parent do a fork and child process calls  inc() 
*  parent process calls dec() and then wait for termination of child
*  Finally main thread displays the value of global variable
*  compile: $ gcc solrace_processes.c -lpthread
*  usage: $./a.out 
*/
#include <pthread.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
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
//creating a named semaphore
   char *name = "/sem1";
	mutex = sem_open(name, O_CREAT, 0666, 1);
//balance variable should be located in shared memory
   key_t key1 = ftok("file1", 65);
   int shm_id1 = shmget(key1, 8, IPC_CREAT | 0666);
   balance = (long*)shmat(shm_id1, NULL, 0);
   *balance = 0;
//Creating a child process
   int cpid = fork();
   if (cpid == 0){
      inc();
      shmdt(balance);
      sem_close(mutex);
      exit(0);
   }
   else{
      dec();
      waitpid(cpid, NULL, 0);
      printf("Value of balance is: %ld\n", *balance);
      shmdt(balance);
      shmctl(shm_id1, IPC_RMID, NULL);
      sem_close(mutex);
      sem_unlink(name);
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
