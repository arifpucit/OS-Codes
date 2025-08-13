/*
*  Video Lecture: 14
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/
#include <unistd.h>
#include <stdio.h>
#include <dirent.h>
#include <stdlib.h>
#include <errno.h>

extern int errno;
int main(){
   printf("Directory scan of /home/: \n");
   DIR* dp = opendir("/home");
   chdir("/home");
   errno = 0;
   struct dirent* entry;
   while(1){
      entry = readdir(dp);
      if(entry == NULL && errno != 0){
         perror("readdir");
         return errno;
      }
      if(entry == NULL && errno == 0){
         printf("\nEnd of directory\n");
         return 0;
      }
      printf("%s   ",entry->d_name);
   }
   closedir(dp);
   return 0;
}
