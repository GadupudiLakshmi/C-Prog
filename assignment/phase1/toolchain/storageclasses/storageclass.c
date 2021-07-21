#include <stdio.h>

int num = 10;
void function1 ();
void function2 ();
int main ()
{
	function1 ();
	function2 ();
	function3 ();
	return 0;
}

void function1 () {
	printf("num is %d \n", num);
}

void function2 () {
	printf("num is %d \n", num);
}
