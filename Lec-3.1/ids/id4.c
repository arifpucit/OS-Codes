/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

#define _GNU_SOURCE
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
int main()
{
   uid_t ruid, euid, suid;
   getresuid(&ruid, &euid, &suid);
   printf("My Real user-ID is: %ld\n", (long)ruid);
   printf("My Effective user-ID is: %ld\n", (long)euid);
   printf("My Saved Set-user-ID is: %ld\n\n\n", (long)suid);

   int rv = setuid(1002);
   if (rv == -1){
      printf ("Error in setting ID\n");
      exit(1);
   }
   getresuid(&ruid, &euid, &suid);
   printf("\n\nAfter setuid(1002) the IDs are:\n");
   printf("My Real user-ID is: %ld\n", (long)ruid);
   printf("My Effective user-ID is: %ld\n", (long)euid);
   printf("My Saved Set-user-ID is: %ld\n", (long)suid);
   return 0;
}
