#include "header.h"

int isFull (struct QUEUE *ptr) {
	if (ptr->front == (ptr->rear + 1) % 8) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
