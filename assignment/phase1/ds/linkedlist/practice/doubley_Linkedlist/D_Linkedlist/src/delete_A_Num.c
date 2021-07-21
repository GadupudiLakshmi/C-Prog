#include "header.h"

D_node_t* delete_A_Num (D_node_t *header) {
	int num;
	printf ("Enter number \n");
	scanf ("%d", &num);
	int position = find (num, header);
	if (position == -1) {
		printf ("number not found \n");
	} else if (position == length (header) - 1) {
		header = delete_End (header);
	} else if (position == length (header)) {
		printf ("No after nodes \n");
	} else {
		D_node_t *temp = header->next;
		D_node_t *ptr = NULL;
		int i = 0;
		while (i < position - 1) {
			temp = temp->next;
			i++;
		}
		ptr = temp->next;
		ptr->prev->next = ptr->next;
		ptr->next->prev = ptr->prev;
		ptr->next = NULL;
		ptr->prev = NULL;
		free (ptr);
	}
	return header;
}		
