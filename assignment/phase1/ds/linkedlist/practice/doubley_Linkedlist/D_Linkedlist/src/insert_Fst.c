#include "header.h"

D_node_t* insert_Fst (D_node_t *header) {
	D_node_t *ptr = NULL;
	if (header->prev == header && header->next == header) {
		ptr = createnode (ptr);
		ptr->prev = header;
		header->next = ptr;
		ptr->next = header;
		header->prev = ptr;
	} else {
		D_node_t *ptr1;
		ptr1 = createnode (ptr1);
		ptr1->next = header->next;
		ptr1->prev = header;
		header->next = ptr1;
	}
	return header;
}
