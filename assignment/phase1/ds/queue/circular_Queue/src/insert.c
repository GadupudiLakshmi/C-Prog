#include "header.h"

void insert (struct QUEUE *ptr, int x) {
	if (isFull (ptr)) {
		printf ("overflow \n");
		exit (1);
	} else if (ptr->rear == -1 && ptr->front == -1){
		ptr->rear = ptr->front = 0;
		ptr->queue_ele[ptr->rear] = x;
	} else {
		ptr->rear = (ptr->rear + 1) % SIZE;
		ptr->queue_ele[ptr->rear] = x;
	} 
}
