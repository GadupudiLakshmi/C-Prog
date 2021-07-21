#include "header.h"

void levelTraverse (node_t *root) {
	int SIZE = pow (2, (height (root) - 1));
	struct QUEUE queue;
	queue->rear = -1;
	queue->front = -1;
	if (root == NULL) {
		printf ("No nodes to traverse \n");
	} else {
		insertqueue (&queue, root);
		node_t *ptr = deletequeue (&queue);
		printf ("%d \n", ptr->data);
		while (ptr->left != NULL || ptr->right != NULL) {
			if (ptr->left != NULL) {
				insertqueue (&queue, ptr->left);
			}
			if (ptr->right != NULL) {
				insertqueue (&queue, ptr->right);
			}
			ptr = deletequeue (&queue);
			printf ("%d \n", ptr->data);
		}
	}
}
		
		
