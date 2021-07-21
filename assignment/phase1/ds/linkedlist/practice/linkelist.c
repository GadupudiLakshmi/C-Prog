#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct _node_t {
	char *name;
	struct _node_t *link;
}node_t;

int addnode ( );
int main ()
{
	node_t *list = NULL;
	node_t *ptr1 = NULL;
	node_t *ptr2 = NULL;
	ptr1 = (node_t *) malloc (sizeof (node_t));

	list = ptr1;
	ptr1->name = (char *) malloc (strlen ("lakshmi") + 1);
	strcpy (ptr1->name, "lakshmi");
	ptr1->link = NULL;	
	printf ("ptr1->name = %s \n", ptr1->name);
	printf ("ptr1-> link = %p \n", ptr1->link);
	addnode (ptr2, ptr1);
	printf ("node 2 sucess \n");
	addnode (ptr2, ptr1);
	printf ("node 3 sucess \n");
	printf ("%s \n", list);
}

int addnode (node_t *ptr2, node_t *ptr1) {
	ptr2 = (node_t *) malloc (sizeof (node_t));
	if (ptr1->link == NULL) {
		ptr1->link = ptr2;
		ptr2->name = (char *) malloc (strlen ("lll") + 1);
		strcpy (ptr2->name, "lll");
		ptr2->link = NULL;
		printf ("ptr2->name = %s \n", ptr2->name);
		printf ("ptr2->name = %p \n", ptr2->link);
		}
		ptr1 = ptr1->link;
		ptr2 = ptr1;
		printf ("ptr1 = %p \n", ptr1);
}

		

	
