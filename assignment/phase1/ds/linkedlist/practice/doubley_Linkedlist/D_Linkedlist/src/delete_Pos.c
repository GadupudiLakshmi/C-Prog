#include "header.h"

D_node_t* delete_Pos (D_node_t *header) {
	int position;
	printf ("Enter position \n");
	scanf ("%d", &position);
	if (position > length (header)) {
		printf ("Invalid Position \n");
	} else if (position == 1) {	
		header = delete_Fst (header);
	} else if (position == length (header)) {
		header = delete_End (header);
	} else {
		D_node_t *temp = header->next;
		D_node_t *ptr;
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
	return header;
}
