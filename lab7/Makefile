all: main
main: IO.o teste_mmq.c mmq.o matriz.o gauss.o
	gcc -o main  teste_mmq.c mmq.o matriz.o gauss.o -W -Wall -ansi -pedantic
matriz.o: matriz.c
	gcc -o matriz.o -c matriz.c -W -Wall -ansi -pedantic
mmq.o:  gauss.o mmq.c IO.o 
	gcc -o mmq.o -c mmq.c gauss.o IO.o -W -Wall -ansi -pedantic
gauss.o: matriz.o gauss.c 
	gcc -o gauss.o -c gauss.c matriz.o -W -Wall -ansi -pedantic
IO.o: IO.c IO.h
	gcc -o IO.o -c IO.c -W -Wall -ansi -pedantic
clean:
	rm -rf *.o
