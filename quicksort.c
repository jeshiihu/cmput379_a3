
#include "simulator.h"

void process() {
	printf("QUICKSORT\n");
	printf("Page size: %d, Window Size: %d\n", page_size, window_size);
	// init(page_size, window_size);
	// dummy();
	// done();
}

int main(int argc, char** argv) {

	int i;
	page_size = atoi(argv[1]);
	window_size = atoi(argv[2]);


	process();
	return 0;
}