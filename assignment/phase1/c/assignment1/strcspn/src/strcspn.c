//!@file strcspn.c
#include "header.h"

int StrCSpn (const char *str, const char *reject) {
	char *ptr;
	char *ptr2;
	int count = 0;
	ptr = reject;

	while (*str != '\0' && *str != '\n') {
		while (*reject != '\0') {
			if (*str == *reject) {
				return count;
			} else {
				if (*reject == '\n') {
					count++;
				}
				reject++;
			}
		}

		reject = ptr;
		str++;
	}
	return count;
}
