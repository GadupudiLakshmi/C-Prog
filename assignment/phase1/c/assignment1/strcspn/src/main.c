//!@file main.c
//!@author Lakshmi
//!@brief strcspn
//!@date 11/04/2021

#include "header.h"

int main ()
{
	char *string1;
	char *string2;
	int count;
	string1 = (char *) malloc (100 * sizeof (char));
	string2 = (char *) malloc (100 * sizeof (char));
	printf("Enter String \n");
	fgets (string1, MAX, stdin);
	printf("Enter reject string \n");
	fgets (string2, MAX, stdin);
	count = StrCSpn (string1, string2);
	printf("length of the prefix substring - %d \n", count);
	
	free (string1);
	free (string2);
	return 0;
}

