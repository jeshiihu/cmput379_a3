HEADERS = simulator.h
CC = gcc

SOURCES = simulator.c quicksort.c heapsort.c

all: quicksort heapsort

clean:
	-rm -f *.o quicksort heapsort

quicksort: quicksort.c
	gcc -o quicksort quicksort.c simulator.c


heapsort: heapsort.c 
	gcc -o heapsort heapsort.c simulator.c

run:
	./heapsort
	./quicksort