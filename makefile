all: main.o helperFunctions.o musicalLibraryFunctions.o
	gcc -o program main.o helperFunctions.o musicalLibraryFunctions.o

main.o: main.c helperFunctionsHeader.h musicalLibraryHeader.h
	gcc -c main.c

helperFunctions.o: helperFunctions.c helperFunctionsHeader.h
	gcc -c helperFunctions.c
musicalLibraryFunctions.o: musicalLibraryFunctions.c musicalLibraryHeader.h
	gcc -c musicalLibraryFunctions.c
clean:
	rm *.o
	rm *~
run:
	./program
debug: main.c helperFunctions.c musicalLibraryFunctions.c
	gcc -g -c main.c helperFunctions.c musicalLibraryFunctions.c
gdb:
	gdb ./a.out
valgrind:
	valgrind ./a.out
