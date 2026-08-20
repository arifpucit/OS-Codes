# Contents of ./d1/makefile
# default target
all: mymod.o

mymod.o: mymod.c mymod.h
	@echo "Compiling mymod.c in d1..."
	gcc -Wall -g -c -I. mymod.c

clean:
	@echo "Cleaning d1 directory...."
	rm -f mymod.o

.PHONY: all clean
