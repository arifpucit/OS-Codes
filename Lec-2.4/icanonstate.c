/*
*  Video Lecture: 16
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
int main()
{
        struct termios info;
        int rv = tcgetattr(0, &info);     /* read values from driver      */
        if ( rv == -1 ){
                perror( "tcgetattr");
                exit(1);
        }
        if (info.c_lflag & ICANON)
                printf("Terminal driver is in canonical mode\n");
        else
                printf("Terminal driver is in non-canonical mode\n");
	return 0;
}
