#include "header.h"

void traverse (struct STACK *ptr) {
	if (isEmpty(ptr)) {
		printf ("underflow \n");
	} else {
		int i = ptr->top;
		for (i; i >= 0; i--) {
			printf ("%d \n", ptr->stack_ele[i]);
		}
	}
}
