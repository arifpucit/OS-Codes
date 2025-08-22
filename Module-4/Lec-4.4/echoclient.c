/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  echoclient.c: Client programs connects to the echo
*  service running on the ubuntuserver having ip 192.168.100.20
*  at port 7, sends a string and receives the same string
*  and display it on stdout
*  compile: gcc tcpechoclient.c
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
int main(int argc, char** argv){
//*** STEP-I:  Create a socket
   int sockfd = socket(PF_INET, SOCK_STREAM, 0);
//*** STEP-II: Populate Socket's DS for remote IP and Port, and
//***          let the local IP and Port be selected by the OS itself
   struct sockaddr_in dest_addr;
   dest_addr.sin_family = AF_INET;    
   dest_addr.sin_port = htons(54154);
   inet_aton("127.0.0.1", &dest_addr.sin_addr);
   memset(&(dest_addr.sin_zero), '\0', sizeof dest_addr.sin_zero); 
//*** STEP-III: Connect this socket to the server's socket
   connect(sockfd, (struct sockaddr*)& dest_addr, sizeof dest_addr);
//*** STEP-IV:  Client reads string from stdin and send it to server
//***           then read string returned by server and display on stdout
   char buff1[128],buff2[128] ;
   while(1){
      int n = read(0, buff1, sizeof buff1);   
      buff1[n] = '\0';
      write(sockfd, buff1, strlen(buff1));
      n = read(sockfd, buff2, strlen(buff1));
      buff2[n] = '\0';
      write(1, buff2, n);
   }
//*** STEP-V:  Close socket
   close(sockfd);
   exit(0);
}
