#include "header.h"

node_t* insert_B_Num (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int num;
		printf ("Enter number \n");
		scanf ("%d", &num);
		int position = find (num, list);
		if (position == -1) {
			printf ("number not found \n");
		} else if (position == 1) {
			list = insert_Fst (list);
		} else {
			node_t *temp = list;
			node_t *ptr = NULL;
			int i = 1;
			while (i < position - 1) {
				temp = temp->link;
				i++;
			}
			ptr = createnode (ptr);
			ptr->link = temp->link;
			temp->link = ptr;
		}
	}
	return list;
}
