
#include "simulator.h"

void doneTempt() {
	fprintf(stdout, " === The history of the working set ===\n");

	//TEST CODE
	list_of_page_size = 4;
	list_of_pages = malloc(list_of_page_size*sizeof(int));
	list_of_pages[0] = 2;
	list_of_pages[1] = 1;
	list_of_pages[2] = 2;
	list_of_pages[3] = 6;
	// list_of_pages[4] = 3;

	int i = 0;
	int total = 0;
	fprintf(stdout, "Total number of working sets: %d\n", list_of_page_size);

	// loop through all the history pages, and prints out the working set
	for(i = 0; i < list_of_page_size; i++) {
		// fprintf(stdout, "TOTAL BEFORE: %d\n", total);
		fprintf(stdout, "%d\n", list_of_pages[i]);
		total = total + list_of_pages[i];
		// fprintf(stdout, "TOTAL AFTER: %d\n", total);
	}
	fprintf(stdout, "total: %d size: %d\n", total, list_of_page_size);
	float avg = (float)total/(float)list_of_page_size; // bumps it down always no matter what
	fprintf(stdout, "\nAverage Working Set Size: %f\n", avg);
}

void process() {
	printf("QUICKSORT\n");
	printf("Page size: %d, Window Size: %d\n", page_size, window_size);

	// init(page_size, window_size);
	// dummy();
	doneTempt();
}

int main(int argc, char** argv) {
	// error checking
	page_size = atoi(argv[1]);
	window_size = atoi(argv[2]);

	process();
	return 0;
}