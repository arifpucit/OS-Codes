/*
*  Video Lecture: 17
*  Programmer: Arif Butt
*  Course: System Programming with Linux
*/

#include <stdio.h>
#include <unistd.h>
int main()
{
   printf("My Real user-ID is: %ld\n", (long)getuid());
   printf("My Effective user-ID is: %ld\n", (long)geteuid());

   printf("My Real group-ID is: %ld\n", (long)getgid());
   printf("My Effective group-ID is: %ld\n", (long)getegid());
   return 0;
}
