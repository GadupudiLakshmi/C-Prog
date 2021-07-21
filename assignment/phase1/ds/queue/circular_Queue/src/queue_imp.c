#include <header.h>

int main ()
{
	struct QUEUE queue;
	int choice = 1;
	int num;
	int selection;
	queue.rear = -1;
	queue.front = -1;
	
	while (choice) {
		printf ("selection \n");
		scanf ("%d", &selection);
		
		switch (selection) {
			case 1:
				printf ("Enter element to Insert \n");
				scanf ("%d", &num);
				insert (&queue, num);
				break;
			case 2:
				printf ("deleted element is%d\n", delete1 (&queue));
				break;
			case 3:
				printf ("Queue traverse \n");
				traverse (&queue);
				break;
			default :
				printf ("Invalid selection \n");
		}
		printf ("continue? 0/1 \n");
		scanf ("%d", &choice);
	}
}

