#include "header.h"

node_t* checkloop (node_t *list) {
	node_t *ptr = list;
	node_t *sptr = list;
	node_t *fptr = list;
	node_t *root = ptr;
	while (sptr != NULL && fptr != NULL) {
		sptr = sptr->link;
		fptr = fptr->link->link;
		if (sptr == fptr) {
			printf ("loop \n");
			break;
		}
	}
/// removing loop
	if (sptr == fptr) {
		while (sptr != NULL && ptr != NULL) {
			if (sptr->link == ptr->link) {
				printf ("Fist node in loop is %d \n", sptr->link->data);
				sptr->link = NULL;
				return root;
			}
		
			sptr = sptr->link;
			ptr = ptr->link;
		}
	}
///
	
	if (sptr == NULL || fptr == NULL) {
		printf ("No loop \n");
	}
}
