#ifndef _HEADER__H__
#define _HEADER__H__
#include <stdio.h>
#include <stdlib.h>

typedef struct _D_node_t {
	struct _D_node_t *next;
	int data;
	struct _D_node_t *prev;
}D_node_t;

D_node_t* insert_End (D_node_t*);
D_node_t* createnode (D_node_t*);
D_node_t* insert_Fst (D_node_t*);
D_node_t* insert_Pos (D_node_t*);
D_node_t* insert_A_Pos (D_node_t*);
D_node_t* insert_B_Pos (D_node_t*);
D_node_t* insert_B_Num (D_node_t*);
D_node_t* insert_A_Num (D_node_t*);
D_node_t* insert_Middle (D_node_t*);
D_node_t* insert_Penultimate (D_node_t*);
D_node_t* delete_End (D_node_t*);
D_node_t* delete_Fst (D_node_t*);
D_node_t* delete_Pos (D_node_t*);
D_node_t* delete_B_Pos (D_node_t*);
D_node_t* delete_A_Pos (D_node_t*);
D_node_t* delete_B_Num (D_node_t*);
D_node_t* delete_A_Num (D_node_t*);
D_node_t* delete_Middle (D_node_t*);
D_node_t* delete_Penultimate (D_node_t*);
int find (int , D_node_t*);
int length (D_node_t*);
void print (D_node_t*);

#endif
