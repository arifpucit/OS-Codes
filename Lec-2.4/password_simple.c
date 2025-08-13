/*
*  Video Lecture: 16
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  password_simple.c: Input password string from user, if it is correct print appropriate message
*/

#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
	char passwd[50];
	printf("Password:");
	fgets(passwd, 50, stdin);
//the passwd contains the string entered by user + '\n' and then '\0', we need to remove the '\n' if there is any
	char *q;
   q = strchr(passwd, '\n');
   *q = '\0';
	int rv = strcmp(passwd, "pucit");
	if (rv == 0)
		printf("\nThe password is correct\n");
	else
		printf("\nThe password is incorrect\n");
	
	return 0;

}
