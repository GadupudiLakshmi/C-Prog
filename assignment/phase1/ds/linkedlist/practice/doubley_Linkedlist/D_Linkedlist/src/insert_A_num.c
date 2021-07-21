#include "header.h"

D_node_t* insert_A_Num (D_node_t *header) {
	int num;
	printf ("Enter number \n");
	scanf ("%d", &num);
	int position = find (num, header);
	if (position == -1) {
		printf ("number not found \n");
	}else if (position == 0) {
		header = insert_Fst (header);
	} else if (position > length (header)) {
		printf ("Number not found \n");
	} else if (position == length (header)) {
		header = insert_End (header);
	} else {
		D_node_t *temp = header->next;
		D_node_t *ptr1 = NULL;
		int i = 0;
		while (i < position - 1) {
			temp = temp->next;
			i++;
		}
		ptr1 = createnode (ptr1);
		ptr1->prev = temp;
		ptr1->next = temp->next;
		temp->next = ptr1;
		ptr1->next->prev = ptr1;
	}
	return header;
}
	
