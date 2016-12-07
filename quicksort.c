
#include "simulator.h"

void swap(unsigned int index1, unsigned int index2) {
	int tmp = get(index1);
	put(index1, get(index2));
	put(index2, tmp);
}

int inPlacePartitioning(unsigned int beginIndex, unsigned int endIndex) {
	int pivot = get(endIndex); // getting pivot element
	unsigned int i = beginIndex;

	int j;
	for(j = beginIndex; j <= endIndex-1; j++) {
		if(get(j) <= pivot) {
			swap(i, j);
			i++;
		}
	}

	swap(i, endIndex);
	return i;
}

// beginIndex and endIndex are indices not data elements
void quicksort(unsigned int beginIndex, unsigned int endIndex) {
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
	printf("QUICKSORT\n");
	printf("Page size: %d, Window Size: %d\n", page_size, window_size);


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

	// numberOfElements = 10;
	// put(0, 14);
	// put(1, 1);
	// put(2, 12);
	// put(3, 5);
	// put(4, 26);
	// put(5, 7);
	// put(6, 14);
	// put(7, 3);
	// put(8, 7);
	// put(9, 2);

	quicksort(0, numberOfElements-1);
}

int main(int argc, char** argv) {
	// error checking
	if (argc != 3)
	{
		printf("Invalid arguments, please try again!\n");
		return 0;
	}

	page_size = atoi(argv[1]);
	window_size = atoi(argv[2]);

	process();
	done();
	
	return 0;
}