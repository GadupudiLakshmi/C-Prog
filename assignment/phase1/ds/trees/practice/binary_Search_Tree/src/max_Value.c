#include "header.h"

int maxValue (node_t *root) {
	printf ("WE \n");
	if (root->left == NULL && root->right == NULL) {
		printf ("Max value is %d \n", root->data);
		return root->data;
	} else {
		maxValue (root->right);
	}
}
