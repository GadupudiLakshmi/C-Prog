#include "header.h"

D_node_t* insert_B_Num (D_node_t *header) {
		int num;
		printf ("Enter num \n");
		scanf ("%d", &num);
		int position = find (num, header);
		if (position == -1) {
			printf ("no number found \n");
		}else if (position == 0 ) {
			printf ("no before nodes \n");
		} else if (position == 1) {
			header = insert_Fst (header);
		} else {
			D_node_t *temp = header->next;
			D_node_t *ptr1 = NULL;
			int i = 1;
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
	
			
