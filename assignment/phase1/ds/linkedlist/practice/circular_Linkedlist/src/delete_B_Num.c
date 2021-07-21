#include"header.h"

node_t* delete_B_Num (node_t *list) {
	if (list == NULL) {
		printf ("List is empty \n");
	} else {
		int num;
		printf ("enter number \n");
		scanf ("%d", &num);
		int position = find (num, list);
		if (position == -1){
			printf ("Number not found \n");
		} else if (position == 1) {
			printf ("No before node \n");
		} else if (position == 2) {
			list = delete_Fst (list);
		} else {
			node_t *temp = list;
			node_t *ptr = NULL;
			int i = 2;
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
