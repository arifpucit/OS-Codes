/*
*  Video Lecture: 19
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Executing a shell script using system()
*/
#include <stdlib.h>
#include <stdio.h>
int main(){
   printf("Executing a script using system from main.\n\n");
   system("/bin/bash script1.sh");
   printf("\n\nDone... Bye from main\n");
   exit(0);
}
