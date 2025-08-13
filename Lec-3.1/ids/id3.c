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
   printf("My Saved Set-user-ID is: %ld\n", (long)suid);

   gid_t rgid, egid, sgid;
   getresgid(&rgid, &egid, &sgid);
   printf("My Real group-ID is: %ld\n", (long)rgid);
   printf("My Effective group-ID is: %ld\n", (long)egid);
   printf("My Saved Set-group-ID is: %ld\n", (long)sgid);
   return 0;
}
