#include "header.h"

node_t* delete_B_Pos (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int position;
		printf ("Enter position \n");
		scanf ("%d", &position);
	
		if (position > length (list)) {
			printf ("invalid position \n");
		} else if (position == 1) {
			printf ("no before nodes to delete \n");
		} else if (position == 2) {
			list = delete_Fst (list);
		} else {
			node_t *temp = list->link;
			node_t *ptr;
			int i = 2;
			while (i < position - 1) {
				temp = temp->link;
				i++;
			}
			ptr = temp->link;
			temp->link = ptr->link;
			ptr->link = NULL;
			free (ptr);
		}
	}
	return list;
}
