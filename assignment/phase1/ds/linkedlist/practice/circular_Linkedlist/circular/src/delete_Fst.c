#include "header.h"

node_t* delete_Fst (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	}
	node_t *temp = list->link;
	if (temp == list) {
		list->link = NULL;
		list = NULL;
		free (temp);
	} else {
		node_t *ptr = list->link;
		list->link = ptr->link;
		ptr->link = NULL;
		free (ptr);
	}
	return list;
}
