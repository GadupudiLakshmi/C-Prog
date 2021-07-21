#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main ()
{
	static int i = 10;
	
	pid_t pid;
	pid = fork ();
	
	if (pid > 0) {
		printf ("Parent process \n");
		printf ("%d \n", getpid ());
	} else if (pid == 0) {
		printf ("Child process \n");
		printf ("%d \n", getpid ());
		getchar ();
	} else {
		printf ("no child \n");
	}
//	getchar ();
	return 0;
}
