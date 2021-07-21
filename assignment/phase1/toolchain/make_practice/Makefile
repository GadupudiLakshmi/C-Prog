CC = gcc -o
cc = gcc -c
add : main.o add.o   # dependencies
	$(CC) addexe main.o add.o  #action
sub : mainsub.o sub.o
	$(CC) subexe mainsub.o sub.o
main.o: main.c header.h   
	$(cc) main.c
add.o: add.c header.h
	$(cc) add.c
mainsub.o: mainsub.c header.h
	$(cc) mainsub.c
sub.o: sub.c header.h
	$(cc) sub.c

clean:
	rm -rf *.o

