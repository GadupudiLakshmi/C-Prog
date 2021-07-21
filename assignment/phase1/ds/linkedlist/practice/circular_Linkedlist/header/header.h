#ifndef _HEADER__H__
#define _HEADER__H__

#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	int data;
	struct _node_t *link;
}node_t;

typedef struct _node_t1 {
	int data;
	struct _node_t1 *link;
}node_t1;

typedef struct _node_t2 {
	int data;
	struct _node_t2 *link;
}node_t2;

node_t* insert_End (node_t*);
node_t2* insert_End2 (node_t2*);
node_t1* insert_End1 (node_t1*);
node_t* createnode (node_t *);
node_t2* createnode2 (node_t2 *);
node_t1* createnode1 (node_t1 *);
node_t* insert_Fst (node_t *);
node_t* insert_Pos (node_t *);
node_t* insert_A_Pos (node_t *);
node_t* insert_B_Pos (node_t *);
node_t* insert_B_Num (node_t *);
node_t* insert_A_Num (node_t *);
node_t* insert_Middle (node_t *);
node_t* insert_Penultimate (node_t *);
node_t* delete_Fst (node_t *);
node_t* delete_Last (node_t *);
node_t* delete_Pos (node_t *);
node_t* delete_A_Pos (node_t *);
node_t* delete_B_Pos (node_t *);
node_t* delete_B_Num (node_t *);
node_t* delete_A_Num (node_t *);
node_t* delete_Middle (node_t *);
node_t* delete_Penultimate (node_t *);
node_t* reverse (node_t *, node_t *);
node_t* concate (node_t*, node_t1*);
node_t* arrange (node_t*);
void verify ();
int lastnode (node_t *, int );
int middle (node_t *);
int length (node_t *);
int find (int,node_t*);
void print ();
#endif
