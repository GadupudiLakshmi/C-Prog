#include "header.h"

D_node_t* delete_B_Num (D_node_t *header) {
	int num;
	printf ("Enter Number \n");
	scanf ("%d", &num);
	int position = find (num, header);
	if (position == -1) {
		printf ("No number found \n");
	} else if (position == 1) {
		printf ("No befor nodes \n");
	} else if (position == 2) {
		header = delete_Fst (header);
	} else {
		D_node_t *temp = header->next;
		D_node_t *ptr1 = NULL;
		int i = 2;
		while (i < position - 1) {
			temp = temp->next;
			i++;
		}
		ptr1 = temp->next;
		ptr1->prev->next = ptr1->next;
		ptr1->next->prev = ptr1->prev;
		ptr1->next = NULL;
		ptr1->prev = NULL;
		free (ptr1);
	}
	return header;
} 
