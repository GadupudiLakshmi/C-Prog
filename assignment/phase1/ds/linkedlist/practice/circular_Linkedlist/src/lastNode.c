#include "header.h"

int lastnode (node_t *list, int n) {
	node_t *ptr = list;
	int count = 0;
	while (ptr->link != NULL) {
		count++;
		if (count == n) {
			return ptr->data;
		}
		ptr = ptr->link;
	}
	count++;
	if (count == n) {
		return ptr->data;
	}
}
