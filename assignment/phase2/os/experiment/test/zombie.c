#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	pid_t pid;
	pid = fork ();
	
	if (pid > 0) {
		printf ("Parent process \n");
		printf ("%d \n", getpid ());
		getchar ();
	} else if (pid == 0) {
		printf ("Child process \n");
		printf ("%d \n", getpid ());
	} else {
		printf ("no child \n");
	}
	return 0;
}
