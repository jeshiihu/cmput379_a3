
#include "simulator.h"


void printArray(int* array, int size) {
	int i;
	for(i = 0; i < size; i++) {
		printf("%d ", array[i]);
	}

	printf("\n");
}

void swap(int index1, int index2) {
	int tmpVal = get(index1);
	put(index1, get(index2));
	put(index2, tmpVal);
}

int inPlacePartitioning(int beginIndex, int endIndex) {
	int pivot = get(endIndex); // getting pivot element
	int smallerIndex = beginIndex;

	int leftIndex = beginIndex;
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
void quicksort(int beginIndex, int endIndex) {
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

	printf("Sorting %d values\n", table_size);

	// generate random values
	int i;
	srand(time(NULL));

	for(i = 0; i < numberOfElements; i++) {
		put(i, rand());
	}

	quicksort(0, numberOfElements-1);
}

int main(int argc, char** argv) {
	// error checking
	page_size = atoi(argv[1]);
	window_size = atoi(argv[2]);

	process();
	done();
	
	return 0;
}