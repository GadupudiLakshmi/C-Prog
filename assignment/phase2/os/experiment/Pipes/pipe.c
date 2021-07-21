#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main (int argc, char *argv[])
{
	int fp[2];
	int fd2[2];
	pid_t pid;
	char buff [100];
	char buff1[100];
	if (pipe (fp) != -1) {
		if (pipe (fd2) != -1) {
			pid = fork ();
			if (pid > 0) {
				printf ("Parent \n");
				close (fp[0]);
				close (fd2[1]);
				write (fp[1], "Lakshmi", 10);
				read (fd2[0], buff1, sizeof (buff1));
				printf ("%s \n", buff1);
				
			} else if (pid == 0) {
				printf ("Child process \n");
				close (fp[1]);
				close (fd2[0]);
				read (fp[0], buff1, sizeof (buff1));
				toupper (buff1);
				write (fd2[1], "gadupudi", 10);
			}
		}
	}
	fclose (file);
	return 0;
}
		
