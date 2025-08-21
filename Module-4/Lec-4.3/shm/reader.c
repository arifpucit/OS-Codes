/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  Program gets the id of an existing shared memory region,
*  attach it to its adress space
*  read the data and display it on stdout
*  detach the memory segment and deletes it
*  usage: ./reader
*/
#include <stdio.h>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <sys/stat.h>
int main(){
// ftok to generate unique key
   key_t key = ftok("f1.txt", 65);
// shmget returns an identifier of existing shared memory
   int shmid = shmget(key, 1024, 0666|IPC_CREAT);
// shmat to attach to shared memory
   char *buffer = (char*)shmat(shmid, NULL, 0);
   printf("Data read from memory: %s\n", buffer);
//detach from shared memory 
   shmdt(buffer);
// destroy the shared memory
//   shmctl(shmid, IPC_RMID, NULL);
   return 0;
}
