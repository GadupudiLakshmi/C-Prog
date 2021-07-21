#include "header.h"

void preOrder (node_t *root) {
	if (root) {
		printf ("%d \n", root->data);
		preOrder (root->left);
		preOrder (root->right);
	}
}
		
		
