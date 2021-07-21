#include "header.h"

node_t *reverse (node_t *list, node_t *temp) {
	printf ("REv \n");
	node_t *ptr = list;
	node_t *prev = NULL;
	node_t *next = NULL;
	while (ptr != NULL) {
		next = ptr->link;
		ptr->link = prev;
		prev = ptr;
		ptr = next;
	}
	list = prev;
	return list;
}
