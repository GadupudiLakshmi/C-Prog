#include "header.h"

int bubblesort (int *array, int size) {
	int i;
	int j;
	int temp;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
				temp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = temp;
			
		}
	}
	return *array;
}
