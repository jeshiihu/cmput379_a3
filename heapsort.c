#include "simulator.h"

//finds address of the node with highest value between node node i, and it's children j and k
unsigned int max (unsigned int n, unsigned int i, unsigned int j, unsigned int k) {
    unsigned int m = i;
    if (j > n) {
    	return m;
    }
    
    if (j < n && get(j) > get(m)) {
        m = j;
    }
    if (k > n) {
    	return m;
    }

    if (k < n && get(k) > get(m)) {
        m = k;
    }
    return m;
}

//swaps address of node i and one of it's children nodes if one of them has higher value
void downheap (unsigned int n, unsigned int i) {
    while (1) {
        unsigned int j = max(n, i, 2 * i + 1, 2 * i + 2);
        if (j == i) {
            break;
        }
        int t = get(i);
        put(i, get(j));
        put(j,t);
        i = j;
    }
}

//main heapsort function that calls downheap
//calls downheap until it is at the end of array
//then replace the top or highest node with last node and then downheap
void heapsort (unsigned int n) {

    unsigned int i;

    for (i = (n - 2) / 2; (int)i >= 0; i--) {

        downheap(n, i);
    }
    for (i = 0; i < n; i++) {
        int t = get(n - i - 1);
        put((n-i-1), get(0));
        put(0, t);
        downheap(n - i - 1, 0);
    }
}
 
 //process function that takes in inputs and call heapsort
void process() {
	srand (time(NULL));
	printf("HEAPSORT\n");
	
	/* This process function generates a number of integer */
	/* keys and sorts them using bubblesort. */
	unsigned int N, i;
	printf("Please input the number of elements you wish to sort: ");
	scanf ("%u", &N);
	numberOfElements = N;
	
	init(page_size, window_size);

	printf ("Sorting %u keys\n", N);


	/* Generate the sorting problem (just random numbers) */
	for (i = 0; i < N; i++) {
		put(i, rand());
	}

	heapsort(N);
}

//reads arguments, calls process, then done function
int main(int argc, char** argv) {
	page_size = atoi(argv[1]);
	window_size = atoi(argv[2]);
	process();
	done();
	return 0;
}
