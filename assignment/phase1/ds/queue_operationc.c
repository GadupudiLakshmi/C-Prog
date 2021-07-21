#include <stdio.h>
#include <stdlib.h>
 
#define MAX 8
 
void insert();
void delete();
void peek();
void print();

int queue1[MAX];
int queue2[MAX];
int queue3[MAX + MAX];
int rear = -1;
int front = -1;

int main()
{
    int choice;
    while (1)
    {
       	printf("\nEnter your choice:\n");
		printf("1.Insert\n2.Delete\n3.Peek\n4.Print\n5.Exit\n");
		scanf("%d", &choice);
        switch (choice)
        {
            case 1 : insert();
            		 break;
            case 2 : delete();
            		 break;
			case 3 : peek();
					 break;
            case 4 : print();
            		 break;
            case 5 : exit(1);
			
            default : printf("Invalid choice!.....\n");
        } 
    }
} 
 
void insert() 
{
    int data;
	
    if (rear == MAX - 1) {
		printf("Queue is full.. Cannot insert element..\n");
    } else {
        if (front == - 1) {
        	front = 0;
		}
        printf("Inset the element in queue : ");
        scanf("%d", &data);
        rear = rear + 1;
        queue[rear] = data;
    }
} 
 
void delete() 
{	
	int i;
	//temp = rear;
	if (front == - 1 || front > rear) {
        printf("Queue is empty... \n");
    } else {
        printf("Element deleted from queue is : %d\n", queue[front]);
       // front = front + 1;
		//rear = rear - 1;
		for (i = 0 ; i < rear ; i++) {
			queue[i] = queue[i+1];
		}
		rear--;
    }
} 

void peek() 
{
 	printf("The peek element is:%d\n", queue[front]);
}

void print()
{
    int i;
	int temp;
	temp = front;
    if (front == - 1 || front > rear) {
        printf("Queue is empty \n");

    } else {
        printf("The elements are : \n");
        for (i = front ; i <= rear  ; i++) {
            printf("%d ", queue[front]);
			front = front + 1;
		}
		front = temp;
		printf("\n");
    }
} 
