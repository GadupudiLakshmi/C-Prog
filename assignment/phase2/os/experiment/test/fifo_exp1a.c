#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>

int main ()
{
	char arr[10];
	int fd = open ("SUM", O_RDONLY);
	int i;
	for (i = 0; i < 10; i++) {
		read (fd, arr, sizeof (char));
		printf ("R %s \n", arr);
	}
	close (fd);
	return 0;
}
