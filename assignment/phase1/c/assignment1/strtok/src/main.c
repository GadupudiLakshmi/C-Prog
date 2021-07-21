#include "header.h"

int main ()
{
	char *string;
	char *dellocator;
	char *token;

	string = (char *) malloc (100 * sizeof (char));
	dellocator = (char *) malloc (100 * sizeof (char));

	printf ("Enter string \n");
	fgets (string, MAX, stdin);

	printf ("Enter dellocator \n");
	fgets (dellocator, MAX, stdin);

	token = StrTok (string, dellocator);
	while (token != NULL) {
	//	printf("%s \n", token);
		token = StrTok (token, dellocator);
	}
	
	free (string);
	free (dellocator); 
	return 0;
}

