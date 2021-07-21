#include "header.h"

int isEmpty (struct STACK *ptr) {
	if (ptr->top == -1) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
