#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <string.h>
int main ()
{
	int fd1;
	char *myfile = "/training/assiment/phase2/os/exeriment/test/lakshmi";
	mkfifo (myfile, 0666);
	char str1[50];
	char str2[50];
	while (1) {
		fd1 = open (myfile, O_RDONLY);
		read (fd1, str1, sizeof (str1));
		close (fd1);
		
	
		fd1 = open (myfile, O_WRONLY);
		fgets (str2, 50, stdin);
		write (fd1, str2, strlen (str2)+1);
		printf ("u2 %s \n", str2);
		close (fd1);
	}
	return 0;
}
