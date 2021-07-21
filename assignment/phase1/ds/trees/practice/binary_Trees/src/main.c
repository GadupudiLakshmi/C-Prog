#include "header.h"

int main ()
{
	node_t *root = NULL;
	root = (node_t *) malloc (sizeof (node_t));
	root->left = NULL;
	root->right = NULL;
	root->data = -1;
	int option;
	
	while (1) {
		printf ("Select option \n");
		scanf ("%d", &option);
		switch (option) {
		case 1: 
			printf ("Insert into tree \n");
			root = insert (root);
			break;
		case 2:
			printf ("Delete leaf node \n");
			root = deleteLeaf (root);
			break;
		case 3:
			printf ("Preorder Traverse \n");
			preOrder (root);
			break;
		case 4:
			printf ("Inorder Traverse \n");
			inOrder (root);
			break;
		case 5:
			printf ("Postorder Traverse \n");
			postOrder (root);
			break;
		case 6:
			exit (0);
			break;
		case 7:
			printf ("Invalid option \n");
		}
	}

	return 0;
}
