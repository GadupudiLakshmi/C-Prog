#include "header.h"

int binarysearch (int *array, int size, int key) {
//	sort (array , size);
	int mid;
	int low;
	int high;
	low = 0;
	high = size - 1;
	
	while (low <= high) {
		mid = (low + high) / 2;
		if (key == *(array + mid)) {
			return mid;
			break;
		} else if (key > *(array + mid)) {
			low = mid + 1;
		} else if (key < *(array + mid)) {
			high = mid - 1;
		}
	}
	return -1;
}
