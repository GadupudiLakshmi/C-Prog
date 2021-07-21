#include "header.h"

node_t* insert_Fst (node_t * list) {
	node_t *ptr;
	if (list == NULL) {
		ptr = createnode (ptr);
		list = ptr;
	} else {
		node_t *ptr1 = list;
		ptr1 = createnode (ptr1);
		ptr1->link = list;
		list = ptr1;
	}
	return list;
}
