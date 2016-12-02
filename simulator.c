#include "simulator.h" 

void init(int psize, int winsize) {
	page_size = psize;
	window_size = winsize;
	table_size = 9;
	list_of_page_size = 0;
	table = malloc(table_size*sizeof(llist*));
	numberOfElements = 0;
	list_of_pages = malloc(1*sizeof(int));
}

void put(unsigned int address, int value) {
	llist* newItem = ll_new(address, value);
	ht_insert(table, table_size, newItem);

	addToHistory(address);
}

int get(unsigned int address) {
	llist* foundLlist = ht_search(table, table_size, address);

	addToHistory(address);
	return foundLlist->data;
}

void done() {
	fprintf(stdout, " === The history of the working set ===\n");

// 	//TEST CODE
// 	list_of_page_size = 6;
// 	list_of_pages = malloc(list_of_page_size*sizeof(int));
// 	list_of_pages[0] = 2;
// 	list_of_pages[1] = 1;
// 	list_of_pages[2] = 2;
// 	list_of_pages[3] = 6;
// 	list_of_pages[4] = 2;
// 	list_of_pages[5] = 4;


// 	int i, win_size_counter = 0;
// 	fprintf(stdout, "Total number of working sets: %d\n", list_of_page_size);

// 	// create an array of ints that is equal to the window size
// 	int* page_set = malloc(window_size*sizeof(int));

// 	// the total amount of data
// 	int size_of_data = list_of_page_size/window_size;
// 	int* final_data = malloc(size_of_data*sizeof(int));

// 	// loop through all the history pages, and prints out the working set
// 	for(i = 0; i < list_of_page_size; i++) {
// 		fprintf(stdout, "Page number: %d\n", list_of_pages[i]);

// 		// add to the page set
// 		page_set[win_size_counter] = list_of_pages[i];
// 		win_size_counter++;

// 		if(win_size_counter == window_size) {
// 			int numDiffPages = getNumberOfDiffPagesAccessed(page_set, win_size_counter);
// 			final_data = 0; // reset the counter
// 		}
// 	}


// 	// fprintf(stdout, "total: %d size: %d\n", final_data, list_of_page_size);
// 	// float avg = (float)total/(float)list_of_page_size; // bumps it down always no matter what
// 	// fprintf(stdout, "\nAverage Working Set Size: %f\n", avg);
}

void printSortedValues() {
	int i;
	for(i = 0; i < numberOfElements; i++) {
		int val = get(i);
		printf("%d ", val);
	}

	printf("\n\n");
}

// adding page to our history
void addToHistory(unsigned int address) {
	list_of_page_size++;
	// if(list_of_page_size > 1)
	list_of_pages = realloc(list_of_pages, list_of_page_size*sizeof(int));
	int page = address/page_size;
	list_of_pages[list_of_page_size-1] = page;
}


// ======================= linked list functions to be used by hash table =======================
llist* ll_new(int key, double data) {
	llist* new = malloc(sizeof(llist));
	new->key = key;
	new->data = data;
	new->next = NULL;
	new->previous = NULL;
	
	return new;
}

// Example: head = ll_insert(head, new);
llist* ll_insert(llist* head, llist* new) {
	new->next = head;
	if(head != NULL)
		head->previous = new;
	head = new;
	
	return head;
}

// Example: head = ll_delete(head, item); (remember to free memory for item)
llist* ll_delete(llist* head, llist* item) {
	if(item->previous != NULL)
		item->previous->next = item->next;
	if(item->next != NULL)
		item->next->previous = item->previous;
	if(item == head)
		head = item->next;

	return head;
}

// Example: llist* item = ll_search(head, key)
llist* ll_search(llist* head, int key) {
	for(; head!=NULL; head=head->next) {
		if(head->key == key)
			return head;
	}

	return NULL;
}

// ======================= hash table functions =======================
// hash table functions
void ht_insert(llist** table, int size, llist* item) {
	int key = item->key;
	table[key%size] = ll_insert(table[key%size], item);
}

void ht_delete(llist** table, int size, llist* item) {
	int key = item->key;
	table[key%size] = ll_delete(table[key%size], item);
}

llist* ht_search(llist** table, int size, int key) {
	return ll_search(table[key%size], key);
}
