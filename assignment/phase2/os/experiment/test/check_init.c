#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <stdlib.h>

int main ()
{
	pid_t pid;
	pid = fork ();
	if (pid > 0) {
		printf ("%d \n", getpid ());
		
		printf ("parent process \n");
		exit (0);
	} else if (pid == 0) {
		printf ("child process \n");
		printf ("%d \n", getpid ());
	} else {
		printf ("no child \n");
	}
	return 0;
}
