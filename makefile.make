HEADERS = simulator.h
CC = gcc

SOURCES = simulator.c quicksort.c heapsort.c

all: quicksort heapsort

clean:
	-rm -f *.o quicksort heapsort

quicksort: quicksort.c
	gcc -o quicksort simulator.c quicksort.c 

heapsort: heapsort.c 
	gcc -o heapsort simulator.c heapsort.c

run:
	./heapsort
	./quicksort