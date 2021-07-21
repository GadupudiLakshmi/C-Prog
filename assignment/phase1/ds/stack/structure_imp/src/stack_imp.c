#include "header.h"

#if 0
struct STACK {
	int top;
	int stack_ele [10];
};

int isFull(struct STACK *ptr);
	if (ptr->top == 9) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
int isEmpty (struct STACK *ptr) {
	if (ptr->top == -1) {
		return (TRUE);
	} else {
		return (FALSE);
	}
}
void push (struct STACK *ptr, int x) {
	if (isFull(ptr)) {
		printf ("stack is full \n");
		exit (1);
	} else {
		ptr->stack_ele[++(ptr->top)] = x;
	}
}

int pop (struct STACK *ptr) {
	if (isEmpty (ptr)) {
		printf ("underflow \n");
		exit (1);
	} else {
		return ptr->stack_ele[ptr->top--];
	}
}
int peek (struct STACK *ptr) {
	return ptr->stack_ele[ptr->top];
}
#endif
int main ()
{
	int select;
	int item;
	int choice = 1;
	int num;
	struct STACK stack;
	stack.top = -1;

	while (choice) {
		printf ("select operation \n");
		scanf ("%d", &select);
		
		switch (select) {
		case 1:
			printf ("Enter element to push \n");
			scanf ("%d", &num);
			push (&stack, num);
			break;
		case 2:
			printf ("popped element is %d \n", pop (&stack));
			break;
		case 3:
			printf ("top element is %d \n", peek (&stack));
			break;
		case 4:
			printf ("stack Traverse \n");
			traverse (&stack);
			break;
		default :
			printf ("Invalid selection \n");
		}
		printf ("continue? 0/1 \n");
		scanf ("%d", &choice);
	}
	return 0;
}
