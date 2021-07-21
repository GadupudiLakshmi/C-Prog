#include "header.h"

node_t * createnode (node_t *ptr) {
	node_t *temp = NULL;
	temp = (node_t *) malloc (sizeof (node_t));
	temp->left = NULL;
	temp->right = NULL;
	return temp;
}
	
	
	
