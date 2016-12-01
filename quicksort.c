
#include "simulator.h"

int getNumberOfDiffPagesAccessed(int* page_array, int array_len) {

// LOOL THIS IS WRONG HAVE TO REDO
	int duplicateCount = 0;

	// int found_pages_size = 1;
	// int* found_pages = malloc(found_pages_size*sizeof(int));

	// int i, j;
	// for(i = 0; i < array_len; i++) {

	// 	// loop through the already encountered pages to see if we have a duplicate
	// 	for(j = 0; j < array_len; j++) {
	// 		if(page_array[i] == found_pages[j]) {
	// 			duplicateCount++;
	// 			found_pages[found_pages_size]
	// 		}
	// 	}
	// }

	return duplicateCount;
}

void doneTempt() {
	fprintf(stdout, " === The history of the working set ===\n");

	//TEST CODE
	list_of_page_size = 6;
	list_of_pages = malloc(list_of_page_size*sizeof(int));
	list_of_pages[0] = 2;
	list_of_pages[1] = 1;
	list_of_pages[2] = 2;
	list_of_pages[3] = 6;
	list_of_pages[4] = 2;
	list_of_pages[5] = 4;


	int i, win_size_counter = 0;
	fprintf(stdout, "Total number of working sets: %d\n", list_of_page_size);

	// create an array of ints that is equal to the window size
	int* page_set = malloc(window_size*sizeof(int));

	// the total amount of data
	int size_of_data = list_of_page_size/window_size;
	int* final_data = malloc(size_of_data*sizeof(int));

	// loop through all the history pages, and prints out the working set
	for(i = 0; i < list_of_page_size; i++) {
		fprintf(stdout, "Page number: %d\n", list_of_pages[i]);

		// add to the page set
		page_set[win_size_counter] = list_of_pages[i];
		win_size_counter++;

		if(win_size_counter == window_size) {
			int numDiffPages = getNumberOfDiffPagesAccessed(page_set, win_size_counter);
			final_data = 0; // reset the counter
		}
	}


	// fprintf(stdout, "total: %d size: %d\n", final_data, list_of_page_size);
	// float avg = (float)total/(float)list_of_page_size; // bumps it down always no matter what
	// fprintf(stdout, "\nAverage Working Set Size: %f\n", avg);
}

void process() {
	printf("QUICKSORT\n");
	printf("Page size: %d, Window Size: %d\n", page_size, window_size);

	// init(page_size, window_size);
	dummy();
	doneTempt();
}

int main(int argc, char** argv) {
	// error checking
	page_size = atoi(argv[1]);
	window_size = atoi(argv[2]);

	process();
	return 0;
}