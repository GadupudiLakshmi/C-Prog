#ifndef _HEADER__H__
#define _HEADER__H__
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
struct QUEUE {
	int queue_ele[10];
	int front;
	int rear;
};

void insert (struct QUEUE *, int);
int delete1 (struct QUEUE *);
int isFull (struct QUEUE *);
int isEmpty (struct QUEUE *);
int printrear (struct QUEUE *);
int printfront (struct QUEUE *);
void traverse (struct QUEUE *);
#endif
