#include "header.h"

node_t* insert_A_Num (node_t *list) {
	int num;
	printf ("Enter number \n");
	scanf ("%d", &num);
	int position = find (num, list);
	if (position == -1) {
		printf ("number not found \n");
	}else if (position == 0) {
		list = insert_Fst (list);
	} else if (position > length (list)) {
		printf ("Number not found \n");
	} else if (position == length (list)) {
		list = insert_End (list);
	} else {
		node_t *temp = list->link;
		node_t *ptr1 = NULL;
		int i = 0;
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
	
