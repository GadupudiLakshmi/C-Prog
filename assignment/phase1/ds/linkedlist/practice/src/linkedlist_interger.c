#include <stdio.h>
#include <stdlib.h>
#include <stdio_ext.h>

typedef struct _node_t {
	int value;
	struct _node_t *link;
}node_t;

node_t* addnode (node_t *);
node_t* insert_First (node_t *);
node_t* insert_Pos (node_t *);
node_t* delete_Fst (node_t *);
node_t* delete_Last (node_t*);
void print (node_t *);
int main ()
{
	node_t *list = NULL;
	node_t *ptr;
	int option;
	int choice = 1;
	
	do {
		printf ("Enter your option \n");
		scanf ("%d", &option);

		switch (option) {
		case 1:
			printf ("creating node and insert at end\n");
			if (list == NULL) {
				ptr = (node_t *) addnode (ptr);
				list = ptr;
			} else {
				node_t *ptr1 = list;
				while (ptr1->link != NULL) {
					ptr1 = ptr1->link;
				}
				ptr = (node_t *) addnode (ptr);
				ptr1->link = ptr;
			}
			break;
		case 2:
			printf ("Printing list Items \n");
			print (list);	
			break;
		case 3:
			printf ("creating and Inserting node at begining \n");
			if (list == NULL) {
				ptr = (node_t *) insert_First (ptr);
				list = ptr;
