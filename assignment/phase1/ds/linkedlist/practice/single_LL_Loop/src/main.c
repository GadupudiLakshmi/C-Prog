#include "header.h"

int main ()
{
	node_t *list = NULL;
	int choice;
	
	while (1) {
		printf ("Enter choice \n");
		scanf ("%d", &choice);
		switch (choice) {
		case 1:
			printf ("Insert End \n");
			list = insert_End (list);
			break;
		case 2:
			printf ("Create loop \n");
			printf ("enter position to create loop \n");
			int n;
			scanf ("%d", &n);
			list = createloop (list, n);
			break;
		case 3:
			printf ("check loop \n");
			checkloop (list);
			break;
		case 4:
			printf ("Print loop \n");
			print (list);
		default :
			printf ("invalid selecion \n");
		}
	}
	return 0;
}
