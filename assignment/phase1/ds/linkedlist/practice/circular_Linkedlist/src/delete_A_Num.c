#include "header.h"

node_t *delete_A_Num (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int num;
		printf ("Enter number \n");
		scanf ("%d", &num);
		int position = find (num, list);
		if (position == -1) {
			printf ("Number not found \n");
		} else if (position == length (list)-1) {
			list = delete_Last (list);
		} else if (position == length (list)) {	
			printf ("No after node \n");
		} else {
			node_t *temp = list;
			node_t *ptr = NULL;
			int i = 0;
			while (i < position - 1) {
				temp = temp->link;
				i++;
			}
			ptr = temp->link;
			temp->link = ptr->link;
			ptr->link = NULL;
			free (ptr);
		}
	}
	return list;
}
