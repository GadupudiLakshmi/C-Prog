#include "header.h"

int main ()
{
	node_t *list = NULL;
	int option;
	int choice;
	
	while (1) {
		printf ("select your option \n \
		 1.insert_at_End \n \
		 2.insert_First \n \
		 3.insert_at_Given_Position\n \
		 4.insert_After_Given_Position \n \
		 5.insert_Before_Given_Position\n \
		 6.insert_Befor_Given_Number \n \
		 7.insert_After_Given_Number\n \
		 8.insert_Middle \n \
		 9.insert_Penultimatenode \n \
		 10.Delete_At_End \n \
		 11.delete_First \n \
		 12.Delete_at_given_position \n \
		 13.Delete_before_given_position \n \
		 14.Delete_after_given_position \n \
		 15.Delete_before_given_number \n \
		 16.Delete_after_given_number \n \
		 17.Delete_at_middle \n \
		 18.Delete Penultimate \n \
		 19.PrintList \n \
		 20.exit \n");
		scanf ("%d", &option);
		
		switch (option) {
		case 1:
			printf ("Insert at end in circular Linkedlist \n");
			list = insert_End (list);
			break;
		case 2:
			printf ("Insert at start of circular LinkedList \n");
			list = insert_Fst (list);
			break;
		case 3:
			printf ("Insert at given position \n");
			list = insert_Pos (list);
			break;
		case 4:
			printf ("Insert after given position \n");
			list = insert_A_Pos (list);
			break;
		case 5:
			printf ("Insert before given position \n");
			list = insert_B_Pos (list);
			break;
		case 6:
			printf ("Insert before given number \n");
			list = insert_B_Num (list);
			break;
		case 7:
			printf ("Insert after given number \n");
			list = insert_A_Num (list);
			break;
		case 8:
			printf ("Insert at middle \n");
			list = insert_Middle (list);
			break;
		case 9:
			printf ("Insert at penultimate node \n");
			list = insert_Penultimate (list);
			break;
		case 10:
			printf ("Delete at End \n");
			list = delete_End (list);
			break;
		case 11:
			printf ("Delete Fisrt node \n");
			list = delete_Fst (list);
			break;
		case 12:
			printf ("Delete at given Position \n");
			list = delete_Pos (list);
			break;
		case 13:
			printf ("Delete before Position \n");
			list = delete_B_Pos (list);
			break;
		case 14:
			printf ("Delete after Position \n");
			list = delete_A_Pos (list);
			break;
		case 15:
			printf ("Delete before number \n");
			list = delete_B_Num (list);
			break;
		case 16:
			printf ("Delete after number \n");
			list = delete_A_Num (list);
			break;
		case 17:
			printf ("Delete at middle \n");
			list = delete_Middle (list);
			break;
		case 18:
			printf ("Delete Penultimate node \n");
			list = delete_Penultimate (list);
			break;
		case 19:
			printf ("Print list \n");
			print (list);
			break;
		case 20:
			exit (0);
			break;
		default :
			printf ("Invalid selection \n");
		}
	}
	
	return 0;
}
