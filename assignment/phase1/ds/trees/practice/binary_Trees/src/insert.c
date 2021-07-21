#include "header.h"

node_t * insert (node_t *root) {
	if (root->data == -1) {
		printf ("Insert root node \n");
		int value;
		printf ("Enter data \n");
		scanf("%d", &value);
		root->data = value;
		printf ("data inserted %d \n", value);
	} else {
		char select;
		printf ("Select insertion in left or right : L/R \n");
		__fpurge (stdin);
		scanf ("%c", &select);
		if (select == 'L') {
			if (root->left == NULL) {
				node_t *ptr;
				ptr = createnode (ptr);
				root->left = ptr;
				printf ("Left node inserted \n");
			} else {
				node_t *ptr = root;
				ptr = ptr->left;
				ptr = insert (ptr);
			}
		} else if (select == 'R') {
			if (root->right == NULL) {
				node_t *ptr;
				ptr = createnode (ptr);
				root->right = ptr;
				printf ("Right node inserted \n");
			} else {
				node_t *ptr = root;
				ptr = ptr->right;
				ptr = insert (ptr);
			}
		}
	}
		return root;
}

		
