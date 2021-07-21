#include "header.h"

node_t *insertBST (node_t *root, int num) {
	if (root == NULL) {
		printf ("Insert root \n");
		root = createnode (root);
		root->data = num;
	} else {
		if (num < root->data) {
			if (root->left == NULL) {
				printf ("Insert left \n");
				node_t *ptr = createnode (root->left);
				ptr->data = num;
				root->left = ptr;
			} else {
				insertBST (root->left, num);
			}
		} else {
			if (root->right == NULL) {
				printf ("Right \n");
				node_t *ptr = createnode (root->right);
				ptr->data = num;
				root->right = ptr;
			} else {
				insertBST (root->right, num);
			}
		}
	}
	
	return root;
}	
