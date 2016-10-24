all: main
main: IO.o matriz.o main.o 
	gcc -o main IO.o matriz.o main.o
main.o: main.c
	gcc -o main.o -c main.c -W -Wall -ansi -pedantic
matriz.o: matriz.c matriz.h
	gcc -o matriz.o -c matriz.c -W -Wall -ansi -pedantic
IO.o: IO.c IO.h
	gcc -o IO.o -c IO.c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o
