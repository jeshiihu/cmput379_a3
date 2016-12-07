
#include "simulator.h"

//////// Code base on: http://www.geeksforgeeks.org/quicksort-tail-call-optimization-reducing-worst-case-space-log-n/
// has been modified to function correctly with the hastable

// takes in two indices (keys to the hash table)
void swap(unsigned int index1, unsigned int index2) {
	int tmp = get(index1);
	put(index1, get(index2));
	put(index2, tmp);
}

int inPlacePartitioning(unsigned int beginIndex, unsigned int endIndex) {
	int pivot = get(endIndex); // start with end value being the pivot
	unsigned int i = beginIndex;

	int j; // start in the beginning swap the values if less than pivot
	for(j = beginIndex; j <= endIndex-1; j++) {
		if(get(j) <= pivot) {
			swap(i, j);
			i++;
		}
	}

 	// swap pivot element to correct spot and return
	swap(i, endIndex);
	return i;
}

// beginIndex and endIndex are indices not data elements
void quicksort(unsigned int beginIndex, unsigned int endIndex) {
	// recursively call sort until all values sorted
	while(beginIndex < endIndex) {
		unsigned int pivot = inPlacePartitioning(beginIndex, endIndex);

		if((pivot - beginIndex) < endIndex - pivot) {
			quicksort(beginIndex, pivot-1);
			beginIndex = pivot + 1;
		}
		else {
			quicksort(pivot + 1, endIndex);
			endIndex = pivot-1;
		}
	}
}

void process() {
	printf("QUICKSORT\n"); // indicating to the user the sort they are running
	printf("Page size: %d, Window Size: %d\n", page_size, window_size);

	// prompts for the number of elements the user wants to sort
	printf("Please input the number of elements you wish to sort: ");
	while(numberOfElements <= 0)
		scanf("%d", &numberOfElements);

	init(page_size, window_size);
	printf("Sorting %d values\n", numberOfElements);

	// generate random values
	unsigned int i;
	srand(time(NULL));

	for(i = 0; i < numberOfElements; i++) {
		put(i, lrand48());
	}

	quicksort(0, numberOfElements-1);
}

int main(int argc, char** argv) {

	if (argc != 3) {
		printf("Invalid arguments, please try again!\n");
		return 0;
	}

	page_size = atoi(argv[1]);
	window_size = atoi(argv[2]);

	process();
	done();
	
	return 0;
}