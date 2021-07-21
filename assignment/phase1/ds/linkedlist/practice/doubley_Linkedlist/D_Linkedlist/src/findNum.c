#include "header.h"

int find (int num, D_node_t *header) {
	int position = 0;
	if (header->prev == header && header->next == header) {
		return -1;
	} else {
		D_node_t *temp = header->next;
		while (temp->next != header) {
			position++;
			if (temp->data == num) {
				return position;
			}
			temp = temp->next;
		}
		if (temp->data == num) {
			position++;
			return position;
		}
	}
	position = -1;
	return position;
}
