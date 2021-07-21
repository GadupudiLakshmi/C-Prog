#include "header.h"

node_t1* insert_End1 (node_t1 *list) {
	node_t1 *ptr;

	if (list == NULL) {
		ptr = createnode1 (ptr);
		list = ptr;
	} else {
		node_t1 *temp_list = list;
		while (temp_list->link != NULL) {
			temp_list = temp_list->link;
		}
		
		ptr = createnode1 (ptr);
		temp_list->link = ptr;
	}
	return list;
}
		
