#include "header.h"

node_t* delete_Last (node_t *list) {
	if (list == NULL) {
		printf ("list is empty \n");
	} else {
		node_t *ptr = list;
		node_t *temp;
		int count = 0;
		while (ptr->link != NULL) {
			count++;
			temp = ptr;
			ptr = ptr->link;
		}
		temp->link = NULL;
		if (count == 0) {
			temp = list;
			list = list->link;
		}
		free (ptr);
	}
	return list;
}
