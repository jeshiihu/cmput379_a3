#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <strings.h>
#include <time.h>
#include <string.h>

// hashtbale, address is key and value

// working set: number of unique pages 
// A B C A A A C
// Calculate working set:
// Working set is {A B C}, size 3

// Window size: normally 
// ... A B C A A A C (last 7 references)
// for this assignment
// after calling done: yyou'll have a big list of mem references
// if window size if 10
// ... ... ... A B C A A A C
// ^10 ^10 ^10 

// if working set size is huge, you're referencing a lot and a lot of work

// i/page_size = page


struct linked_list {
	unsigned int key;
	int data;
	struct linked_list* next; // left
	struct linked_list* previous; //right
};

typedef struct linked_list llist;

// linked list functions to be used by hash table
llist* ll_new(unsigned int key, double data);
llist* ll_insert(llist* head, llist* new);
llist* ll_delete(llist* head, llist* item);
llist* ll_search(llist* head, unsigned int key);

// hash table functions
void ht_insert(llist** table, int size, llist* item);
void ht_delete(llist** table, int size, llist* item);
llist* ht_search(llist** table, int size, unsigned int key);

// simulator functions
int page_size, window_size, table_size;
//changed numberOfElements to be unsigned int
unsigned int numberOfElements;
llist** table;
int* list_of_pages;
int list_of_page_size;
int flag_print_working_sets;

void addToHistory(unsigned int address);
int getNumberOfDifferentPages(int* arr, int size);
void printSortedValues();
void printAverageWorkingSet(int* arr, int size);

void init(int psize, int winsize);
void put(unsigned int address, int value);
int get(unsigned int address);
void done();

