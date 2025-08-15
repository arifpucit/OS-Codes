/*
*  Programmer: Arif Butt
*  Course: Operating Systems
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
