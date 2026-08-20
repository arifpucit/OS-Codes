# File: Auto variables demo

# Define macros
CC = gcc                           # Compiler to use
CFLAGS = -std=c11 -O0 -ggdb -Wall  # Compilation options
TARGET = greet                     # Final executable
OBJS = main.o greet.o              # Object files

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ 

# Compile main.c
main.o: main.c greet.h
	$(CC) $(CFLAGS) -c $<

# Compile greet.c
greet.o: greet.c greet.h
	$(CC) $(CFLAGS) -c $<

# Clean target (optional, but recommended)
clean:
	-rm -f *.o $(TARGET)

.PHONY: all clean
