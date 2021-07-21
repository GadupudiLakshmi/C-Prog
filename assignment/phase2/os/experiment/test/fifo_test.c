#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
int main ()
{
	int fd;
	char *myfile = "/training/assiment/phase2/os/exeriment/test/lakshmi";
	mkfifo (myfile, 0666);
	char arr1[50];
	char arr2[50];
	while (1) {
		fd = open (myfile, O_WRONLY);
		fgets (arr2, 50, stdin);
		write (fd, arr2, strlen (arr2)+1);
		close (fd);
		
	
		fd = open (myfile, O_RDONLY);
		read (fd, arr1, sizeof (arr1));
		printf ("u2 %s \n", arr1);
		close (fd);
	}
	return 0;
}
