#include "header.h"

int minValue (node_t *root) {
	if (root->left == NULL && root->right == NULL) {
		printf ("Min value is %d \n", root->data);
		return root->data;
	} else {
		minValue (root->left);
	}
}
