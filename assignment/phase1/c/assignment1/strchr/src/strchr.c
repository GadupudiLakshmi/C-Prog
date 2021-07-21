//!@file strchr.c
#include "header.h"

char * StrChr (const char *string, int c) {
	char character;
	character = c;
	printf("%c \n", character);
	while (*string != '\n') {
		if (*string == c) {
			return string;
		} else {
			*string++;
		}
	}
	return NULL;
}

