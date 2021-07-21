#include "header.h"

node_t *search (node_t *root, int num) {
	node_t *prev = NULL;
	if (root->data == num) {
		printf ("%d found \n", root->data);
		return prev;
	} else {
		if (num < root->data) {
			if (root->left == NULL) {	
				printf ("%d not found \n", num);
			} else {
				if (root->left->data == num) {
					prev = root;
					printf ("%d found \n", num);
					printf ("%d \n", prev->data);
					return prev;
				}
				search (root->left, num);
			}
		} else if (num > root->data) {
			if (root->right == NULL) {
				printf("%d not found \n", num);
			} else {
				if (root->right->data == num) {
					prev = root;
					printf ("%d \n", prev->data);
					return prev;
				}
				search (root->right, num);
			}
		 }
	}
}
