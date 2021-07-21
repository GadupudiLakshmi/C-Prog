#ifndef _HEADER__H__
#define _HEADER__H__
#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	int data;
	struct _node_t *link;
}node_t;

node_t* insert_End (node_t*);
node_t* createnode (node_t*);
node_t* insert_Fst (node_t*);
node_t* insert_Pos (node_t*);
node_t* insert_A_Pos (node_t*);
node_t* insert_B_Pos (node_t*);
node_t* insert_B_Num (node_t*);
node_t* insert_A_Num (node_t*);
node_t* insert_Middle (node_t*);
node_t* insert_Penultimate (node_t*);
node_t* delete_End (node_t*);
node_t* delete_Fst (node_t*);
node_t* delete_Pos (node_t*);
node_t* delete_B_Pos (node_t*);
node_t* delete_A_Pos (node_t*);
node_t* delete_B_Num (node_t*);
node_t* delete_A_Num (node_t*);
node_t* delete_Middle (node_t*);
node_t* delete_Penultimate (node_t*);
int find (int , node_t*);
int length (node_t*);
void print (node_t*);
#endif
