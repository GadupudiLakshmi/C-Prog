#include "header.h"

void merge (int low, int mid, int high, int *arr)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int Lsize = mid;
	int Rsize = high - mid;
	int left [Lsize];
	int right [Rsize];
	
	for (i = 0; i < Lsize; i++, k++) {
		left[i] = *(arr + k);
	}
	for (i = 0; i < Rsize; i++, k++) {
		right[i] = *(arr + k);
	}
	i = 0;
	k = 0;
	while (i < Lsize && j < Rsize) {
		if (*(left + i) <= *(right + j)) {
			*(arr + k) = *(left + i);
			i++;
		} else {
			*(arr + k) = *(right + j);
			j++;
		}
		k++;
	}
	
	while (i < Lsize) {
		*(arr + k) = *(left + i);
		i++;
		k++;
	}

	while (j < Rsize) {
		*(arr + k) = *(right + j);
		j++;
		k++;
	}
}
