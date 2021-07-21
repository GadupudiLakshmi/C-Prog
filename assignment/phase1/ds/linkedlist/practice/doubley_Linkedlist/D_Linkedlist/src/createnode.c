#include "header.h"

D_node_t* createnode (D_node_t *header) {
	D_node_t *temp;
	temp = (D_node_t *) malloc (sizeof (D_node_t));
	printf ("Enter value \n");
	scanf ("%d", &(temp->data));
	
	return temp;
}
