#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>

int main ()
{
	char arr[10];
	char arr1[10];
	char *myfile = "myfile";
	if (mkfifo (myfile, 0666) == -1) { // creating fifo file
		printf ("Cannot create, file already exists\n");
	}
	while (1) {
		int fd = open ("myfile", O_WRONLY);
		if (fd == -1) {
			printf ("Can't open file \n");
		} else {
			fgets (arr, 10, stdin);
			if (write (fd, arr, 10) == -1) {
				return 1;
			}
			if (arr[0] == '\n') {
				printf ("Lets end the chat \n");
				exit (0);
			}
			printf ("Sent %s \n", arr);
			close (fd);
	
			fd = open ("myfile", O_RDONLY);
			if (fd == -1) {
				printf ("can't open file \n");
			} else {
				if (read (fd, arr1, 10) == -1) {
					return 1;
				}
				if (arr1[0] == '\n') {
					printf ("Received Termination \n");
					exit (0);
				}	
				printf ("received %s \n", arr1);
				close (fd);
			}
		}
	}
	
	return 0;
}

