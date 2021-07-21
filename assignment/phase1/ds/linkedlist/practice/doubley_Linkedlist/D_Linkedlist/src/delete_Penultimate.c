#include "header.h"

D_node_t* delete_Penultimate (D_node_t *header) {
	if (header->prev == header && header->next == header) {
		printf ("List is empty \n");
	} else {
		int position = length (header) - 1;
		if (position == 0) {
			printf ("No penultimate node \n");
		} else if (position == 1) {
			header = delete_Fst (header);
		} else {
			D_node_t *temp = header->next;
			D_node_t *ptr = NULL;
			int i = 1;
			while (i < position - 1) {
				temp = temp->next;
				i++;
			}
			ptr = temp->next;
			ptr->prev->next = ptr->next;
			ptr->next->prev = ptr->prev;
			ptr->next = NULL;
			ptr->prev = NULL;
			free (ptr);
		}
	}
	return header;
}
