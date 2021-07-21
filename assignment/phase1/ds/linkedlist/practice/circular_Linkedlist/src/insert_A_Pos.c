#include "header.h"

node_t* insert_A_Pos (node_t *list) {
	if (list == NULL) {
		node_t *ptr = createnode (ptr);
		list = ptr;
	} else {
		int position;
		printf ("Enter position \n");
		scanf ("%d", &position);
		if (position > length(list)) {
			printf ("invalid position \n");
		} else if (position == 0) {
			list = insert_Fst (list);
		} else {
			node_t *ptr1 = list;
			node_t *ptr2;
			int i = 0;
			while (i < position - 1) {
				ptr1 = ptr1->link;
				i++;
			}
			ptr2 = createnode (ptr2);
			ptr2->link = ptr1->link;
			ptr1->link = ptr2;
		}	
	} 
	return list;
}	
