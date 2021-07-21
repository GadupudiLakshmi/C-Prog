#include "header.h"

D_node_t* insert_End (D_node_t *header) {
	D_node_t *ptr;
	if (header->prev == header && header->next == header) {
		ptr = createnode (ptr);
		ptr->prev = header;
		header->next = ptr;
		ptr->next = header;
		header->prev = ptr;
	} else {
		D_node_t *temp;
		D_node_t *ptr = header->next;
		while (ptr->next != header) {
			ptr = ptr->next;
		}
		temp = createnode (temp);
		temp->prev = ptr;
		ptr->next = temp;
		header->prev = temp;
		temp->next = header;
	}
	return header;
}

