#include "header.h"

node_t *deleteLeaf (node_t *root) {
	if (root->left == NULL && root->right == NULL) {
		free (root);
	} else if (root->left == NULL) {
		if (root->right != NULL) {
			node_t *ptr = root;
			while (ptr->left != NULL) {
				node_t *prev = ptr;
				ptr = ptr->left;
			}
			if (ptr->left == NULL && ptr->right == NULL) {
				prev = NULL;
			}
		}
	} if (root->left != NULL) {
		node_t *ptr = root;
		while (ptr->left != NULL) {
			node_t *prev = ptr;
			ptr = ptr->left;
		}
		if (ptr->left == NULL && ptr->right == NULL) {
			prev = NULL;
		} else if (ptr->left == NULL) {
			if (ptr->right != NULL) {
				ptr = ptr->right;
				while (ptr->left != NULL) {
					prev = ptr;
					ptr = ptr->left;	
				}
				if (ptr->left == NULL && ptr->right == NULL) {
					prev = NULL;
				}
				
				
