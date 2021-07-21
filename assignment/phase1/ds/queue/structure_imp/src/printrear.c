#include "header.h"

int printrear (struct QUEUE *ptr) {
	if (isEmpty(ptr)) {
		printf ("underflow \n");
	} else {
		return ptr->queue_ele[ptr->rear];
	}
}
