#include "header.h"
#include <inttypes.h>

node_t *insert_End (node_t *head) {
	if (head == NULL) {
		node_t *ptr = head;
		node_t *temp = createnode (temp);
		temp->npx = ptr;
		head = ptr;
	} else {
		node_t *cur = head;
		node_t *prev = NULL;
		node_t *next = NULL;
		next = (node_t *) ((uintptr_t) (prev) ^ (uintptr_t) (cur->npx));
		while (next != NULL) {
			prev = cur;
			cur = next;
			next = (node_t*) ((uintptr_t) (prev) ^ (uintptr_t) (cur->npx));
		}
		node_t *temp = createnode (temp);
		temp->npx = (node_t*) ((uintptr_t) (cur) ^ (uintptr_t) (next));
		cur->npx = (node_t*) ((uintptr_t) (prev) ^ (uintptr_t) (temp));
	}
	return head;
}
