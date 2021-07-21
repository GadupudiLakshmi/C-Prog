#include "header.h"

D_node_t* delete_End (D_node_t *header) {
	if (header->prev == header && header->next == header) {
		printf ("list is empty \n");
	} else {  
		D_node_t *ptr = header->next;
		while (ptr->next != header) {
			ptr = ptr->next;
		}
		ptr->prev->next = ptr->next;
		header->prev = ptr->prev;
		free (ptr);
	}
		return header;
}

