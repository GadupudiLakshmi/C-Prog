#include "header.h"

char * StrStr (const char *string, const char *substring) {
	char *ptr;
	ptr = string;
		
	while (*string != '\n' && *substring != '\n') {
		if (*string == *substring) {
			string++;
			substring++;
		} else {
			ptr++;
			string++;
		}
	}
	if (*substring == '\n') {
		return ptr;
	} else {
		return NULL;
	}
}
