/*
* redirect_grep.c
* Programmer: Arif Butt
* This program redirects the standard input to read from a specified input file
* and redirects the standard output to write to a specified output file.
* It then executes the `grep` command to search for a specified string in the input file
* and writes the results to the output file.

  Usage: ./redirect_grep <search_string> <input_file> <output_file>
*/

#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h> 
#include <sys/types.h>
#include <sys/stat.h>

int main(int argc, char **argv){
  char* searchstr = argv[1];
  char* inputfile = argv[2];
  char* outputfile = argv[3];
  // open input and output files
  int fd1 = open(inputfile, O_RDONLY);
  int fd2 = open(outputfile,O_WRONLY|O_TRUNC|O_CREAT, 0666);
  // replace stdin with input file and close fd1
  dup2(fd1, 0);
  close(fd1);
  // replace stdout with output file and close fd2
  dup2(fd2, 1);
  close(fd2);
  // execute grep
  char *grep_args[] = {"grep", searchstr, NULL};
  execvp("grep", grep_args);
}