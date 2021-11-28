exo1: exo1.o utf8.o
	gcc exo1.o utf8.o -ansi -Wall -o exo1
exo1.o: exo1.c utf8.h
	gcc -ansi -Wall -c exo1.c
utf8.o: utf8.c utf8.h
	gcc -ansi -Wall -c utf8.c

exo2: exo2.c 
	gcc -ansi -Wall -c exo2.c
