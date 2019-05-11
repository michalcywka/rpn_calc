a.out: stos.o main.o
	gcc stos.o main.o
main.o: modul.h main.c	
	gcc -c -Wall -pedantic main.c
stos.o: modul.h stos.c
	gcc -c -Wall -pedantic stos.c
