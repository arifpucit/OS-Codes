# Link object files together into an target executable
greetings: main.o greet.o
	gcc  main.o greet.o -o greetings

# Compile main.c
main.o: main.c greet.h
	gcc -c main.c
	
# Compile greet.c
greet.o: greet.c greet.h
	gcc -c greet.c
