#include "header.h"

int isEmpty (struct QUEUE *ptr) {
	if (ptr->rear < ptr->front) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
