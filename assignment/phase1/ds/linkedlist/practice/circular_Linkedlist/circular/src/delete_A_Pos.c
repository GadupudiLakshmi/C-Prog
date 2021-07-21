#include "header.h"

node_t* delete_A_Pos (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int position;
		printf ("Enter position \n");
		scanf ("%d", &position);

		if (position > length (list)) {
			printf ("Invalid Position \n");
		} else if (position == 0) {
			list = delete_Fst (list);
		} else if (position == length (list) - 1) {
			list = delete_End (list);
		} else if (position == length (list)) {
			printf ("no after nodes \n");
		} else {
			node_t *temp = list->link;
			node_t *ptr = NULL;
			int i = 0;
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
