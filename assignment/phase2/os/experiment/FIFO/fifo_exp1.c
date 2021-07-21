#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
	char arr[10];
	int i;
//	for (i = 0; i < 10; i++) {
//		arr[i] = i;
//	}
//	for (i = 0; i < 10; i++) {
//		scanf ("%c", &arr[i]);
//	}
	fgets (arr, 10, stdin);
	int fd = open ("SUM", O_WRONLY);
	for (i = 0; i < 10; i++) {
		write (fd, &arr[i], sizeof (char));
		printf ("W %c \n", arr[i]);
	}
	close (fd);
	return 0;
}

