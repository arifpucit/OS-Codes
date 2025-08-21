/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  Program gets the id of an existing message queue,
*  reads a message from that queue and 
*  display the mtext on stdout
*  usage: ./receiver
*/
#include <sys/msg.h>
#include <sys/ipc.h>
#include <stdlib.h>
#include <stdio.h>
#define SIZE 512
struct msgbuf{
   long mtype;
   char mtext[SIZE];
};
int main(){
   key_t key = ftok("./myfile", 65);
   int qid = msgget(key, IPC_CREAT | 0666);
//get the first message from the message queue
   struct msgbuf msg;
   msgrcv(qid, &msg, SIZE, 0, IPC_NOWAIT);
   printf("Message Received: %s\n",msg.mtext);
   return 0;
}
