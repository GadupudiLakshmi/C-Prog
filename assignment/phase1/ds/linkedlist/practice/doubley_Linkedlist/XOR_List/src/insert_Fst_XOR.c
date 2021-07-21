#include "header.h"
#include <inttypes.h>

node_t *insert_Fst (node_t *head) {
	if (head == NULL) {
		node_t *ptr = head;
		node_t *temp = createnode (temp);
		temp->npx = ptr;
		head = temp;
	} else {
		node_t *temp = createnode (temp);
		head->npx = (node_t *) ((uintptr_t) (head->npx) ^ (uintptr_t) (temp));
		temp->npx = (node_t *) ((uintptr_t) (NULL) ^ (uintptr_t) (head));
		head = temp;
	}
	return head;
}
		
