#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int global;
int main ()
{
	pid_t pid;
	pid = vfork ();
	if (pid > 0) {
		printf ("Parent process \n");
		printf ("%d \n", getpid ());
		printf ("after %d \n", global);
	} else if (pid == 0) {
		printf ("Child process \n");
		printf ("%d \n", getpid());
		printf ("before %d \n", global);
		global = 2;
		exit (2);
	}
	return 0;
}
	
