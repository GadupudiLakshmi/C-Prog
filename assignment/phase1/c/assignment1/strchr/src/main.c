//!@file main.c
//!@author lakshmi
//!@brief strchr
//!@date 11/04/2021

#include "header.h"

int main ()
{
	char *string1;
	int character;
	char *ch;
	string1 = (char *) malloc (100 * sizeof (char));
//	character = (char *) malloc (100 * sizeof (char));
	printf("Enter String \n");
	fgets (string1, MAX, stdin);
	printf("Enter character \n");
	scanf("%d", &character);
	ch = StrChr (string1, character);
	
	if (NULL) {
		printf("Not found \n");
	} else {
		printf("%s \n", ch);
	}
	free (string1);
	return 0;
}

