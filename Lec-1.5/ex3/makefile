all: myexe
myexe: prog1.o mymul.o myadd.o mysub.o mydiv.o ./d1/mymod.o
	gcc -o myexe prog1.o mymul.o myadd.o mysub.o mydiv.o ./d1/mymod.o
myadd.o: myadd.c
	gcc -c myadd.c
mysub.o: mysub.c 
	gcc -c mysub.c
mydiv.o: mydiv.c 
	gcc -c mydiv.c
mymul.o: mymul.c
	gcc -c mymul.c
prog1.o: prog1.c mymath.h d1/mymod.h
	gcc -c prog1.c -I. -Id1/
include: ./d1/makefile
clean:
	rm -f *.o
	rm -f ./d1/mymod.o
install: myexe
	@cp myexe /usr/bin
	@chmod a+x /usr/bin/myexe
	@chmod og-w /usr/bin/myexe
	@echo "myexe installed successfully in /usr/bin"
uninstall:
	@rm -f /usr/bin/myexe
	@echo "myexe successfully un-installed from /usr/bin"
