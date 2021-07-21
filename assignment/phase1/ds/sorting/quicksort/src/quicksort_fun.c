#include "header.h"

void quicksort (int low, int high, int *arr)
{
	int j;
	int i;
	if (low < high) {
		int j = divide (low, high, arr);	
		quicksort (low, j, arr);
		quicksort (j + 1, high, arr);
	}
	
//	for (i = 0; i < 9; i++) {
//		printf ("%d \n", *arr++);
//	}
}

