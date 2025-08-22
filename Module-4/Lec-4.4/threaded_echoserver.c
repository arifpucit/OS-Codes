/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  tcpechoserver_threaded.c: Server programs runs on ubuntu server
*  binds itself to ip 127.0.0.1 and port 54154, 
*  waits for client connections
*  for each client create a thread
*  receives a string from client
*  and will send it back to client
*  compile: gcc tcpechoserver_threaded.c
*  usage: ./a.out
*/
#include <sys/types.h>
#include <sys/socket.h>
#include <netdb.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <pthread.h>
#define BACKLOG 10  //how many pending connections queue  will hold
void* tcpechod(void *fd);
int main(){
   int server_sockfd;//socket on which server process will listen for incoming con
   int client_sockfd; //socket on which the server will be comm with the client
   struct sockaddr_in server_addr;
   struct sockaddr_in client_addr;

//*** STEP-I:  Create passive socket for the server
   server_sockfd = socket (AF_INET, SOCK_STREAM, 0);

//*** STEP-II: Create a address structure containing server IP addr
//***          and port, then bind the server_sockfd with this address
   server_addr.sin_family = AF_INET;
   server_addr.sin_port = htons(54154);
   inet_aton("127.0.0.1", &server_addr.sin_addr);
   memset(&(server_addr.sin_zero), '\0', sizeof server_addr.sin_zero);
   bind(server_sockfd, (struct sockaddr*)&server_addr, sizeof server_addr);
//*** STEP-III: Create a connection queue and wait for clients
   listen(server_sockfd, BACKLOG); 
   while(1){
//*** STEP-IV: Accept a connection, blocks until connection from client is established
//****         will return a brand new descriptor for comm with this single connection
      int client_len = sizeof client_addr;
      client_sockfd=accept(server_sockfd,(struct sockaddr*)&client_addr,&(client_len));
      pthread_t tid;
      pthread_attr_t ta;
      pthread_attr_init(&ta);
      pthread_attr_setdetachstate(&ta, PTHREAD_CREATE_DETACHED);
      pthread_create(&tid, &ta, &tcpechod, (void*)&client_sockfd);  
    }
   return 0;
 }
void* tcpechod(void * fd){
   int client_sockfd = *((int*)fd);
   char buf[100];
   int rv;
   fprintf(stderr, "\n********* CLIENT CONNECTION ESTABLISHED ********");
   while (rv = read(client_sockfd, buf, sizeof buf))
      write(client_sockfd, buf, rv);
   close(client_sockfd);
   fprintf(stderr, "\n********* CLIENT CONNECTION TERMINATED ********");
   pthread_exit(NULL);
}
