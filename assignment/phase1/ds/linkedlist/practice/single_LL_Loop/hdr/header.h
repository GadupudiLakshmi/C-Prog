#ifndef _HEADER__H__
#define _HEADER__H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	int data;
	struct _node_t *link;
} node_t;

node_t *insert_End (node_t*);
node_t *createloop (node_t*, int);
node_t *createnode (node_t*);
node_t *checkloop (node_t*);
void print (node_t*);
#endif
