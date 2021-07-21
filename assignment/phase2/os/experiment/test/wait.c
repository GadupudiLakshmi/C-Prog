#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
	FILE *fd;
	fd = fopen ("file.txt", "w+");
	pid_t pid;
	int status;
	pid = fork ();
	if (pid > 0) {
		printf ("Parent Process \n");
		printf ("%d \n", getpid ());
		int i = wait (&status);
		printf ("status %d \n", i);
		fputs ("Lakshmi", fd);
		fclose (fd);
	} else if (pid == 0) {
		printf ("Child Process \n");
		printf ("%d \n", getpid ());
		fputs (" Gadupudi", fd);
	} else {
		printf ("No child \n");
	}	
	return 0;
}

