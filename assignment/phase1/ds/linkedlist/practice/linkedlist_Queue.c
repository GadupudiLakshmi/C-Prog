#include <stdio.h>
#include <stdlib.h>

typedef struct _node_t {
	int data;
	struct _node_t *link;
}node_t;

node_t* insert (node_t* );
node_t* delete (node_t* ,node_t*);
void traverse (node_t*, node_t*);

int main ()
{
	node_t *front = NULL;
	node_t *rear = NULL;
	node_t *ptr;
	int option;
	int choice = 1;
	do {
		printf ("select option \n");
		scanf ("%d", &option);
		
		switch (option) {
		case 1: 
			printf ("Insert into queue \n");
			if (front == NULL) {
				ptr = insert (ptr);
				front = ptr;
				rear = ptr;
			} else {
				ptr = insert (ptr);
				rear = ptr;
			}
//			int num;
//			printf ("element to insert \n");
//			scanf ("%d", &num);
//			insert (num, rear,front);
			break;
	
		case 2:
			printf ("Deleting from queue \n");
			if (front == NULL) {
				printf ("Queue is empty \n");
			} else {
			//	if (front == rear) {
			//		printf ("%d \n", front->data);
			//		front = rear = NULL;
			//	} else {
					front = delete (front, rear);
			//	}
			}
			break;
		case 3:
			printf ("Traverse Queue \n");
			if (front == NULL) {
				printf ("Queue is empty \n");
			} else {
				traverse (front, rear);
			}
			break;	
		default :
			printf ("Invalid selection \n");
		}
		printf ("Enter choice \n");
		scanf ("%d", &choice);
	} while (choice);
}


node_t* insert (node_t *rear) {
	node_t *temp = (node_t *) malloc (sizeof (node_t));
	int num;
	scanf ("%d", &num);
	temp->data = num;
	temp->link = NULL;
	rear->link = temp;
	rear = temp;
	return rear;
}

node_t* delete (node_t *front, node_t *rear) {
	node_t *temp = front;
	if (front == rear) {
		printf ("%d \n", front->data);
		front = rear = NULL;
	} else {
		front = front->link;
		printf ("%d \n", temp->data);
	}
	free (temp);
	return front;
}

void traverse (node_t *front, node_t *rear) {
	node_t *temp = front;
	while (temp != NULL) {
		if (temp == rear) {
			printf ("%d\n", temp->data);
			temp = NULL;
		} else {
			printf ("%d \n", temp->data);
			temp = temp->link;
		}
	}
}
