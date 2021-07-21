#include <stdio.h>
#define SIZE 50
int main ()
{
	char *string;
	
	string = (char*) malloc (SIZE * sizeof (int));
	fgets (string. SIZE, stdin);
	
	for (i = 0; *(string + i) != '\n'; i++) {
		if (*(string + i) == ',') {
			continue;
		}else if (*(string + i) == *(string + i + 1) + 1) {
				count++;
				if (count > 2)
		}
