/*
*  Video Lecture: 14
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  lsv1.c:
*  usage: ./a.out 
         ./a.out dirpath
         ./a.out dir1 dir2 dir3
*/


#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include<sys/stat.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;
void do_ls(char*);
int main(int argc, char* argv[]){
   if (argc == 1){
         printf("Directory listing of pwd:\n");
      do_ls(".");
   }
   else{
      int i = 0;
      while(++i < argc){
         printf("Directory listing of %s:\n", argv[i] );
	 do_ls(argv[i]);
      }
   }
   
   return 0;
}


void do_ls(char * dir)
{
   struct dirent * entry;
   DIR * dp = opendir(dir);
   if (dp == NULL){
      fprintf(stderr, "Cannot open directory:%s\n",dir);
      return;
   }
   errno = 0;
   while((entry = readdir(dp)) != NULL){
         if(entry == NULL && errno != 0){
  		perror("readdir failed");
		exit(1);
  	}else{
                if(entry->d_name[0] == '.')
                    continue;
        }     	printf("%s\n",entry->d_name);
   }
   closedir(dp);
}
