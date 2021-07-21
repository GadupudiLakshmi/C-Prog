#include "header.h"

node_t *checkColor (node_t *root, node_t *temp) {
	if (root->color != 0) {
		printf ("No voilation \n");
	} else {
		char select;
		node_t *parent = search (temp, root->data);
		if (parent == NULL) {
			root->color = -1;
		} else {
		node_t *grandparent = search (temp, parent->data);
		if (parent->color == 0) {
			if (grandparent->left == parent) {
				if (grandparent->right != NULL) {
					if (grandparent->right->color == 0) {
						parent->color = -1;
						grandparent->right->color = -1;
						grandparent->color = 0;
						node_t *ptr = checkColor (grandparent, temp);
					} else {
						if (parent->left->data == root->data) {
							select = 'L';
						} else {
							select = 'R';
						}
						if (select == 'R') {
							parent = leftRotate (parent);
							checkColor (parent, temp);
						} else if (select == 'L') {
							parent->color = -1;
							grandparent->color = 0;
							grandparent = rightRotate (grandparent);
						}
					}			
				} else {
					if (parent->left->data == root->data) {
						select = 'L';
					} else {
						select = 'R';
					}
					if (select == 'R') {
						parent = leftRotate (parent);
						checkColor (parent, temp);
					} else if (select == 'L') {
						parent->color = -1;
						grandparent->color = 0;
						grandparent = rightRotate (grandparent);
					}
				}			
			} else {
				if (grandparent->left != NULL) {
					if (grandparent->left->color == 0) {
						parent->color = -1;
						grandparent->left->color = -1;
						grandparent->color = 0;
						checkColor (grandparent, temp);
					} else {
						if (parent->left->data == root->data) {
							select = 'L';
						} else {
							select = 'R';
						}
						if (select == 'R') {
							parent = leftRotate (parent);
							checkColor (parent, temp);
						} else {
							parent->color = -1;
							grandparent->color = 0;
							grandparent = rightRotate (grandparent);
						}
					}
				} else {
					if (parent->left->data == root->data) {
						select = 'L';
					} else {
						select = 'R';
					}
					if (select == 'R') {
						parent = leftRotate (parent);
						checkColor (parent, temp);
					} else {
						parent->color = -1;
						grandparent->color = 0;
						grandparent = rightRotate (grandparent);
					}
				}
			}
		} else {
			printf ("No violation \n");
		}
	}
	}
	return temp;
}
#if 0				
			
		printf ("be%d \n", ptr->data);
		node_t *ptr1 = ptr;
		node_t *ptr2 = root;
		if (ptr->color != 0) {
			printf ("no violation \n");
		} else {
			printf ("%d \n", ptr->data);
			root->data = ptr->data;
			ptr = search (temp, ptr->data);
			if (ptr != NULL) {
			printf ("%d \n", ptr->data);
			if (ptr->left->data == root->data) {
				if (ptr->right != NULL) {
					if (ptr->right->color == 0) {
						ptr->left->color = -1;
						ptr->right->color = -1;
						ptr->color = 0;
						if (ptr != temp) {
							ptr = checkColor (ptr,temp);
						} else {
							ptr->color = 1;
						}
					} else if (ptr->right->color == -1) {
						char select;
						if (ptr1->left->data == ptr2->data) {
							select = 'L';
						} else {
							select = 'R';
						}
						if (select == 'L') {
							ptr->left->color = -1;
							ptr->color = 0;
							ptr = rightRotate (ptr);
						} else if (select == 'R') {
							ptr = leftRotate (ptr->left);
							ptr = checkColor (ptr, temp);
						}
					}
				}
			}
		}
	}
	}
	return temp;
}
#endif
