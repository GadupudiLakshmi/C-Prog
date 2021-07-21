#include "header.h"

void postOrder (node_t *root) {
	if (root) {
		postOrder (root->left);
		postOrder (root->right);
		printf ("%d \n", root->data);
	}
}
		
