#include "header.h"

node_t* delete_A_Pos (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int position;
		printf ("Enter position \n");
		scanf ("%d", &position);
		if (position > length(list)) {
			printf ("invalid position \n");
		} else if (position == 0) {
			list = delete_Fst (list);
		} else {
			node_t *ptr1 = list;
			node_t *ptr2;
			int i = 0;
			while (i < position - 1) {
				ptr1 = ptr1->link;
				i++;
			}
			ptr2 = ptr1->link;
			ptr1->link = ptr2->link;
			ptr2->link = NULL;
			free (ptr2);
		}	
	} 
	return list;
}	
