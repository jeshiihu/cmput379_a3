#include "simulator.h"

#include <stdio.h>
#include <time.h>
 
unsigned int max (unsigned int n, unsigned int i, unsigned int j, unsigned int k) {
    unsigned int m = i;
    printf("max loop\n");
    printf("compare j: %d to m: %d \n", j, m);

    printf("compare j: %d: %d to m: %d: %d \n", j, get(j), m, get(m));
    if (j < n && get(j) > get(m)) {
    	printf("here3\n");
        m = j;
    }
    printf("compare k: %d to m: %d \n", k, m);

    printf("compare k: %d: %d to m: %d: %d \n", k, get(k), m, get(m));
    if (k < n && get(k) > get(m)) {
    	printf("here2\n");
        m = k;
    }
    printf("here4\n");
    return m;
}
 
void downheap (unsigned int n, unsigned int i) {
    while (1) {
    	printf("here\n");
        unsigned int j = max(n, i, 2 * i + 1, 2 * i + 2);
        printf("here1\n");
        if (j == i) {
            break;
        }
        int t = get(i);
        put(i, get(j));
        put(j,t);
        i = j;
    }
}
 
void heapsort (unsigned int n) {

    unsigned int i = 0;

    for (i = (n - 2) / 2; i >= 0; i--) {
        downheap(n, i);
    }
    for (i = 0; i < n; i++) {
        int t = get(n - i - 1);
        put((n-i-1), get(0));
        put(0, t);
        downheap(n - i - 1, 0);
    }
}
 
void process() {
	srand (time(NULL));
	printf("HEAPSORT\n");
	/* This process function generates a number of integer */
	/* keys and sorts them using bubblesort. */
	unsigned int N, i, j, k, t, min, f;
	scanf ("%d", &N);
	printf ("Sorting %1d keys\n", N);

	init(128, 1000);

	// init(page_size, window_size);
	/* Generate the sorting problem (just random numbers) */
	// for (i = 0; i < N; i++) {
	// 	put(i, lrand48 ());
	// }
	put(0, 4);
	put(1, 10);
	put(2, 3);
	put(3, 5);
	put(4, 1);

	heapsort(5);

		printf ("Sorting %1d keys\n", N);


	int n = N;
	for (i = 0; i < n; i++) {
        printf("%d%s", get(i), i == n - 1 ? "\n" : " ");
	}
    for (i = 0; i < n; i++)
        printf("%d%s", get(i), i == n - 1 ? "\n" : " ");
	printf("Page size: %d, Window Size: %d\n", 128, 1000);

	//done ();
}

int main(int argc, char** argv) {
	process();
	return 0;
}
