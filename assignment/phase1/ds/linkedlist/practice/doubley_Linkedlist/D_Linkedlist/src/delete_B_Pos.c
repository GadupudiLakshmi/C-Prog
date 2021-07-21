#include "header.h"

D_node_t* delete_B_Pos (D_node_t *header) {
	if (header->prev == header && header->next == header) {
		printf ("List is empty \n");
	} else {
		int position;
		printf ("Enter position \n");
		scanf ("%d", &position);
	
		if (position > length (header)) {
			printf ("invalid position \n");
		} else if (position == 1) {
			printf ("no before nodes to delete \n");
		} else if (position == 2) {
			header = delete_Fst (header);
		} else {
			D_node_t *temp = header->next;
			D_node_t *ptr;
			int i = 2;
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
