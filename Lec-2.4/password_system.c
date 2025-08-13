/*
*  Video Lecture: 16
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  password_system.c: Input password string from user, if it is correct print appropriate message
*/
#include <stdio.h>
#include <termios.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]){
   char passwd[50];
   printf("Password:");
//make the echo attribute off using stty command
   system("stty -echo");
	fgets(passwd, 50, stdin);
	char *q;
   q = strchr(passwd, '\n');
   *q = '\0';
//make the echo attribute on using stty command
	system("stty echo");
	int rv = strcmp(passwd, "pucit");
	if (rv == 0)
		printf("\nThe password is correct\n");
	else
		printf("\nThe password is incorrect\n");
	return 0;
}
