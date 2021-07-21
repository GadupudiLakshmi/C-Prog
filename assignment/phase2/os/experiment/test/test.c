#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int i = 10;
int main ()
{
	int local = 1;
	printf ("%d\n", getpid());
	pid_t pid;
	pid = fork ();
	if (pid > 0) {
		printf ("%d \n", i);
		printf ("parent process \n");
		local = 2;
		printf ("%x \n", &local);
		exit (0);
	} else if (pid == 0) {
		printf ("%d \n", i);
		printf ("child process \n");
		printf ("%x \n", &local);
		printf ("%d \n", local);
		i = 20;
		getchar ();
	} else {
		printf ("no child \n");
	}
	return 0;
}
