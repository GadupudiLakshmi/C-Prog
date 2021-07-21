#include "header.h"

node_t *insertRBT (node_t *root, int num, node_t *temp) {
	if (root == NULL) {
		root = createnode (root);
		root->data = num;
		root->color = ~(0);
		printf ("%d \n", root->color);
		node_t *temp = root;
	} else {
		if (num < root->data) {
			if (root->left == NULL) {
				node_t *ptr = createnode (ptr);
				ptr->data = num;
				root->left = ptr;
				printf ("%d \n", ptr->data);
				root = checkColor (ptr, temp);
				if (root->color) {
					printf ("Black \n");
				}	
			} else {
				root->left = insertRBT (root->left, num, temp);
			}
		} else {
			if (root->right == NULL) {
				node_t *ptr = createnode (ptr);
				ptr->data = num;
				root->right = ptr;
				root = checkColor (ptr, temp);
				printf ("Right node inserted \n");
			} else {
				root->right = insertRBT (root->right, num, temp);
			}
		}
	}
	return root;
}
					
