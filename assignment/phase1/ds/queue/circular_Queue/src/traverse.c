#include "header.h"

void traverse (struct QUEUE *ptr) {
	if (isEmpty (ptr)) {
		printf ("underflow \n");
	} else {
		int temp = ptr->front;
		while (temp != ptr->rear) {
			printf ("%d \n", ptr->queue_ele[temp]);
			temp = (temp + 1) % SIZE;
		}
		printf ("%d \n", ptr->queue_ele[temp]);
	}
}
