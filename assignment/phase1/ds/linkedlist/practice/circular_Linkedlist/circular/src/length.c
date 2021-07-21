#include "header.h"

int length (node_t *list) {
	int length = 0;
	if (list == NULL) {
		return length;
	} else {
		node_t *ptr = list->link;
		while (ptr != list) {
			length++;
			ptr = ptr->link;
		}
		length++;
	}
	return length;
}
