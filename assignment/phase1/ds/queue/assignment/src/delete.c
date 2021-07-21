#include "header.h"

int delete1 (struct QUEUE *ptr) {
	if (isEmpty (ptr)) {
		printf ("underflow \n");
		exit (1);
	} else {
		return ptr->queue_ele[ptr->front++];
	}
}
