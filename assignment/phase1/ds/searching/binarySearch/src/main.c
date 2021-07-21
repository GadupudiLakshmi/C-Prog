#include "header.h"

int main ()
{
	int array[MAX];
	char size[MAX];
	char key[MAX];
	int size1;
	int key1;
	int i;
	int index;

	printf("Enter size of array \n");
	fgets(size, MAX, stdin);
	size1 = validation (size);
	if (size1 >= 0) {
		
		__fpurge(stdin);
		printf("enter array elements \n");
		for (i = 0; i < size1; i++) {
			scanf("%d", &array[i]);
		}
		
		__fpurge(stdin);
		printf("Enter key element \n");
		fgets(key, MAX, stdin);
		key1 = validation (key);
		if (key1 >= 0) {
			sort(array, size1);
			printf("Sorted array is \n");
			for (i = 0; i < size1; i++) {
				printf("%d ", array[i]);
			}
			printf("\n");
			index = binarysearch (array, size1, key1);
			if (index == -1) {
				printf("Element not found \n");
			} else {
				printf("Element found at position %d \n", index);
			}
		}
	}
	return 0;
}	
