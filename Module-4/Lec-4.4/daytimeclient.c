/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  daytimeclient.c: Client programs connects to the daytime
*  service running on local machine having ip 127.0.0.1
*  at port 13, receives the daytime and display it on stdout
*  compile: gcc daytimeclient.c
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
int main(){
//*** STEP-I:  Create a socket
   int sockfd = socket (PF_INET, SOCK_STREAM, 0);
//*** STEP-II: Populate Socket's DS for remote IP and Port, and
//***          let the local IP and Port be selected by the OS itself
   struct sockaddr_in dest_addr;
   dest_addr.sin_family = AF_INET;    
   dest_addr.sin_port = htons(13);
   inet_aton("127.0.0.1", &dest_addr.sin_addr);
   memset(&(dest_addr.sin_zero), '\0', sizeof dest_addr.sin_zero);
//*** STEP-III: Connect this socket to the server's socket
   connect(sockfd, (struct sockaddr*)& dest_addr, sizeof dest_addr);
//*** STEP-IV:  Client sends no data to server rather the daytime
//***           server simply sends the date on connection establishment
   char buff[50];
   int rv = read(sockfd, buff, sizeof buff);
   buff[rv] = '\0';
   printf("Time Received from Server is: %s", buff);
//*** STEP-V:  Close socket
   close(sockfd);
   exit(0);
}
