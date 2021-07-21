#include "header.h"

node_t *rightRotate (node_t *root) {
	node_t *temp;
	node_t *ptr = root->left;
	temp = root->left->right;
	root->left->right = root;
	root->left = temp;
	root = ptr;
	return root;
}
