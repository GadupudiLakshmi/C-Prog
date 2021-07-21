#include "header.h"

int main ()
{
	node_t *head = NULL;
	
	int choice;
	while (1) {
		printf ("Enter choice \n");
		scanf ("%d", &choice);
		switch (choice) {
		case 1:
			printf ("Insert First \n");
			head = insert_Fst (head);
			break;
		case 2:
			printf ("Insert End \n");
			head = insert_End (head);
			break;
		case 3:
			printf ("Delete First \n");
			head = delete_Fst (head);
			break;
		case 4:
			printf ("Delete Last \n");
//			head = delete_End (head);
			break;
		case 5:
			printf ("Print list elements \n");
			print (head);
			break;
		case 6:
			exit (0);
			break;
		default:
			printf ("Invalid selection \n");
		}
	}
	return 0;
}

