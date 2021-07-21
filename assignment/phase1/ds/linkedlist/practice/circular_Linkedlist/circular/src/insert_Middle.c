#include "header.h"

node_t* insert_Middle (node_t *list) {
	if (list == NULL) {
		printf ("list is empty \n");
	} else {
		int position;
		position = length (list) / 2;
		if (position < 1) {
			printf ("Cannot find middle \n");
		} else {
			node_t *temp = list->link;
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
