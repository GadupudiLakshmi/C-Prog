#include "header.h"

node_t* createnode (node_t *ptr) {
	node_t *temp;
	temp = (node_t *) malloc (sizeof (node_t));
	printf ("Enter value \n");
	scanf ("%d" ,&(temp->data));
	ptr = temp;
	return temp;
}
