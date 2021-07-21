#include "header.h"

node_t* insert_Fst (node_t *list) {
	node_t *ptr = NULL;
	if (list == NULL) {
		ptr = createnode (ptr);
		ptr->link = ptr;
		list = ptr;
	} else {
		node_t *ptr1;
		node_t *temp = ptr;
		ptr1 = createnode (ptr1);
		ptr1->link = list->link;
		list->link = ptr1;
	}
	return list;
}
