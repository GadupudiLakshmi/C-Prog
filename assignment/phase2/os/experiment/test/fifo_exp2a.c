#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ()
{
	char arr[10];
	char arr1[10];
	while (1) {
		int fd = open ("SUM", O_RDONLY);
		int i;
		read (fd, arr, 10);
		printf ("Received %s \n", arr);
		close (fd);
	
		fd = open ("SUM", O_WRONLY);
		fgets (arr1, 10, stdin);
		write (fd, arr1, 10);
		printf ("Sent %s \n", arr1);
	
		close (fd);
	}
	return 0;
}
