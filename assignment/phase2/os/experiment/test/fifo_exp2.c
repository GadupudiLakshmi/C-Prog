#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
	char arr[10];
	char arr1[10];
	int i;
	while (1) {
		int fd = open ("SUM", O_WRONLY);
		if (fd == -1) {
			printf ("Can't open file \n");
		} else {
			fgets (arr, 10, stdin);
			if (write (fd, arr, 10) == -1) {
				return 1;
			}
			printf ("Sent %s \n", arr);
			close (fd);
	
			fd = open ("SUM", O_RDONLY);
			if (fd == -1) {
				printf ("can't open file \n");
			} else {
				if (read (fd, arr1, 10) == -1) {
					return 1;
				}
				printf ("received %s \n", arr1);
				close (fd);
			}
		}
	}
	return 0;
}

