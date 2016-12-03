
#include "simulator.h"

void swap(unsigned int index1, unsigned int index2) {
	int tmpVal = get(index1);
	put(index1, get(index2));
	put(index2, tmpVal);
}

int inPlacePartitioning(unsigned int beginIndex, unsigned int endIndex) {
	int pivot = get(endIndex); // getting pivot element
	unsigned int smallerIndex = beginIndex;

	unsigned int leftIndex = beginIndex;
	while(leftIndex < endIndex) {
		for(; leftIndex < endIndex; leftIndex++) {
			if(get(leftIndex) <= pivot) {
				swap(leftIndex, smallerIndex);
				smallerIndex++;
			}
		}

		swap(endIndex, smallerIndex);
	}
	
	return smallerIndex;
}

// beginIndex and endIndex are indices not data elements
void quicksort(unsigned int beginIndex, unsigned int endIndex) {
	int pivot = inPlacePartitioning(beginIndex, endIndex);

	if(beginIndex < pivot - 1)
		quicksort(beginIndex, pivot-1);
	if(pivot < endIndex)
		quicksort(pivot, endIndex);
}

void process() {
	printf("QUICKSORT\n");
	printf("Page size: %d, Window Size: %d\n", page_size, window_size);

	init(page_size, window_size);

	printf("Please input the number of elements you wish to sort: ");
	while(numberOfElements <= 0)
		scanf("%d", &numberOfElements);

	printf("Sorting %d values\n", numberOfElements);

	// generate random values
	unsigned int i;
	srand(time(NULL));

	for(i = 0; i < numberOfElements; i++) {
		put(i, rand());
	}

	quicksort((unsigned int)0, (unsigned int)(numberOfElements-1));
}

int main(int argc, char** argv) {
	// error checking
	page_size = atoi(argv[1]);
	window_size = atoi(argv[2]);

	process();
	done();
	
	return 0;
}