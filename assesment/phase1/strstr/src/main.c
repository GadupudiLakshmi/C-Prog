#include "header.h"

int main ()
{
	char *string1;
	char *string2;
	char *ptr;
	int count;
	string1 = (char *) malloc (100 * sizeof (char));
	string2 = (char *) malloc (100 * sizeof (char));
	printf("Enter String \n");
	fgets (string1, MAX, stdin);
	printf("Enter substring \n");
	fgets (string2, MAX, stdin);
	ptr = StrStr (string1, string2);

	if (NULL) {
		printf("substring not matched \n");
	} else {
		printf("%s \n", ptr);
	}
	return 0;
}

