#include "header.h"

node_t* delete_End (node_t *list) {
	if (list == NULL) {
		printf ("list is empty \n");
	} else {  
		node_t *temp = list->link;
		if (temp == list) {
			list->link = NULL;
			list = NULL;
			free (temp);
		} else {
			node_t *ptr = list->link;
			node_t *temp = NULL;
			while (ptr != list) {
				temp = ptr;
				ptr = ptr->link;
			}
			temp->link = list->link;
			list = temp;
		}
	}
		return list;
}

