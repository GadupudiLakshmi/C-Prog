#include "header.h"

void inOrder (node_t *root) {
	if (root) {
		inOrder (root->left);
		printf ("%d \n", root->data);
		inOrder (root->right);
	}
}
