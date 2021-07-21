#include "header.h"

node_t* insert_Penultimate (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int position = length (list) - 1;
		if (position == 0) {
			list = insert_Fst (list);
		} else {
			node_t *temp = list;
			node_t *ptr = NULL;
			int i = 0;
			while (i < position - 1) {
				temp = temp->link;
				i++;
			}
			ptr = createnode (ptr);
			ptr->link = temp->link;
			temp->link = ptr;
		}
	}
	return list;
}
