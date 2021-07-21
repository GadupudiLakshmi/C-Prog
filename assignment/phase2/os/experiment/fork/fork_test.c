#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int global = 0;
void sort (int*, int);
int main ()
{
	pid_t pid;
	pid = fork ();
	if (pid > 0) {
		printf ("parent process \n");
		int i = 0;
		for (i = 0; i < size; i++) {
			if (arr[i] % 2 == 0) {
				printf ("%d ", arr[i]);
			}
		}
		printf ("\n");
		wait (0);
	} else if (pid == 0) {
		
		printf ("child process \n");
		int i = 0;
		for (i = 0; i < size; i++) {
			if (arr[i] % 2 != 0) {
				printf ("%d ", arr[i]);
			}
		}
		printf ("\n");
	} else {
		printf ("no child \n");
	}
	return 0;
}

void sort (int *arr, int size) {
	int i = 0;
	int j = 0;
	for (i = 0; i < size; i++) {
		for (j = i + 1; j < size; j++) {
			if(*(arr + i) > *(arr + j)) {
				int temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}
