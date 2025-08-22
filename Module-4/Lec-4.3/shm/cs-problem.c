/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  cs-problem.c: The process creates a shared memory segment using System V API
*  The process attaches the shared memory to store a long variable named balance
*  The parent process fork and creates a child process, both have the shared memory attached
*  The child process calls inc() function, which increments the balance variable
*  The parent process calls dec() function, which decrements the balance variable
*  The parent process then waits for the child thread to terminate and then prints the value of balance variable
*  If both parent and child decrement and increment the same number of times the count should be zero
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
long *balance;
void  inc();
void  dec();
int main(){
   key_t key1 = ftok("file1", 65);
   if (key1 == -1){
      perror("ftok failed");
      exit(1);
   }
   int shm_id1 = shmget(key1, 8, IPC_CREAT | 0666);
   if (shm_id1 == -1){
      perror("shmget failed");
      exit(1);
   }
   balance = (long*)shmat(shm_id1, NULL, 0);
   if (balance == (void*)-1){
      perror("shmat failed");
      exit(1);
   }
   *balance = 0;
   printf("Value of balance before is :%ld\n", *balance);
   int cpid = fork();
   if (cpid==0){
        inc();
        shmdt(balance);
        exit(0);
   }else{
        dec();
        waitpid(cpid, NULL, 0);
        printf("Value of balance after is :%ld\n", *balance);
        shmdt(balance);
        shmctl(shm_id1, IPC_RMID, NULL);
        exit(0);
   }
}
void  inc(){
   for(long i=0; i < 0xfffffff; i++)
      *balance = *balance + 1;
}
void dec(){
   for(long i=0; i < 0xfffffff; i++)
     *balance = *balance - 1;
}
