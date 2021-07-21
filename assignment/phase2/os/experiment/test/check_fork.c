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
		i = 20;
		printf ("%d \n", i);
		wait (NULL);
		getchar ();
		printf ("child terminated \n");
		printf ("%d \n", i);
	} else if (pid == 0) {
		printf ("Child process \n");
		i = i + 5;
		printf ("%d \n", i);
	} else {
		printf ("no child \n");
	}
	
	return 0;
}
