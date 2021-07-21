#include "header.h"

int middle (node_t *list) {
	int size = length (list) / 2;
	node_t *temp = list;
	node_t *ptr = NULL;
	int i = 0;
	while (i < size - 1) {
		temp = temp->link;
		i++;
	}
	ptr = temp->link;
	return ptr->data;
}
