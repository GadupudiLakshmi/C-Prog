#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
	int fp[2];
	pid_t pid;
	FILE *file;
	FILE *fileD;
	file = fopen (argv[1], "r");
	fileD = fopen (argv [2], "w+");
	char buff;
	char buff1[100];
	if (pipe (fp) != -1) {
		pid = fork ();
		if (pid > 0) {
			printf ("Parent \n");
			while ((buff = fgetc (file)) != EOF) {
				write (fp[1], &buff, 1);
			}
			close (fp[1]);
			wait (NULL);
		} else if (pid == 0) {
			printf ("Child process \n");
			read (fp[0], &buff1, sizeof (buff1));
			fputs (buff1, fileD); 
			printf ("%s", buff1);
			close (fp[0]);
		}
	}
	fclose (file);
	return 0;
}
		
