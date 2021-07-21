#include "header.h"
#include <time.h>
int main ()
{
	int array[MAX];
	char size[MAX];
	int size1;
	int i;
	printf("Enter size of the array \n");
	fgets(size, MAX, stdin);
	size1 = validation (size);
	if (size1 >= 0) {
		__fpurge(stdin);
		printf("Enter elements into array \n");
		for (i = 0; i < size1; i++) {
			scanf("%d", &array[i]);
		}
		char *ct;
		time_t sec;
		time (&sec);
		ct = ctime (&sec);
		printf ("time %ld \n", sec);
		printf ("bef%s \n", ct);

		clock_t begin = clock ();
		printf ("be %ld \n", begin);
		bubblesort (array, size1);
		clock_t end = clock ();
		printf ("en %ld \n", end);
		
		printf ("diff %f \n", (double) (end - begin) / CLOCKS_PER_SEC);
		
		time (&sec);
		ct = ctime (&sec);
		printf ("ti2 %ld \n", sec);
		printf ("%s \n", ct);
		for (i = 0; i < size1; i++) {
			printf("%d ", array[i]);
		}
	}
		
}
		
