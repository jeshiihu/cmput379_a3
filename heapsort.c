#include "simulator.h"

#include <stdio.h>
#include <time.h>
 
int max (unsigned int n, unsigned int i, unsigned int j, unsigned int k) {
    unsigned int m = i;
    if (j < n && get(j) > get(m)) {
        m = j;
    }
    if (k < n && get(k) > get(m)) {
        m = k;
    }
    return m;
}
 
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
        printf ("Sorting %1d keys\n", n);
    }
}
 
void heapsort (unsigned int n) {

    unsigned int i;

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
	for (i = 0; i < N; i++) {
		put(i, lrand48 ());
	}

	heapsort(N);

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
