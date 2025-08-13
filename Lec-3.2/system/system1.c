/*
*  Video Lecture: 19
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Executing a shell command using system()
*/
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char* argv[]){
   system(argv[1]);
   printf("\nDone... Bye\n");
   exit(0);
}
