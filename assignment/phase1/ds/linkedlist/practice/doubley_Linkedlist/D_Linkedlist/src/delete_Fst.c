#include "header.h"

D_node_t* delete_Fst (D_node_t *header) {
	if (header->prev == header && header->next == header) {
		printf ("List is empty \n");
	}
	D_node_t *temp = header->next;
	header->next = header->next->next;
	header->next->prev = header;
	free (temp);
	return header;
}
