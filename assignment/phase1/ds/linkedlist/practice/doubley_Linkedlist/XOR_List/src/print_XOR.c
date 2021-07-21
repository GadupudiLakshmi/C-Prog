#include "header.h"
#include <inttypes.h>

void print (node_t *head) {
	if (head == NULL) {
		printf ("list is empty \n");
	} else {
		node_t *cur = head;
		node_t *prev = NULL;
		node_t *next = NULL;
		next = (node_t*) ((long int) (prev) ^ (long int) (cur->npx));
		while (next != NULL) {
			printf ("%d \n", cur->data);
			prev = cur;
			cur = next;
			next =(node_t*) ((long int) (prev) ^ (long int) (cur->npx));
		}
		printf ("%d \n", cur->data);
	}
}

