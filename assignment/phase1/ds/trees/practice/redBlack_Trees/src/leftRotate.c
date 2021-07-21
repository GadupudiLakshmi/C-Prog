#include "header.h"

node_t *leftRotate (node_t *root) {
	node_t *temp;
	node_t *ptr = root->right;
	temp = root->right->left;
	root->right->left = root;
	root->right = temp;
	root = ptr;
	return root;
}	
