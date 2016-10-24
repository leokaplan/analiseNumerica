all: main
main: IO.o matriz.o main.o 
	gcc -o main IO.o matriz.o gauss.o main.o
main.o: gauss.o teste_gauss.c
	gcc -o main.o -c teste_gauss.c -W -Wall -ansi -pedantic
matriz.o: matriz.c matriz.h
	gcc -o matriz.o -c matriz.c -W -Wall -ansi -pedantic
gauss.o: IO.o gauss.c gauss.h
	gcc -o gauss.o -c gauss.c -W -Wall -ansi -pedantic
IO.o: IO.c IO.h
	gcc -o IO.o -c IO.c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o
