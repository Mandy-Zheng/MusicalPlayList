all: main.o songListFunctions.o
	gcc -o program main.o songListFunctions.o

main.o: main.c songListHeader.h
	gcc -c main.c

functions.o: songListFunctions.c songListHeader.h
	gcc -c songListFunctions.c
clean:
	rm *.o
	rm *~
run:
	./program
debug: main.c songListFunctions.c songListHeader.h
	gcc -g -c main.c songListFunctions.c
gdb:
	gdb ./a.out
valgrind:
	valgrind ./a.out
