#include "header.h"

int isFull (struct QUEUE *ptr) {
	if (ptr->rear == 9) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
