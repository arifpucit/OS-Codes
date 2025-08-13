/*
*  Video Lecture: 16
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  password_ioctl.c: Input password string from user, if it is correct print appropriate message
*/

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ioctl.h>
int main(int argc, char *argv[])
{
	char passwd[50];
	printf("Password:");
//get attributes
        struct termios info;
        ioctl(0,TCGETS, &info); 
//save a copy of original attributes
	struct termios save = info;
//make the echo bit off and set attributes
        info.c_lflag &= ~ECHO;        
        ioctl(0, TCSETS, &info);
//get password from user
	fgets(passwd, 50, stdin);
	char *q;
   q = strchr(passwd, '\n');
   *q = '\0';
//now set the attributes back to original
	ioctl(0, TCSETS, &save);
//compare password and print appropriate message
	int rv = strcmp(passwd, "pucit");
	if (rv == 0)
		printf("\nThe password is correct\n");
	else
		printf("\nThe password is incorrect\n");
	
	return 0;

}
