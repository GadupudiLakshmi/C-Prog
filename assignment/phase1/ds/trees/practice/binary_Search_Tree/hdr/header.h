#ifndef _HEADER__H__
#define _HEADER__H__

#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct _node_t {
	int data;
	struct _node_t *left;
	struct _node_t *right;
} node_t;

node_t *insertBST (node_t*,int);
node_t *createnode (node_t*);
node_t *deleteBST (node_t*,int);
node_t *search (node_t*, int);
int maxValue (node_t*);
int minValue (node_t*);
void preOrder (node_t*);
void inOrder (node_t*);
void postOrder (node_t*);
int height (node_t*);
void levelTraverse (node_t*);
#define TRUE 1
#define FALSE 0
struct QUEUE {
	int queue_ele[10];
	int front;
	int rear;
};

node_t *insertqueue (struct QUEUE *, node_t*);
node_t *deletequeue (struct QUEUE *);
int isFull (struct QUEUE *);
int isEmpty (struct QUEUE *);

#endif
