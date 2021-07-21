#include "header.h"

char * StrTok (char *string, const char *del) 
{
	char *ptr = string;

//	while (*del != '\n') {
		while (*string != '\n') {
			if (*del == *string || *(del + 1) == *string) {
				*string = '\0';
				printf("%s\n", ptr);
				string++;
				ptr = string;
				return ptr;
			} else {
				string++;
			}
		}
		del++;
	}
	if (*ptr != '\n' || *ptr != '\0') {
		printf("%s\n", ptr);
		return NULL;
	}
}
				
