#include "header.h"

int StrSpn (const char *str, const char *accept) {
	char *ptr;
	char *ptr2;
	int count = 0;
	ptr = accept;

	while (*str != '\0' && *str != '\n') {
		while (*accept != '\0') {
			if (*str == *accept) {
				count++;
				break;
			} else {
				if (*accept == '\n' && count == 0) {
					return count;
				} else {
					accept++;
				}
			}
		}
		accept = ptr;
		str++;
	}
	return count;
}
