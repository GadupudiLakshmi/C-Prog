#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
	FILE *fp;
	fp = fopen ("file.txt", "w+");
	pid_t pid;
	int status;
	pid = fork ();
	
	if (pid > 0) {
		printf ("Parent Process \n");
		fputs ("Lakshmi", fp);
		fclose (fp);
		wait (&status);
		printf ("child process terminated \n");

	} else if (pid == 0) {
		printf ("Child Process \n");
		fputs (" Gadupudi", fp);
		fclose (fp);
		
	} else {
		printf ("No child \n");
	}
	if (pid == 0 && WIFEXITED (status)) {
		printf ("Child terminated normally \n");
	}
	if (pid == 0 && WIFSIGNALED (status)) {
		printf (" terminated by signal \n");
	}
		
	return 0;
}
