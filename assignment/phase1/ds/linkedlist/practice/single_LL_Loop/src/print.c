#include "header.h"

void print (node_t *list) {
	node_t *ptr = list;
	if (ptr == NULL) {
		printf ("Empty \n");
	} else {
		node_t *temp = ptr;
		
		while (temp != NULL) {
			printf ("%d \n", temp->data);
			temp = temp->link;
		}
	}
}
