#include "header.h"

D_node_t* insert_Middle (D_node_t *header) {
	if (header->prev == header && header->next == header) {
		printf ("list is empty \n");
	} else {
		int position;
		position = length (header) / 2;
		if (position < 1) {
			printf ("Cannot find middle \n");
		} else {
			D_node_t *temp = header->next;
			D_node_t *ptr = NULL;
			int i = 0;
			while (i < position - 1) {
				temp = temp->next;
				i++;
			}
			ptr = createnode (ptr);
			ptr->prev = temp;
			ptr->next = temp->next;
			temp->next = ptr;
			ptr->next->prev = ptr;
		}
	}
	return header;
}
