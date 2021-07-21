#include "header.h"

node_t* delete_B_Num (node_t *list) {
	int num;
	printf ("Enter Number \n");
	scanf ("%d", &num);
	int position = find (num, list);
	if (position == -1) {
		printf ("No number found \n");
	} else if (position == 1) {
		printf ("No befor nodes \n");
	} else if (position == 2) {
		list = delete_Fst (list);
	} else {
		node_t *temp = list->link;
		node_t *ptr1 = NULL;
		int i = 2;
		while (i < position - 1) {
			temp = temp->link;
			i++;
		}
		ptr1 = temp->link;
		temp->link = ptr1->link;
		ptr1->link = NULL;
		free (ptr1);
	}
	return list;
} 
