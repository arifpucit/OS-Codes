#this is a comment
myexe : mysub.o prog1.o myadd.o  mydiv.o mymul.o
	gcc  prog1.o myadd.o mysub.o mydiv.o mymul.o -o myexe
myadd.o: myadd.c
	gcc -c myadd.c 
mysub.o: mysub.c
	gcc -c mysub.c 
mydiv.o: mydiv.c
	gcc -c mydiv.c
mymul.o: mymul.c
	gcc -c mymul.c
prog1.o: prog1.c mymath.h
	gcc -c -I.  prog1.c 
clean:
	rm -f *.o
install: myexe
	@cp myexe /usr/bin
	@chmod a+x /usr/bin/myexe
	@chmod og-w /usr/bin/myexe
	@echo "myexe successfully installed in /usr/bin"
uninstall:
	@rm -f /usr/bin/myexe
	@echo "myexe successfully un-installed from /usr/bin"
.PHONY: all clean install uninstall