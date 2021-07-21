#include "header.h"

node_t *createnode (node_t *head) {
	head = (node_t*) malloc (sizeof (node_t));
	printf ("Enter data \n");
	scanf ("%d", &head->data);
	return head;
}
