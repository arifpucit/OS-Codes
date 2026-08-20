#this is a comment
all: myexe install
myexe : mysub.o prog1.o myadd.o  mydiv.o mymul.o
	gcc  mysub.o prog1.o myadd.o mydiv.o mymul.o -o myexe
myadd.o: myadd.c mymath.h
	gcc -c -I. myadd.c 
mysub.o: mysub.c mymath.h
	gcc -c -I. mysub.c 
mydiv.o: mydiv.c mymath.h
	gcc -c -I. mydiv.c
mymul.o: mymul.c mymath.h
	gcc -c -I. mymul.c
prog1.o: prog1.c mymath.h
	gcc -c -I.  prog1.c 
clean:
	rm -f *.o myexe
install: myexe
	@cp myexe /usr/bin
	@chmod a+x /usr/bin/myexe
	@chmod og-w /usr/bin/myexe
	@echo "myexe successfully installed in /usr/bin"
uninstall:
	@rm -f /usr/bin/myexe
	@echo "myexe successfully un-installed from /usr/bin"
.PHONY: all clean install uninstall
