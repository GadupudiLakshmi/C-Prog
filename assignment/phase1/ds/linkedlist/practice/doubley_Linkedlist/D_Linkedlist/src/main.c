#include "header.h"

int main ()
{
	D_node_t *header = NULL;
	header = (D_node_t *) malloc (sizeof (D_node_t));
	header->prev = header->next = header;
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
			header = insert_End (header);
			break;
		case 2:
			printf ("Insert at start of circular LinkedList \n");
			header = insert_Fst (header);
			break;
		case 3:
			printf ("Insert at given position \n");
			header = insert_Pos (header);
			break;
		case 4:
			printf ("Insert after given position \n");
			header = insert_A_Pos (header);
			break;
		case 5:
			printf ("Insert before given position \n");
			header = insert_B_Pos (header);
			break;
		case 6:
			printf ("Insert before given number \n");
			header = insert_B_Num (header);
			break;
		case 7:
			printf ("Insert after given number \n");
			header = insert_A_Num (header);
			break;
		case 8:
			printf ("Insert at middle \n");
			header = insert_Middle (header);
			break;
		case 9:
			printf ("Insert at penultimate node \n");
			header = insert_Penultimate (header);
			break;
		case 10:
			printf ("Delete at End \n");
			header = delete_End (header);
			break;
		case 11:
			printf ("Delete Fisrt node \n");
			header = delete_Fst (header);
			break;
		case 12:
			printf ("Delete at given Position \n");
			header = delete_Pos (header);
			break;
		case 13:
			printf ("Delete before Position \n");
			header = delete_B_Pos (header);
			break;
		case 14:
			printf ("Delete after Position \n");
			header = delete_A_Pos (header);
			break;
		case 15:
			printf ("Delete before number \n");
			header = delete_B_Num (header);
			break;
		case 16:
			printf ("Delete after number \n");
			header = delete_A_Num (header);
			break;
		case 17:
			printf ("Delete at middle \n");
			header = delete_Middle (header);
			break;
		case 18:
			printf ("Delete Penultimate node \n");
			header = delete_Penultimate (header);
			break;
		case 19:
			printf ("Print list \n");
			print (header);
			break;
		case 20:
			free (header);
			exit (0);
			break;
		default :
			printf ("Invalid selection \n");
		}
	}
	
	return 0;
}
