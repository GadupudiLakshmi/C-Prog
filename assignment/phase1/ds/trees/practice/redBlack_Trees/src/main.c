#include "header.h"

int main ()
{
	node_t *root = NULL;
	node_t *temp = root;
	int option;
	
	while (1) {
		printf ("Enter option \n");
		scanf ("%d", &option);
		switch (option) {
		case 1:
			printf ("Insert into RedBlack Trees \n");
			int num;
			printf ("Enter number to insert \n");
			scanf ("%d", &num);
			temp = root;
			root = insertRBT (root, num, temp);
			break;
		case 2:
			printf ("Right rotate \n");
			root = rightRotate (root);
			break;
		case 3:
			printf ("Left Rotate \n");
			root = leftRotate (root);
			break;
		case 4:
			printf ("Inorder traverse \n");
			inOrder (root);
			break;
		case 5:
			printf ("Post order Traverse \n");
			postOrder (root);
			break;
		case 6:
			exit (0);
			break;
		default:
			printf ("Invalid option \n");
		}
	}

	return 0;
}
	
