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
        if (rv == -1){
                perror( "tcgetattr");
                exit(1);
        }
        if ((info.c_lflag & 0000010) == 0)
                printf("echo is off , since its bit is 0\n");
        else
                printf("echo is on, since its bit is 1\n");
	return 0;
}
