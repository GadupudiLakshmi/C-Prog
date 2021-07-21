#include "header.h"

node_t2* createnode2 (node_t2 *ptr) {
	node_t2 *temp;
	temp = (node_t2 *) malloc (sizeof (node_t));
	printf ("Enter value \n");
	scanf ("%d" ,&(temp->data));
	ptr = temp;
	return temp;
}
