/*
*  Video Lecture: 14
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

//gidtogname.c - receives gid via cmd line and checks the group name for that gid in the file /etc/group

#include <stdio.h>
#include <errno.h>
#include <grp.h>
#include <stdlib.h>

extern int errno;
int main(int argc, char* argv[]){
   if(argc!=2){
	printf("Enter exactly one command line argument: gid\n");
	exit(1);
   }
   int gid = atoi(argv[1]);
   struct group * grp = getgrgid(gid);
  
   errno = 0;
   if (grp == NULL){
      if (errno == 0)
          printf("Record not found in /etc/group file.\n");
      else
          perror("getgrgid failed");
   }else
      printf("Name of group is: %s \n", grp->gr_name);   
   return 0;
}
