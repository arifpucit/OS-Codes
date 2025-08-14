/*
*  Lecture: 1.6
*  Instructor: Arif Butt
*/
#include <stdio.h>
#include<stdlib.h>
#include <string.h>
void f1();
void f2();
void f3();
void f4();
void f5();
void f6();
void f7();

int main(){
//	f1();
//	f2();
//	f3();
//	f4();
	f5();
//	f6();
//	f7();
	return 0;
}

void f1(){
	int number = 54;
	if (number = 3)
		printf("variable number contains 3\n");
	else
		printf("variable number donot contain 3\n");
}

void f2(){
	char * ptr = (char*) malloc(sizeof(char)*10);
	ptr[13] = 'a';
	free(ptr);
	printf("Bye Bye from f2()...\n");
}

void f3(){
   char * ptr = (char*) malloc(sizeof(char)*10);
	free(ptr);
   ptr[5] = 'a';
	printf("Bye Bye from f3()...\n");
}

void f4(){
   char * ptr = (char*) malloc(sizeof(char)*10);
	free(ptr);
   free(ptr);
}

void f5(){
	char * ptr = (char*) malloc(sizeof(char)*10);
	ptr[1] = 'a';
	printf("Bye Bye from f5()...\n");
}


char* getString1(){
	char msg[100] = "Finding bugs is fun with Arif";
	char *ret = msg;
	return ret;
}

void f6(){
	char * abc = getString1();
	printf("String: %s\n",abc);
}





char* getString2(){
	char * ret = (char*) malloc(100);
	strcpy(ret, "Finding bugs is fun with Arif");
	return ret;
}

void f7(){
	char * abc = getString2();
	printf("String: %s\n",abc);
	free(abc);
}
