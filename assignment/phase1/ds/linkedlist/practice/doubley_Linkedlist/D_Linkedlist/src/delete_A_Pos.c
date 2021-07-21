#include "header.h"

D_node_t* delete_A_Pos (D_node_t *header) {
	if (header->prev == header && header->next == header) {
		printf ("List is empty \n");
	} else {
		int position;
		printf ("Enter position \n");
		scanf ("%d", &position);

		if (position > length (header)) {
			printf ("Invalid Position \n");
		} else if (position == 0) {
			header = delete_Fst (header);
		} else if (position == length (header) - 1) {
			header = delete_End (header);
		} else if (position == length (header)) {
			printf ("no after nodes \n");
		} else {
			D_node_t *temp = header->next;
			D_node_t *ptr = NULL;
			int i = 0;
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
