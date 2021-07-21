#include "header.h"

void mergesort (int low, int high, int *arr)
{
	int i;
	if (low < high) {
	//if (high >= 2) {
//		printf ("low %d \n", low);
//		printf ("high %d \n", high);
		int mid = (low + high) / 2;
//		printf ("mid %d \n", mid);
		mergesort (low, mid, arr);
		mergesort (mid + 1, high, arr);
		
//		for ( i = 0; i < high; i++) {
//			printf ("%d \t", *(arr + i));
//		}
		merge (low, mid, high, arr);
	}

}
