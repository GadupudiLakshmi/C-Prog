#include "header.h"

node_t *deletequeue (struct QUEUE *ptr) {
	if (isEmpty (ptr)) {
		printf ("underflow \n");
		exit (1);
	} else if (ptr->front == ptr->rear) {
		node_t *x = ptr->queue_ele[ptr->front];
		ptr->rear = ptr->front = -1;
		return x;
	} else {
		node_t *x = ptr->queue_ele[ptr->front];
		ptr->front = (ptr->front + 1) % 8;
		return x;
	}
}
