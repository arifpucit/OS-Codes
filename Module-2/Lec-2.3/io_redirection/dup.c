/*
*  dup.c
*  Programmer: Arif Butt
*  This program demonstrates the use of the dup() system call.
*  It opens a file, duplicates its file descriptor, and reads from both the original and duplicated
*  file descriptors, displaying the contents read from each.

*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
int main(){
   int fd1, fd2, n;
   char buff[10];
   fd1 = open ("abc.txt", O_RDONLY);
   fd2 = dup(fd1);
   //reading via fd1
   n = read (fd1, buff, 5);
   write(1, buff, n);
   //reading via fd2
   n = read (fd2, buff, 5);
   write(1, buff, n);
   //reading via fd1
   n = read (fd1, buff, 5);
   write(1, buff, n);
   return 0;
}
