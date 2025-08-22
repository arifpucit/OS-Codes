/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  finaldaytimeclient.c: Client program receives hostname via cmd line
*  and string service, converts the hostname to ip, 
*  and converts the serice name to port
*  finally connects the server 
*  compile: gcc finaldaytimeclient.c
*  usage: ./a.out <hostname> <servicename>
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
int main(int argc, char** argv){
  if(argc != 3){printf("Must enter hostname and servicename\n"); exit(1);}
//Resolve the hostname string  to ip address
  struct hostent* phe = gethostbyname(argv[1]);
  char ipaddr[15];
  strcpy(ipaddr, inet_ntoa(*((struct in_addr*)phe->h_addr)));

//Get the appropriate portnumber from service name
  struct servent * pse = getservbyname(argv[2], '\0');
  int portnum = ntohs(pse->s_port);

//*** STEP-I:  Create a socket
   int sockfd = socket (PF_INET, SOCK_STREAM, 0);
//*** STEP-II: Populate Socket's DS for remote IP and Port, and
//***          let the local IP and Port be selected by the OS itself
   struct sockaddr_in dest_addr;
   dest_addr.sin_family = AF_INET;    
   dest_addr.sin_port = htons(portnum);
   inet_aton(ipaddr, &dest_addr.sin_addr);
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
