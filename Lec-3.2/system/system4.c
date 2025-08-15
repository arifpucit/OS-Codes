/*
*  Programmer: Arif Butt
*  Course: Operating Systems
*  The code prompts the user to enter a filename as input and constructs a command from it using snprintf() that and formats stores a series of characters and values in the array as per the format string.
*  Simply speaking this program actually executes system("cat " + <file-name>) to display the contents of the file name entered by the user.
*  This program shows that if user input is passed to system() function without any validation, an attacker can manipulate that input to execute arbitrary commands.
*  For example, if the command string contains special characters like ;, &, | etc, it can lead to command injection vulnerability, which is beyond what the programmer intended.
*  So to exploit this program a user can enter "system4.c;/bin/sh" to get a shell. Is it a root shell?
*/

#include <stdlib.h>
#include <stdio.h>
int main(){
   char filename[100];
   printf("Enter a filename to display its content: ");
   fgets(filename, sizeof(filename), stdin);
   char command[150];
   snprintf(command, sizeof(command), "cat %s", filename);
   system(command); 
   return 0;
}
