#include "header.h"

node_t* insert_B_Num (node_t *list) {
		int num;
		printf ("Enter num \n");
		scanf ("%d", &num);
		int position = find (num, list);
		if (position == -1) {
			printf ("no number found \n");
		}else if (position == 0 ) {
			printf ("no before nodes \n");
		} else if (position == 1) {
			list = insert_Fst (list);
		} else {
			node_t *temp = list->link;
			node_t *ptr1 = NULL;
			int i = 1;
			while (i < position - 1) {
				temp = temp->link;
				i++;
			}
			ptr1 = createnode (ptr1);
			ptr1->link = temp->link;
			temp->link = ptr1;
		}
	return list;
}
	
			
