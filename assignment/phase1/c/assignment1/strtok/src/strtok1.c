#include "header.h"

char * StrTok (char *string, const char *del) {
	char *ptr = string;
	char *ptr2 = del;
	while (*string != '\n') {
		del = ptr2;		// pointing del position to previous position

		//comparing every character of 'string' and checking it is equal

		while (*del != '\n') {
			if (*string == *del) { 
				
				/* if any character of string and del are equal then
						replace the matched character of string with '\0' */

				*string = '\0';		
				if (*ptr != '\0') {

					// printing the found token
					printf("%s \n", ptr);	
				}
				string++;	// incrementing string position
				ptr = string;
				return ptr;  // return the remaining string
			} else {
				del++;
			}
		}
		string++;
	}
	
	// check string reached end and return NULL if no more tokens to return

	if (*ptr != '\n' || *ptr != '\0') { 
		printf("%s", ptr);
		return NULL;
	}
}
				
