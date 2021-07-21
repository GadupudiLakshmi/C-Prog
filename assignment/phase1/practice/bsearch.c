#include <stdio.h>

void BSearch (const void *key, const void *base, size_t n, size_t size, int (*cmp) (const void *keyval, const void *data));

int comp (const void *keyva, const void *data);
int main ()
{
	int arr[10] = {1, 5, 7, 11, 19};
	int key = 5;
	BSearch (&key, arr, 5, sizeof (int), comp);
}

int comp (const void *keyval, const void *data) {
	printf ("compare \n");
	printf ("%d-%d \n", *(int*)keyval, *(int*)data);
	int n = (*(int*)keyval - *(int*)data);
	printf ("comp %d \n", n);
	return n;
}

void BSearch (const void *key, const void *base, size_t n, size_t size, int (*cmp) (const void *keyval, const void *data)) {
	int low = 0;
	int high = n - 1;
	int mid;
	int k = *(int*)key;
	while (low <= high) {
		printf ("low %d \n", low);
		mid = (n - 1) / 2;
		printf ("mid %d \n", mid);
		printf ("key %d \n", *(int*)key);
		printf ("value %d \n", *(int*) (base + mid));
		int c = cmp (&k, (int*)(base + mid));
		if (c > 0) {
			low = mid + 1;
			printf ("low %d \n", low);
		} else if (c < 0) {
			high = mid - 1;
			printf ("high %d \n", high);
		} else {
			printf ("found \n");
			return;
		}
	}
}
