all: main.o helperFunctions.o
	gcc -o program main.o helperFunctions.o

main.o: main.c songListHeader.h
	gcc -c main.c

helperFunctions.o: helperFunctions.c songListHeader.h
	gcc -c helperFunctions.c
clean:
	rm *.o
	rm *~
run:
	./program
debug: main.c helperFunctions.c songListHeader.h
	gcc -g -c main.c helperFunctions.c
gdb:
	gdb ./a.out
valgrind:
	valgrind ./a.out
