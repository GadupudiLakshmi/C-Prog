#include "header.h"

D_node_t* insert_Penultimate (D_node_t *header) {
	D_node_t *ptr = NULL;
	if (header->prev == header && header->next == header) {
		printf ("No nodes \n");
	} else {
		int position = length (header) - 1;
		if (position == 0) {
			header = insert_Fst (header);
		} else {
			D_node_t *temp = header->next;
			D_node_t *ptr1 = NULL;
			int i = 0;
			while (i < position - 1) {
				temp = temp->next;
				i++;
			}
			ptr1 = createnode (ptr1);
			ptr1->prev = temp;
			ptr1->next = temp->next;
			temp->next = ptr1;
			ptr1->next->prev = ptr1;
		}
	}
	return header;
}
