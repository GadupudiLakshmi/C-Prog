#include "header.h"
#include <inttypes.h>

node_t *delete_Fst (node_t *head) {
	if (head == NULL) {
		printf ("list is empty \n");
	} else {
		node_t *ptr = head;
		if (ptr -> npx == NULL) {
			ptr = NULL;
			free (ptr);
			head = NULL;
		} else {
			node_t *prev = NULL;
			node_t *cur = head;
			node_t *next = (node_t*) ((uintptr_t) (prev) ^ (uintptr_t) (cur->npx));
			
			prev = cur;
			cur = next;
			next = (node_t*) ((uintptr_t) (prev) ^ (uintptr_t) (cur->npx));
			cur->npx = (node_t*) ((uintptr_t) (NULL) ^ (uintptr_t) (next));
			prev->npx = NULL;
			prev = NULL;
			free (prev);
			head = cur;
		}
	}
	return head;
}
			
			
