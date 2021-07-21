#include "header.h"

node_t* concate (node_t *list, node_t1 *list1) {
	if (list == NULL) {
		list = (node_t *) list1;
	} else {
		node_t *ptr = list;
		while (ptr->link != NULL) {
			ptr = ptr->link;
		}
		ptr->link = (node_t*) list1;
	}
	return list;
}
