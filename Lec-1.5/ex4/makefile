# File: MACRO demonstration
# Define macros
CC = gcc                           # Compiler to use
CFLAGS = -std=c11 -O0 -ggdb -Wall  # Compilation options
TARGET = greet                     # Final executable
OBJS = main.o greet.o              # Object files

# Default target
all: $(TARGET)

# Link object files into executable
$(TARGET): $(OBJS)
   $(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile main.c
main.o: main.c greet.h
   $(CC) $(CFLAGS) -c main.c

# Compile greet.c
greet.o: greet.c greet.h
   $(CC) $(CFLAGS) -c greet.c

clean:
	-rm $(OBJS) $(TARGET)

.PHONY: all clean