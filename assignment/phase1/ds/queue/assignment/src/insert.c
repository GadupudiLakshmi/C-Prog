#include "header.h"

void insert (struct QUEUE *ptr, int x) {
	if (isFull (ptr)) {
		printf ("overflow \n");
		exit (1);
	} else {
		ptr->rear++;
		ptr->queue_ele[ptr->rear] = x;
	}
}
