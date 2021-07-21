#include "header.h"

int length (D_node_t *header) {
	int length = 0;
	if (header->prev == header && header->next == header) {
		return length;
	} else {
		D_node_t *ptr = header->next;
		while (ptr->next != header) {
			length++;
			ptr = ptr->next;
		}
		length++;
	}
	return length;
}
