#include "header.h"

void print (D_node_t *header) {
	if (header->prev == header && header->next == header) {
		printf ("list is empty \n");
	} else {
		printf ("the list items are \n");
		D_node_t *temp = header->next;
		while (temp->next != header) {
			printf ("%d \n", temp->data);
			temp = temp->next;
		}
		printf ("%d \n", temp->data);
		
	}
}
