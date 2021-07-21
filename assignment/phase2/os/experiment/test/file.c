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
		wait (&status);
		printf ("Parent Process \n");
		printf ("%d \n", getpid ());
		fputs ("Lakshmi", fd);
		fclose (fd);
	} else if (pid == 0) {
		printf ("Child Process \n");
		printf ("%d \n", getpid ());
		fputs (" Gadupudi", fd);
		fclose (fd);
	} else {
		printf ("No child \n");
	}
	if (pid == 0 && WIFSIGNALED (status)) {
		printf ("Child terminated normally \n");
	} else {
		printf ("not exe \n");
	}
		
	return 0;
}

