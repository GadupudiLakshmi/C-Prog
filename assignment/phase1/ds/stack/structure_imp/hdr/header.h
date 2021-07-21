#ifndef _HEADER__H__
#define _HEADER__H__
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct STACK {
	int top;
	int stack_ele [10];
};
int isFull(struct STACK *);
int isEmpty (struct STACK *); 
void push (struct STACK *, int); 
int pop (struct STACK *); 
int peek (struct STACK *); 
void traverse (struct STACK *);
#endif

