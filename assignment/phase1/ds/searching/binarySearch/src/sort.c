#include "header.h"

int sort (int *array, int size) {
	int i;
	int j;
	int temp;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if (*(array + i) > *(array + j)) {
				temp = *(array + i);
				*(array + i) = *(array + j);
				*(array + j) = temp;
			}
		}
	}
	return *array;
}
