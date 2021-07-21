#include "header.h"

node_t1* createnode1 (node_t1 *ptr) {
	node_t1 *temp;
	temp = (node_t1 *) malloc (sizeof (node_t1));
	printf ("Enter value \n");
	scanf ("%d" ,&(temp->data));
	ptr = temp;
	return temp;
}
