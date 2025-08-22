/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  usage: ./a.out
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
   short int var = 0x0001;
   char* byte = (char*)&var;
   if (byte[0] == 1)
      printf("Little endian\n");
   else
      printf("Big endian\n");
   return 0;
}

