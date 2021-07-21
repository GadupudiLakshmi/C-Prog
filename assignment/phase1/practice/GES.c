#include <stdio.h>
/*int main ()
{
	char a[30] = "hello";
	char *p = a;
	(*p)++;
	printf ("%s \n", p);
	p++;
	printf ("%s",p);
	return 0;
} 

int func (int i)
{
	if (i%2)
	return 0;
	else 
	return 1;
}
int main ()
{
	int i = 3;
	i = func (i);
	i = func (i);
	printf ("%d ", i);
	}


int main (int argc, char **argv)
{
	int k;
	for (k = 0;k < argc;k++) 
	printf ("%s", argv[++k]);
} 

char * myfunc (char *ptr) {
	ptr+=3;
	return (ptr);
}
int main ()
{
	char *x, *y;
	x = "Hello";
	y = myfunc (x);
	printf ("y = %s \n", y);
	return 0;
} 

int main ()
{
	char ***p;
	printf ("%d %d %d %d", sizeof (p), sizeof (*p), sizeof (**p), sizeof (***p));
} */

int main ()
{
	int n;
	scanf ("%d", &n);
	int c = n;
	int rev = 0;
	while (n) {
		int rem = n % 10;
		rev = rev * 10 + rem;
		n = n / 10;
	}
	if ( c == rev ) {
		printf ("palindrome \n");
	} else {
		printf ("not \n");
	}
	return 0;
}
	
