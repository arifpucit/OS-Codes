/*
*  Video Lecture: 16
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <sys/ioctl.h>
int main()
{
        struct termios info;
        int rv = ioctl(0, TCGETS, &info);     /* read values from driver      */
        if ( rv == -1 ){
                perror( "ioctl");
                exit(1);
        }
        if (info.c_lflag & ICANON)
                printf("Terminal driver is in canonical mode\n");
        else
                printf("Terminal driver is in non-canonical mode\n");
	return 0;
}
