/*
*  lseek1.c
*  Programmer: Arif Butt
*  This program attempts to set the file offset of the file descriptor 0 (standard input)
*  to the 54th byte using the lseek() system call.

   $./lseek1
	$./lseek1 < /etc/passwd
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
extern int errno;
int  main(){
   int rv = lseek(0, 54, SEEK_SET);
   if (rv == -1){
      printf("Cannot seek\n");
      exit(errno);
   }
   else
      printf("seek OK\n");
   return 0;
}
