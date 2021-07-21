#include "header.h"

node_t* delete_Penultimate (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int position = length (list) - 1;
		if (position == 0) {
			printf ("No penultimate node \n");
		} else {
			node_t *temp = list;
			node_t *ptr = NULL;
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
	}
	return list;
}
