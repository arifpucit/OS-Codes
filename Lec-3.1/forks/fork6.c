/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  Describes what happens when fork() is called multiple times
*/

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{   
    fork();
    fork();
    fork();
    printf("Hello fork...\n");
    return 0;
}
