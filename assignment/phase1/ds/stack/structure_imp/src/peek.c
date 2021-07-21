#include "header.h"

int peek (struct STACK *ptr) {
	if (isEmpty(ptr)) {
		printf ("stack underflow \n");
		exit (1);
	} else {
		return ptr->stack_ele[ptr->top];
	}
}
