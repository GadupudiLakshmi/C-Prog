#include "header.h"

int isFull (struct QUEUE *ptr) {
	if (ptr->front == (ptr->rear + 1) % SIZE) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
