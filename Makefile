HEADERS = simulator.h
CC = gcc

SOURCES = simulator.c quicksort.c heapsort.c

all: quicksort heapsort

clean:
	-rm -f *.o quicksort heapsort

quicksort: quicksort.c simulator.c 
	gcc -o quicksort simulator.c quicksort.c -lm

heapsort: heapsort.c simulator.c
	gcc -o heapsort simulator.c heapsort.c -lm

run:
	./heapsort
	./quicksort