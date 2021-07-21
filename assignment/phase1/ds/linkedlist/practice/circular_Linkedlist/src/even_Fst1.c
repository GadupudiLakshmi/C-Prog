#include "header.h"

node_t* arrange (node_t *list) {
	node_t *ptr = list;
	node_t *prev = NULL;
	if (ptr->data % 2 == 0) {
		prev = ptr;
		ptr = ptr->link;
	}
	while (ptr->link != NULL) {
		printf ("fv\n");
		if (ptr->data % 2 == 0) {
			prev->link = ptr->link;
			ptr->link = list;
			list = ptr;
			ptr = prev;
		}
		prev = ptr;
		ptr = ptr->link;
	}
	if (ptr->data % 2 == 0) {
		prev->link = ptr->link;
		ptr->link = list;
		list = ptr;
		printf ("%d \n", prev->link);
	}
	return list;
}
