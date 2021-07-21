#include "header.h"

void verify (node_t *list) {
	node_t *ptr = list;
	while (ptr->link != NULL) {// || ptr->link != list) {
		if (ptr->link == list) {
			printf ("Circular\n");
			break;
		}
		ptr = ptr->link;
	}
	if (ptr->link == NULL) {
		printf ("Single list \n");
	}
}
		
