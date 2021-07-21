#include "header.h"

int main ()
{
	unsigned int NUM;
	printf("Enter number \n");
	scanf("%x", &NUM);
	printf("%x \n", NUM);
	swap (NUM);
	swap1 (NUM);
	return 0;
}
