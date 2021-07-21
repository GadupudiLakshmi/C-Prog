#include "header.h"

int divide (int low, int high, int *arr) {
	int pivot = *(arr + low);
	int i = low;
	int j = high;
	int temp;	
	while (i < j) {
		do {
			i++;
		} while (*(arr + i) <= pivot);
		
		do {
			j--;
		} while (*(arr + j) > pivot);
		
		if (i < j) {
			temp = *(arr + i);
			*(arr + i) = *(arr + j);
			*(arr + j) = temp;
		}
	}
	
	temp = *(arr + low);
	*(arr + low) = *(arr + j);
	*(arr + j) = temp;
	
	return j;
}
	
