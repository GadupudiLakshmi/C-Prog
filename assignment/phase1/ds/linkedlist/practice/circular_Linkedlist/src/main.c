#include "header.h"

int main ()
{
	int option;
	int choice;
	node_t *list = NULL;
	node_t1 *list1 = NULL;
	node_t2 *list2 = NULL;
	do {
		printf ("Enter option \n");
		scanf ("%d", &option);
		
		switch (option) {
		case 1:
			printf ("Insert at End \n");
			list = insert_End (list);	
			break;
		case 2:
			printf ("Insert at First \n");
			list = insert_Fst (list);
			break;
		case 3:
			printf ("Insert node at given position \n");
			list = insert_Pos (list);
			break;
		case 4:
			printf ("Insert node after the given position \n");
			list = insert_A_Pos (list);
			break;
		case 5:
			printf ("Insert node before the given position \n");
			list = insert_B_Pos (list);
			break;
		case 6:
			printf ("Insert node before given numer \n");
			list = insert_B_Num (list);
			break;
		case 7:
			printf ("Insert node after given number \n");
			list = insert_A_Num (list);
			break;
		case 8:
			printf ("Insert node at middle of list \n");
			list = insert_Middle (list);
			break;
		case 9:
			printf ("Insert Penultimate node \n");
			list = insert_Penultimate (list);
			break;
		case 10:
			printf ("Deleting 1st node \n");
			list = delete_Fst (list);
			break;
		case 11:
			printf ("Deleting last node \n");
			list = delete_Last (list);
			break;
		case 12:
			printf ("Deleting node at given Position \n");
			list = delete_Pos (list);
			break;
		case 13:
			printf ("Deleting node after the given position \n");
			list = delete_A_Pos (list);
			break;
		case 14:
			printf ("Deleting node before the given position \n");
			list = delete_B_Pos (list);
			break;
		case 15:
			printf ("Deleting node before given number \n");
			list = delete_B_Num (list);
			break;
		case 16:
			printf ("Deleting node after given number \n");
			list = delete_A_Num (list);
			break;
		case 17:
			printf ("Deleting middle node \n");
			list = delete_Middle (list);
			break;
		case 18:
			printf ("Deleting penultimate node \n");
			list = delete_Penultimate (list);
			break;
		case 19:
			printf ("Reverse of List \n");
			list = reverse (list, list);
			break;
		case 20:
			printf ("List data \n");
			print (list);
			break;
		case 21:
			printf ("number of nodes in list \n");
			printf ("%d \n", length (list));
			break;	
		case 22:
			printf ("Middle element \n");
			printf ("%d \n", middle (list));
			break;
		case 23:
			printf ("nth node \n");
			int n;
			printf ("Enter n \n");
			scanf ("%d", &n);
			printf ("%dth node is %d \n", n, lastnode (list, n));
			break;
		case 24:
			printf ("Insert into 2nd list \n");
			list1 = insert_End1 (list1);
			break;
		case 25:
			printf ("display 2nd list \n");
			print (list1);
			break;
		case 26:
			printf ("Concatinate two lists \n");
			list = concate (list, list1);
			break;
		case 27:
			printf ("Even numbers first \n");
			list = arrange (list);
			break;
		case 28:
			printf ("Insert circular \n");
			list2 = insert_End2 (list2);
			break;
		case 29:
			printf ("verify single or circular \n");
			verify (list);
			break;
		case 30:
			printf ("Verify single or circular \n");
			verify (list2);
			break;
		case 31:
			print (list2);
			break;
		default:
			printf ("Invalid selection \n");
		}
		
		printf ("Continue 0/1 \n");
		scanf ("%d", &choice);
	} while (choice);

	return 0;
}
	
