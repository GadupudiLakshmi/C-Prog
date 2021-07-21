#include "header.h"

node_t* insert_Penultimate (node_t *list) {
	node_t *ptr = NULL;
	if (list == NULL) {
		printf ("No nodes \n");
	} else {
		int position = length (list) - 1;
		if (position == 0) {
			list = insert_Fst (list);
		} else {
			node_t *temp = list->link;
			node_t *ptr1 = NULL;
			int i = 0;
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
