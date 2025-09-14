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
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
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
       fprintf(stderr, "Value of balance is: %ld\n", *balance);
       shmdt(balance);
       shmctl(shm_id1, IPC_RMID, NULL);
       return 0;
   }
}
void inc(){
   int temp = *balance;
   usleep(100000);
   temp = temp + 1;
   usleep(100000);
   *balance = temp;
   return;
}
void dec(){
   int temp = *balance;
   usleep(100000);
   temp = temp - 1;
   usleep(100000);
   *balance = temp;
   return;
}
