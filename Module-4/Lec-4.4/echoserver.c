/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  echoserver.c: Server programs runs on ubuntu server
*  binds itself to ip 127.0.0.1 and port 54154, 
*  waits for client connections
*  receives a string from client
*  and will send it back to client
*  compile: gcc tcpechoserver.c
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
#define BACKLOG 10  //how many pending connections queue  will hold

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
      fprintf(stderr,"\nServer waiting for client connection...");

//*** STEP-IV: Accept a connection, blocks until connection from client is established
//****         will return a brand new descriptor for comm with this single connection
      int client_len = sizeof client_addr;
      client_sockfd=accept(server_sockfd,(struct sockaddr*)&client_addr,&(client_len));
      fprintf(stderr, "\n********* CLIENT CONNECTION ESTABLISHED ********");
      
//STEP-V ***** Read from sockfd and write back
      char buf[100];
      int rv;
      while (rv = read(client_sockfd, buf, sizeof buf))
        write(client_sockfd, buf, rv);
      close(client_sockfd);
      fprintf(stderr, "\n********* CLIENT CONNECTION TERMINATED ********");
      }
   return 0;
 }
