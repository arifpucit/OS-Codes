# File: A simple makefile to build greet target

# Link object files together into an target executable
greet: main.o greet.o
	gcc -o greet main.o greet.o

# Compile main.c
main.o: main.c greet.h
	gcc -c main.c
	
# Compile greet.c
greet.o: greet.c greet.h
	gcc -c greet.c