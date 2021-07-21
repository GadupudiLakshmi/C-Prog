#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int i = 10;
int main ()
{
	int local = 1;
	printf ("%d\n", getpid());
	pid_t pid;
	pid = fork ();
	if (pid > 0) {
		printf ("parent process \n");
		local = 2;
		printf ("%x \n", &local);
	} else if (pid == 0) {
		
		printf ("%d \n", getpid());
		int a;
		scanf ("%d", &a);
		printf ("child process \n");
	} else {
		printf ("no child \n");
	}
	return 0;
}
