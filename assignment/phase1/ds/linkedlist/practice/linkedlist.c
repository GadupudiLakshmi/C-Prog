#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdio_ext.h>

typedef struct _node_t {
	char *name;
	struct _node_t *link;
}node_t;

node_t* adddata (node_t *);
void print (node_t *);
int main ()
{
	node_t *list = NULL;
	node_t *ptr;
	int choice = 1;

	do {
		print (list);
		if (list == NULL) {
			ptr = (node_t *) adddata (ptr);	 // adding data into 1st node
			list = ptr;  // adding ptr to list
		} else {
			node_t *ptr2 = list;
			while (ptr2->link != NULL) {	// traversing till last node
				ptr2 = ptr2->link;
			}
		
			ptr = (node_t *) adddata (ptr); // adding newnode at last node
			ptr2->link = ptr;
		}
		printf ("do you want to add another node 0/1 \n");
		scanf ("%d", &choice);
	} while (choice);
	print (list);
	
	free (ptr);
	return 0;
}

node_t* adddata (node_t *ptr) {
	ptr = (node_t *) malloc (sizeof (node_t));
	ptr->name = (char *) malloc (10 * sizeof (char));
	__fpurge (stdin);
	printf ("Enter Name \n");
	fgets (ptr->name, 100, stdin);
	return ptr;
}

void print (node_t *list) {
	if (list == NULL) {
		printf ("empty \n");
	} else {
		printf ("items in the list: \n");
		while (list !=NULL) {
			printf ("%s \n", list->name);
			list = list->link;
		}
	}
}
