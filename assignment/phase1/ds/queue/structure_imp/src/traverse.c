#include "header.h"

void traverse (struct QUEUE *ptr) {
	printf ("Traverse \n");
	if (isEmpty (ptr)) {
		printf ("underflow \n");
	} else {
		int i = ptr->front;
		for (i; i <= ptr->rear; i++) {
			printf ("%d\n", ptr->queue_ele[i]);
		}
	}
}

