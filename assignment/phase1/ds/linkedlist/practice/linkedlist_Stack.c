#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	int data;
	struct _node_t *link;
}node_t;

node_t* push (int , node_t *);
node_t* pop ();
void traverse (node_t *);
int main ()
{
	node_t *top = NULL;
	int option;
	int choice = 1;
		
	do {
		printf ("select option \n");
		scanf ("%d", &option);
			
		switch (option) {
		case 1:
			printf ("Push operation \n");
			int num;
			printf ("enter value to push into stack \n");
			scanf ("%d", &num);
			top = push (num, top);
			printf ("push success \n");
			break;

		case 2:
			printf ("Pop operation \n");
			if (top == NULL) {
				printf ("stack is empty \n");
			} else {
				top = pop (top);
			}
			break;

		case 3:
			printf ("Traverse stack \n");
			if (top == NULL) {
				printf ("Stack is empty \n");
			} else {
				traverse (top);
			}
			break;
		default:
			printf ("invalid \n");
	
		}
		printf ("cont 0/1 \n");
		scanf ("%d", &choice);
	} while (choice); 
}


node_t* push (int num, node_t *top) {
	node_t *temp;
	temp = (node_t *) malloc (sizeof (node_t));
	
	temp->data = num;
	temp->link = top;
	top = temp;
	return top;
}

node_t* pop (node_t *top) {
	node_t *temp;
	temp = top;

	top = top->link;
	temp->link = NULL;
	printf ("%d \n", temp->data);
	free (temp);
	return top;
}

void traverse (node_t *top) {
	node_t *temp;
	temp = top;
	
	while (temp != NULL) {
		printf ("%d \n", temp->data);
		temp = temp->link;
	}
}
