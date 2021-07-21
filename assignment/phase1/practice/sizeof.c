#include <stdio.h>

int Sizeof ();
int var;
int main ()
{
//	char var;
	printf ("Enter value \n");
	scanf ("%c", &var);
	printf ("addr of var %ld \n", &var);
	printf ("%d \n", Sizeof ());
	return 0;
}

int Sizeof () {
/*	int res;
	int *ptr = &res;
	ptr = ptr + 12;
	int x = ptr;
	res = ++ptr;
	return res - x;

*/
	int res = &var;
	int dup = &var + 1;
	return dup - res;
}
	
	
