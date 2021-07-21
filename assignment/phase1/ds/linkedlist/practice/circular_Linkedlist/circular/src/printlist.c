#include "header.h"

void print (node_t *list) {
	if (list == NULL) {
		printf ("list is empty \n");
	} else {
		printf ("the list items are \n");
		node_t *temp = list->link;
		while (temp != list) {
			printf ("%d \n", temp->data);
			temp = temp->link;
		}
		printf ("%d \n", temp->data);
	}
}
