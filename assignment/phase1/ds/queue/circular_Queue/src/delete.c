#include "header.h"

int delete1 (struct QUEUE *ptr) {
	if (isEmpty (ptr)) {
		printf ("underflow \n");
		exit (1);
	} else if (ptr->front == ptr->rear) {
		int x = ptr->queue_ele[ptr->front];
		ptr->rear = ptr->front = -1;
		return x;
	} else {
		int x = ptr->queue_ele[ptr->front];
		ptr->front = (ptr->front + 1) % SIZE;
		return x;
	}
}
