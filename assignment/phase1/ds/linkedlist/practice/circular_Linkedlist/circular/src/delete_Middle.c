#include "header.h"

node_t* delete_Middle (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int position = length (list) / 2;
		if (length (list) > 2) {
			if (position < 1) {
				printf ("Mid not found \n");
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
		} else {
			printf ("mid not found \n");
		}
	}
	return list;
}
