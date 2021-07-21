#include "header.h"

node_t* insert_Pos (node_t *list) {
	node_t *ptr = NULL;
	if (list == NULL) {
		ptr = createnode (ptr);
		ptr->link = ptr;
		list = ptr;
	} else {
		int position;
		printf ("enter position \n");
		scanf ("%d", &position);
		if (position > length (list)) {
			printf ("invalid position \n");
		} else if (position == 1) {
			list = insert_Fst (list);
		} else {
			node_t *temp = list->link;
			node_t *ptr1 = NULL;
			int i = 1;
			while (i < position - 1) {
				temp = temp->link;
				i++;
			}
			
			ptr1 = createnode (ptr1);
			ptr1->link = temp->link;
			temp->link = ptr1;
		}
	}

	return list;
}
