#include "header.h"
#include <time.h>

int main ()
{
	int array[MAX];
	char size[MAX];
	int size1;
	int i;
	
	printf("Enter size \n");
	fgets(size, MAX, stdin);
	size1 = validation (size);
	
	__fpurge(stdin);
	printf("Enter elements into array \n");
	for (i = 0; i < size1; i++) {
		scanf("%d", &array[i]);
	}
	
	clock_t begin = clock ();
	printf ("Begin %ld \n", begin);	
	selectionsort (array, size1);
	clock_t end = clock ();
	printf ("End %ld \n", end);
	printf ("diff %f \n", (double) (end - begin) / CLOCKS_PER_SEC);
	for (i = 0; i < size1; i++) {
		printf("%d ", array[i]);
	}
	return 0;
}
