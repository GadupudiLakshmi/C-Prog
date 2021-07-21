#include "header.h"

int insersionsort (int *array, int size) {
	int i;
	int j;
	int copy;
	for (i = 1; i < size; i++) {
		copy = *(array + i);
		j = i - 1;
		for (j = i - 1; (j >= 0) && (*(array + j) > copy); j--) {
			*(array + (j + 1)) = *(array + j);
		}
		*(array + (j + 1)) = copy;
	} 
	return *array;
}
		
			
