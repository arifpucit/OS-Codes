/*
*  Video Lecture: 14
*  Programmer: Arif Butt
*  Course: System Programming with Linux
* fileinfo.c - demonstrates using stat() to obtain
 *              file information.
 *            - some members are just numbers...
 */
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
void show_stat_info(char*);
int main(int argc, char *argv[]){
   if(argc != 2){
      fprintf(stderr, "Incorrect number of arguments\n");
      exit(1);
   }
   show_stat_info(argv[1]);
   return 0;
}

void show_stat_info(char *fname){
   struct stat info;
   int rv = lstat(fname, &info);
   if (rv == -1){
      perror("stat failed");
      exit(1);
   }
   printf("mode: %o\n", info.st_mode);
   printf("link count: %ld\n", info.st_nlink);
   printf("user: %d\n", info.st_uid);
   printf("group: %d\n", info.st_gid);
   printf("size: %ld\n", info.st_size);
   printf("modtime: %ld\n", info.st_mtime);
   printf("name: %s\n", fname );
}
