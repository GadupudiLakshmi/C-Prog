#include "header.h"

D_node_t* insert_Pos (D_node_t *header) {
	D_node_t *ptr = NULL;
	if (header->prev == header && header->next == header) {
		ptr = createnode (ptr);
		ptr->prev = header;
		header->next = ptr;
		ptr->next = header;
		header->prev = ptr;
	} else {
		int position;
		printf ("enter position \n");
		scanf ("%d", &position);
		if (position > length (header)) {
			printf ("invalid position \n");
		} else if (position == 1) {
			header = insert_Fst (header);
		} else {
			D_node_t *temp = header->next;
			D_node_t *ptr1 = NULL;
			int i = 1;
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
