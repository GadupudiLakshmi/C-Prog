#include "header.h"
#include <time.h>

int main ()
{
	int arr[MAX];
	int i;
	int size;
	printf ("Enter size of array \n");
	scanf ("%d", &size);
	printf ("Enter %d elements \n", size);
	for (i = 0; i < size; i++) {
		scanf ("%d", &arr[i]);
	}
	
	clock_t begin = clock ();
	printf ("Begin %ld \n", begin);
	quicksort (0, size-1, arr);
	clock_t end = clock ();
	printf ("End %ld \n", end);
	printf ("diff %f \n", (double) (end - begin) / CLOCKS_PER_SEC);

	printf ("sorted array is \n");	
	for (i = 0; i < size; i++) {
		printf ("%d  ", arr[i]);
	}
	
	return 0;
}
	
