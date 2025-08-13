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
        if (rv == -1){
                perror( "ioctl");
                exit(1);
        }
//	printf("%d\n", ECHO);
//	printf("%d\n",info.c_lflag);
//	printf("%d \n", info.c_lflag & 8);
        if ((info.c_lflag & ECHO) == 0)
                printf("echo is off , since its bit is 0\n");
        else
                printf("echo is on, since its bit is 1\n");
	return 0;
}
