/*
*  Video Lecture: 14
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*  lsv0.c: Receives exactly one directory name via command line argument and display names of files and subdirectories in the order as they appear in the directory
*  usage: ./a.out dirpath
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
   if (argc != 2){
   printf("Enter exactly one argument (a directory name).\n");
   exit(1);
   }
   printf("Directory listing of %s:\n", argv[1] );
   do_ls(argv[1]);
   return 0;
}


void do_ls(char * dir){
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
         exit(errno);
      }
      else
         printf("%s\n",entry->d_name);
      }
      closedir(dp);
}
