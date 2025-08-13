//rev7.c
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]){
	if(argc==2){
		printf("Checking Key: %s\n", argv[1]);
		if (strcmp(argv[1], "kakamanna")==0)
			printf("Access Granted!\n");
		else
			printf("Sorry, Try again....\n");
	}else
		printf("Usage: <key>\n");
	return 0;
}
