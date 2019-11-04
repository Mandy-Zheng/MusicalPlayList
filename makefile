ifeq ($(DEBUG), true)
	CC = gcc -g
else
	CC = gcc
endif
all: main.o helperFunctions.o musicalLibraryFunctions.o
	$(CC) -o program main.o helperFunctions.o musicalLibraryFunctions.o

main.o: main.c helperFunctionsHeader.h musicalLibraryHeader.h
	$(CC) -c main.c

helperFunctions.o: helperFunctions.c helperFunctionsHeader.h
	$(CC) -c helperFunctions.c
musicalLibraryFunctions.o: musicalLibraryFunctions.c musicalLibraryHeader.h
	$(CC) -c musicalLibraryFunctions.c helperFunctions.c
clean:
	rm *.o
	rm *~
run: all
	./program
gdb:
	gdb ./a.out
valgrind:
	valgrind ./a.out
