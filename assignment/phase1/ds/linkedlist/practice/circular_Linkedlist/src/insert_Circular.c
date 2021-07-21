#include "header.h"

node_t2* insert_End2 (node_t2 *list) {
	node_t2 *ptr;
	if (list == NULL) {
		ptr = createnode2 (ptr);
		ptr->link = ptr;
		list = ptr;
	} else {
		node_t2 *temp;
		node_t2 *ptr1 = list->link;
		temp = createnode2 (temp);
		list->link = temp;
		list = temp;
		temp->link = ptr1;
		
	}
	return list;
}
