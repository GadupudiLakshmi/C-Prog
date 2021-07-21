#include "header.h"

void push (struct STACK *ptr, int x) {
	if (isFull(ptr)) {
		printf ("stack is full overflow\n");
		exit (1);
	} else {
		ptr->top++;
		ptr->stack_ele[ptr->top] = x;
	}
}
