#include "header.h"

/*	if we declare a variable as static globally the scope of that
	value is within the file */

extern int num;
void function1 ();
void function2 ();
void function3 ();
int main ()
{	
	printf ("%d \n", num);
	function1 ();
	function2 ();
//	function3 ();
	return 0;
}

void function1 () {
	printf("num is %d \n", num);
}

void function2 () {
	printf("num is %d \n", num);
}
