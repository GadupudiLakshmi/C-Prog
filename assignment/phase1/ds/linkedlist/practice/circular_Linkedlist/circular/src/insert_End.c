#include "header.h"

node_t* insert_End (node_t *list) {
	node_t *ptr;
	if (list == NULL) {
		ptr = createnode (ptr);
		ptr->link = ptr;
		list = ptr;
	} else {
		node_t *temp;
		node_t *ptr1 = list->link;
		temp = createnode (temp);
		list->link = temp;
		list = temp;
		temp->link = ptr1;
		
	}
	return list;
}

