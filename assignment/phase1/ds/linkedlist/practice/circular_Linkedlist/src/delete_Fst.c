#include "header.h"

node_t* delete_Fst (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		node_t *temp = list;
		list = list->link;
		temp->link = NULL;
		free (temp);
	}
	return list;
}
