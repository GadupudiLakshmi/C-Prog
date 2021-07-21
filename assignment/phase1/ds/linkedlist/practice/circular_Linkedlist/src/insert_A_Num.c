#include "header.h"

node_t* insert_A_Num (node_t *list) {
	int num;
	printf ("Enter number \n");
	scanf ("%d", &num);
	int position = find (num, list);
	if (position == -1) {
		printf ("Number not found \n");
	} else if (position == length (list)) {
		list = insert_End (list);
	} else {
		node_t *temp = list;
		node_t *ptr = NULL;
		int i = 0;
		while (i < position - 1) {
			temp = temp->link;
			i++;
		}
		ptr = createnode (ptr);
		ptr->link = temp->link;
		temp->link = ptr;
	}
	return list;
}
