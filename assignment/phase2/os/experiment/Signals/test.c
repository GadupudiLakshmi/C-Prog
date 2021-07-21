#include <stdio.h>
#include <signal.h>

int handler (int sig_num)
{
	printf ("signal generated %d\n", sig_num);
	printf ("no \n");
	return 1;
}

int main ()
{
	char *ptr = "lak";
	signal (SIGSEGV, (void *) handler);
	*(ptr + 1) = 'a';
	printf ("oak\n");
	exit (1);
	return 0;
}
