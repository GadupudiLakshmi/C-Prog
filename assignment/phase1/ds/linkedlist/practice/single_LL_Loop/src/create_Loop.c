#include "header.h"

node_t *createloop (node_t *list, int n) {
	node_t *ptr = list;
	node_t *temp = NULL;
	int count = 0;
	while (ptr->link != NULL) {
		count++;
		if (count == n) {
			temp = ptr;
		}
		ptr = ptr->link;
	}
	count++;
	if (count == n) {
		temp = ptr;
	}
	ptr->link = temp;
	
	return list;
}
	
