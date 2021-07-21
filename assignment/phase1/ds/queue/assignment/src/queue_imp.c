#include <header.h>

int main ()
{
	struct QUEUE queue1;
	struct QUEUE queue2;
	struct QUEUE queue3;
	int num;
	int i;
	int size1 = 5;
	int size2 = 6;
	int size3 = size1 + size2;
	queue1.rear = -1;
	queue1.front = 0;
	queue2.rear = -1;
	queue2.front = 0;
	queue3.rear = -1;
	queue3.front = 0;
	for (i = 0; i < size1; i++) {
		printf ("Enter element to Insert \n");
		scanf ("%d", &num);
		insert (&queue1, num);
	}
	for (i = 0; i < size2; i++) {
		printf ("Enter element into Insert \n");
		scanf ("%d", &num);
		insert (&queue2, num);
	}
	for (i = 0; i < size3; i++) {
		num = delete1 (&queue1);
		if (num != -1) {
			printf ("inserting into q3\n");
			insert (&queue3, num);
		}
		num = delete1 (&queue2);
		if (num != -1) {
			insert (&queue3, num);
		}
	}
	printf ("%d %d \n", queue3.rear, queue3.front);
	traverse (&queue3);
	return 0;
}
	
			

