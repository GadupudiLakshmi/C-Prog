#include "header.h"

node_t * createnode (node_t *ptr) {
	node_t *temp = NULL;
	temp = (node_t *) malloc (sizeof (node_t));
	int value;
	printf ("Enter data \n");
	scanf ("%d", &value);
	temp->data = value;
	temp->left = NULL;
	temp->right = NULL;
	ptr = temp;
	return ptr;
}
	
	
	
