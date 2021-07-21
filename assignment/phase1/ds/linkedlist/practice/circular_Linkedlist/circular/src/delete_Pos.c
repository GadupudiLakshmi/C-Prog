#include "header.h"

node_t* delete_Pos (node_t *list) {
	int position;
	printf ("Enter position \n");
	scanf ("%d", &position);
	if (position > length (list)) {
		printf ("Invalid Position \n");
	} else if (position == 1) {	
		list = delete_Fst (list);
	} else if (position == length (list)) {
		list = delete_End (list);
	} else {
		node_t *temp = list->link;
		node_t *ptr;
		int i = 1;
		while (i < position - 1) {
			temp = temp->link;
			i++;
		}
		ptr = temp->link;
		temp->link = ptr->link;
		ptr->link = NULL;
		free (ptr);
	}
	return list;
}
