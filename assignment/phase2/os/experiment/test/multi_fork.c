#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main ()
{
	pid_t pid1;
	pid1 = fork ();
	if (pid1 > 0) {
		wait (NULL);
		printf ("Child1 terminated \n"); 
		printf ("Parent1 \n");
		printf ("%d \n", getpid ());
	} else if (pid1 == 0) {
		printf ("Child1 \n");
		printf ("%d \n", getpid ());
	} else {
		printf ("no child \n");
	}

	printf ("%d \n", pid1);	
	pid_t pid2;
	pid2 = fork ();
	if (pid2 > 0 && pid1 > 0) {
		wait (NULL);
		printf ("child2 terminated \n");
		printf ("parent2 \n");
		printf ("%d \n", getpid ());
	} else if (pid2 > 0 && pid1 == 0) {
		wait (NULL);
		printf ("CChild2 terminated \n");
		printf ("parent2 \n");
		printf ("%d \n", getpid ());
	} else if (pid2 == 0 && pid1 > 0) {
		printf ("Pchild2 \n");
		printf ("%d \n", getpid ());
	} else if (pid2 == 0 && pid1 == 0) {
		printf ("CChild2 \n");
		printf ("%d \n", getpid ());
	} else {
		printf ("no child \n");
	}
	return 0;
}	
