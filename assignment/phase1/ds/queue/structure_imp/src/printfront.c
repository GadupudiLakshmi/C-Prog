#include "header.h"

int printfront (struct QUEUE *ptr) {
	if (isEmpty (ptr)) {
		printf ("underflow \n");
	} else {
		return ptr->queue_ele[ptr->front];
	}
}
