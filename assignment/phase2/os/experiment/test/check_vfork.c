#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int j = 1;
int main ()
{
	int local = 10;
	pid_t pid;
	pid = vfork ();
	if (pid > 0) {
		printf ("Parent process \n");
		printf ("%d \n", getpid ());
		printf ("%d \n", j);
		printf ("%d \n", local);
	} else if (pid == 0) {
		printf ("Child process \n");
		printf ("%d \n", getpid());
		j = 2;
		printf ("%d \n", local);
	//	exit (2);
	}
	return 0;
}
	
