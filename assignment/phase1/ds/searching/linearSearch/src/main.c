#include "header.h"

int main ()
{
	int array[MAX];
	int *ptr;
	char key[MAX];
	int keyE;
	char size[MAX];
	int size1;
	int i;
	int index;
	printf("Enter size of array \n");
	fgets(size, MAX, stdin);
	size1 = validation (size);
	if (size1 >= 0) {
		__fpurge(stdin);
		printf("Enter elements into array \n");
		for (i = 0; i < size1; i++) {
			scanf("%d", &array[i]);
		}
		__fpurge(stdin);
		printf("Enter search key \n");
		fgets(key, MAX, stdin);
		keyE = validation (key);
		if (keyE >= 0) {
			index = linearsearch (array, size1, keyE);
			if (index == -1) {
				printf("Element not found \n");
			} else {
				printf("element found at position %d\n", index);
			}
		}
	}
	return 0;
}
	
