#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct _node_t {
	int value;
	struct _node_t *link;
}node_t;

node_t* addnode (node_t *);
node_t* insert_First (node_t *);
node_t* insert_Pos (node_t *);
node_t* delete_Fst (node_t *);
node_t* delete_Last (node_t*);
void print (node_t *);
int main ()
{
	node_t *list = NULL;
	node_t *ptr;
	int option;
	int choice = 1;
	
	do {
		printf ("Enter your option \n");
		scanf ("%d", &option);

		switch (option) {
		case 1:
			printf ("creating node and insert at end\n");
			if (list == NULL) {
				ptr = (node_t *) addnode (ptr);
				list = ptr;
			} else {
				node_t *ptr1 = list;
				while (ptr1->link != NULL) {
					ptr1 = ptr1->link;
				}
				ptr = (node_t *) addnode (ptr);
				ptr1->link = ptr;
			}
			break;
		case 2:
			printf ("Printing list Items \n");
			print (list);	
			break;
		case 3:
			printf ("creating and Inserting node at begining \n");
			if (list == NULL) {
				ptr = (node_t *) insert_First (ptr);
				list = ptr;
			} else {
				node_t *ptr1 = list;
				ptr1 = (node_t *) insert_First (ptr1);
				ptr1->link = list;
				list = ptr1;
			}
			break;
		case 4:
			printf ("creating and Inserting node at given position \n");
			if (list == NULL) {
				ptr = (node_t *) insert_Pos (ptr);
				list = ptr;
			} else {
				int position;	
				printf ("Enter Position to Insert node \n");
				scanf ("%d", &position);
				node_t *ptr1 = list;
				if (position == 1) {
					ptr1 = insert_First (ptr1);
					ptr1->link = list;
					list = ptr1;
				} else {	
					int count = 1;
					node_t *ptr2 = list;
					while (ptr2->link != NULL) {
						node_t *temp = ptr2;
						count++;
						if (count == position) {
							insert_Pos (temp);
						}
						ptr2 = ptr2->link;
				}
				if (ptr2->link == NULL) {
					count++;
					node_t *temp = ptr2;
					if (count == position) {
						insert_Pos (temp);
					} else {
						printf ("position not found \n");
					}
				}
				}
			}
			break;
		case 5:
			printf ("Deleting 1st Node \n");
			if (list == NULL) {
				printf ("list is empty \n");
			} else {
				list = delete_Fst (list);
			}
			break;
		case 6:
			printf ("Deleting last Node \n");
			if (list == NULL) {
				printf ("list is empty \n");
			} else {
				int count = 0;
				node_t *ptr1 = list;
			//	ptr1 = delete_Last (ptr1);
				node_t *temp;
				while (ptr1->link != NULL) {
						count++;
					 	temp = ptr1;
						ptr1 = ptr1->link;
				}
				temp->link = NULL;
				if (count == 0) {
					temp = list;
					list = list->link;
				}
			}
			break;
		
		case 7:
			printf ("Deleting Node at given Position \n");
			int position;
			printf ("Enter position \n");
			scanf ("%d", &position);
			int count = 0;
			if (list == NULL) {
				printf ("List is empty \n");
			} else {
				if (position == 1) {
					list = list->link;
				} else {
					node_t *ptr1 = list;
					node_t *temp;
					while (ptr1->link != NULL) {
						count++;
						if (count == position) {
							temp->link = ptr1->link;
						}
						temp = ptr1;
						ptr1 = ptr1->link;
					}
					count++;
					if (count == position) {
						temp->link = NULL;
					}
					if (count < position ) {
						printf ("Position not found \n");
					}
				}
			}
			break;
		default:
			printf ("invalid option \n");
		}
		printf ("do you want to continue 0/1 \n");
		scanf ("%d", &choice);
	} while (choice);
	
	free (ptr);
	return 0;
}

node_t* addnode (node_t *ptr) {
	ptr = (node_t *) malloc (sizeof (node_t));
	__fpurge (stdin);
	printf ("Enter value\n");
	scanf ("%d", &(ptr->value));
	return ptr;
}

node_t* insert_First (node_t *ptr) {
	
	node_t *temp = (node_t *) malloc (sizeof (node_t));
	printf ("Enter value \n");
	scanf ("%d", &(temp->value));
//	temp->link = NULL;
//	temp->link = ptr->link;
	ptr = temp;
	return temp;
}

node_t* insert_Pos (node_t *ptr) {
	node_t *temp = (node_t *) malloc (sizeof (node_t));
	printf ("Enter value \n");
	scanf ("%d", &(temp->value));
//	temp->link = NULL;
	temp->link = ptr->link;
	ptr->link = temp;
	return temp;
}

node_t* delete_Fst (node_t *list) {
	node_t *temp = list;
	list = list->link;
	temp->link = NULL;
//	free (temp);
	return list;
}

node_t* delete_Last (node_t *ptr1) {
	int count = 0;
	node_t *temp;
	node_t *list = ptr1;
	while (ptr1->link != NULL) {
		count++;
		temp = ptr1;
		ptr1 = ptr1->link;
	}
	temp->link = NULL;
	if (count == 0) {
	temp = list;
	list = list->link;
	}
	free (temp);
	return ptr1;
}
void print (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		printf ("values in list : \n");
		while (list != NULL) {
			printf ("%d \n", list->value);
			list = list->link;
		}
	}
}
			
