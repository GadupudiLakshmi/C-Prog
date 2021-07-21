#include "header.h"

int height (node_t *root) {
	if (root == NULL) {
		return 0;
	} else {
		int left = height (root->left);
		int right = height (root->right);
		if (left > right) {
			return left + 1;
		} else {
			return right + 1;
		}
	}
}
