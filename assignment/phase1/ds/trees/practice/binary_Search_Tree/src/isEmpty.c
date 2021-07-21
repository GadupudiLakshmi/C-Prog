#include "header.h"

int isEmpty (struct QUEUE *ptr) {
	if (ptr->rear == -1 && ptr->front == -1) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
