/*
*  Programmer: Arif Butt
*  Course: Operating Systems
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
