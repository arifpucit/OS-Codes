#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main() {
   fork();
   printf("Called fork() system call\n");
   return 0;
}