#include "header.h"

D_node_t* delete_Middle (D_node_t *header) {
	if (header->prev == header && header->next == header) {
		printf ("List is empty \n");
	} else {
		int position;
		position = length (header) / 2;
		printf ("%d \n", position);
		if (length (header) > 2) {
			if (position < 1) {
				printf ("Mid not found \n");
			} 

		 else {
			D_node_t *temp = header->next;
			D_node_t *ptr = NULL;
			int i = 0;
			while (i < position - 1) {
				temp = temp->next;
				i++;
			}
			ptr = temp->next;
			ptr->prev->next = ptr->next;
			ptr->next->prev = temp->prev;
			ptr->prev = NULL;
			ptr->next = NULL;
			free (ptr);
		}
	}
	}
	return header;
}

