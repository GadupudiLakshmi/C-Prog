#include "header.h"

node_t* insert_End (node_t *list) {
	node_t *ptr;

	if (list == NULL) {
		ptr = createnode (ptr);
		list = ptr;
	} else {
		node_t *temp_list = list;
		while (temp_list->link != NULL) {
			temp_list = temp_list->link;
		}
		
		ptr = createnode (ptr);
		temp_list->link = ptr;
	}
	return list;
}
		
