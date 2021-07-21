#include <stdio.h>

int fun ();
int main ()
{
	int val = 10;
	printf ("%ld \n", &val);
	fun ();
	printf ("%d \n", val);
	return 0;
}

int fun ()
{
	int i;
	printf ("%ld \n", &i);
	int *x = &i;
//	x = x + 10;
//	printf ("%ld \n", x);
//	*x = 40;
}
	
