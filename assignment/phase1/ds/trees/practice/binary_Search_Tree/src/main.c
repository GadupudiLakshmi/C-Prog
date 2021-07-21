#include "header.h"

int main ()
{
	node_t *root = NULL;
	int option;
	
	while (1) {
		printf ("Select option \n");
		scanf ("%d", &option);
		switch (option) {
		case 1: 
			printf ("Insert into tree \n");
			int num;
			printf ("Enter value to insert \n");
			scanf ("%d", &num);
			root = insertBST (root,num);
			break;
		case 2:
			printf ("Delete node \n");
			printf ("Enter value to delete \n");
			scanf ("%d", &num);
			root = deleteBST (root,num);
			break;
		case 3:
			printf ("Searching node \n");
			int key;
			printf ("Enter value to search \n");
			scanf ("%d", &key);
			search (root, key);
			break;
		case 4:
			printf ("Preorder Traverse \n");
			preOrder (root);
			break;
		case 5:
			printf ("Inorder Traverse \n");
			inOrder (root);
			break;
		case 6:
			printf ("Postorder Traverse \n");
			postOrder (root);
			break;
		case 7:
			printf ("Maximum value in tree \n");
			maxValue (root);
			break;
		case 8:
			printf ("Minimum value in tree \n");
			minValue (root);
			break;
		case 9:
			printf ("Height of tree \n");
			num = height (root);
			printf ("%d \n", num);
			break;
		case 10:
//			printf ("Level Traverse \n");
//			levelTraverse (root);
			break;
		case 11:
			exit (0);
			break;
		default:
			printf ("Invalid option \n");
		}
	}

	return 0;
}
