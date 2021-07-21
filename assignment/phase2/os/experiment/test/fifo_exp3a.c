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
		int fd = open ("myfile", O_RDONLY);
		int i;
		read (fd, arr, 10);
		if (arr == "END") {
			printf ("Recieved termination \n");
			exit (0);
		}
		printf ("Received %s \n", arr);
		close (fd);
	
		fd = open ("myfile", O_WRONLY);
		fgets (arr1, 10, stdin);
		write (fd, arr1, 10);
		if (arr1[0] == '\n') {
			printf ("Lets end the chat \n");
			exit (0);
		}
		printf ("Sent %s \n", arr1);
	
		close (fd);
	}
	
	return 0;
}
