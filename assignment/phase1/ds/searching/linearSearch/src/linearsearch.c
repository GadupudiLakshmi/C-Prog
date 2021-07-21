#include "header.h"

int linearsearch (int *array, int size, int key) {
	int i = 0;
	while (i < size) {
		if (*array == key) {
			return i;
		} else {
			array++;
			i++;
		}
	}
	return -1;
}
		
