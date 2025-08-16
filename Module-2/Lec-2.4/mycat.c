/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  mycat.c: Get input from keyboard char by char and idsplay on screen
   usage: change terminal attributes and run this program
*/

#include <stdio.h>
#include <ctype.h>

int main()
{
    int ch;
    while ((ch = getchar()) != EOF){
        putchar(ch);
    }
}
