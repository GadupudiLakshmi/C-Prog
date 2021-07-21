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

node_t *insert (node_t*);
node_t *createnode (node_t*);
node_t *deleteLeaf (node_t*);
void preOrder (node_t*);
void inOrder (node_t*);
void postOrder (node_t*);
#endif
