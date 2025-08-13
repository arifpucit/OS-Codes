/*
*  Video Lecture: 16
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main()
{
    int ch;
    system("stty -icanon");
    while ((ch = getchar()) != EOF){
        putchar(ch);
    }
}
