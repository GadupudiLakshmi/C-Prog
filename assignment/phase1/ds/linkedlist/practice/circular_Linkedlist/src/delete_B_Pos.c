#include "header.h"

node_t* delete_B_Pos (node_t *list) {
	if (list == NULL) {
		printf ("list is empty \n");
	} else {
		int position;
		printf ("Enter position \n");
		scanf ("%d", &position);
		if (position > length (list)) {
			printf ("Invalid Position \n");
		} else if (position == 1) {
			printf ("No before Position \n");
		} else if (position == 2) {
			list = delete_Fst (list);
		} else {
			int i = 2;
			node_t *ptr1 = list;
			node_t *ptr2;
			while (i < position - 1) {
				ptr1 = ptr1->link;
				i++;
			}
			ptr2 = ptr1->link;
			ptr1->link = ptr2->link;
			ptr2->link = NULL;
			free (ptr2);
		}
	}
	return list;
}
