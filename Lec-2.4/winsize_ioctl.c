/*
*  Video Lecture: 16
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <sys/ioctl.h>
#include <stdlib.h>
#include <stdio.h>

int main(){
   struct winsize wbuf;
   if(ioctl(0, TIOCGWINSZ, &wbuf) == -1){
      perror("Error in ioctl");
      exit(1);
   }
   printf("%d rows x %d cols \n", wbuf.ws_row, wbuf.ws_col);  
   return 0;
}
