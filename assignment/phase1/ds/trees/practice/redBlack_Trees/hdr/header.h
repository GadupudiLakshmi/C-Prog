#ifndef _HEADER__H__
#define _HEADER__H__
#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	struct _node_t *left;
	char color : 1;
	int data;
	struct _node_t *right;
} node_t;

node_t *insertRBT (node_t*, int, node_t*);
node_t *createnode (node_t*);
node_t *rightRotate (node_t*);
node_t *leftRotate (node_t*);
node_t *checkColor (node_t*, node_t*);
node_t *search (node_t*, int);
void inOrder (node_t*);
void postOrder (node_t*);
#endif
