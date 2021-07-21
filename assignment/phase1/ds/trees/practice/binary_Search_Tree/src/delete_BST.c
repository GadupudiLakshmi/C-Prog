#include "header.h"

node_t *deleteBST (node_t *root, int num) {
	if (root == NULL) {
		return root;
	} else {
		if (num == root->data) {
			if (root->left == NULL && root->right == NULL) {
				root = NULL;
				free (root);
			} else if (root->left != NULL && root ->right == NULL) {
				node_t *ptr = root->left;
				free (root);
				return ptr;
			} else if (root->left == NULL && root->right != NULL) {
				node_t *ptr = root->right;
				free (root);
				return ptr;
			} else if (root->left != NULL && root->right != NULL) {
				int max_value = maxValue (root->right);
				root->data = max_value;
				root->right = deleteBST (root->right, max_value);
			}
		} else if (num < root->data) {
			root->left = deleteBST (root->left, num);
		} else {
			root->right = deleteBST (root->right, num);
		}
	}
	return root;
}	
				
				
			
