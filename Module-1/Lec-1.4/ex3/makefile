all: myexe

myexe: mysub.o prog1.o myadd.o  mydiv.o mymul.o ./d1/mymod.o
	@echo "Linking myexe..."
	gcc  mysub.o prog1.o myadd.o mydiv.o mymul.o  ./d1/mymod.o -o myexe
	@echo "Build myexe: complete"
myadd.o: myadd.c mymath.h
	@echo "Compiling myadd.c..."
	gcc -Wall -g -c -I. myadd.c 
mysub.o: mysub.c mymath.h
	@echo "Compiling mysub.c..."
	gcc -Wall -g -c -I. mysub.c 
mydiv.o: mydiv.c mymath.h
	@echo "Compiling mydiv.c..."
	gcc -Wall -g -c -I. mydiv.c
mymul.o: mymul.c mymath.h
	@echo "Compiling mymul.c..."
	gcc -Wall -g -c -I. mymul.c
prog1.o: prog1.c mymath.h d1/mymod.h
	@echo "Compiling prog1.c..."
	gcc -Wall -g -c -I.  -Id1/ prog1.c
#Recursive make call for subdirectory
./d1/mymod.o: d1/mymod.c mymath.h d1/mymod.h
	@echo "Compiling d1/mymod.c..."
	make -C ./d1 mymod.o          # is equivalent to cd d1 && make mymod.o && cd ..

clean:
	@echo "Clening root directory..."
	rm -f *.o myexe
	@echo "Clening d1 directory..."
	make -C ./d1 clean
	@echo "Clean complete"

install: myexe
	@cp myexe /usr/bin
	@chmod a+x /usr/bin/myexe
	@chmod og-w /usr/bin/myexe
	@echo "myexe successfully installed in /usr/bin"

uninstall:
	@rm -f /usr/bin/myexe
	@echo "myexe successfully un-installed from /usr/bin"

.PHONY: all clean install uninstall
