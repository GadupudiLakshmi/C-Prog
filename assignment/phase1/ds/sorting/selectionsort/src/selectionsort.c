#include "header.h"

int selectionsort (int *array, int size) {
	int i;
	int j;
	int temp;
	int min;
	for (i = 0; i < size; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (*(array + j) < *(array + min)) {
				min = j;
			}
		}
		temp = *(array + i);
		*(array + i) = *(array + min);
		*(array + min) = temp;
	}
	return *array;
}
