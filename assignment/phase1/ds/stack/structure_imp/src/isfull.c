#include "header.h"

int isFull(struct STACK *ptr) {
	if (ptr->top == 9) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
