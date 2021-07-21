#include <stdio.h>
#include <stdlib.h>
int binarysearch (char**, int , int, char*);
   int main()
   {
   
       int i;
      int j;
       int row;
       int col;
		char key[] = "Lakshmi"; 
  
      printf("Enter the number of rows:\n");
      scanf("%d", &row);
  
      printf("Enter the number of columns:\n");
      scanf("%d", &col);
  
      char *ptr[col];
  
      for (i = 0 ; i < row ; i++) {
          ptr[i]  = (char *)malloc(sizeof(char) * 20);
      }
  
      printf("Enter the string:\n");
      for (i = 0 ; i < row ; i++) {
          scanf("%s", *(ptr+i));
      }
  
      printf("the array elements are:\n");
      for (i = 0 ; i < row ; i++) {
          printf("%s\n", *(ptr+i));
      }
	int x = binarysearch (ptr, 0, row, key);
	if (x != -1) {
		printf ("Found \n");
	} else {
		printf ("not \n");
	}
/*	int mid, low, high;
	low = 0;
	high = row-1;
	int flag = 0;
	while (low <= high) {
		mid = (low + high) / 2;
		if (strcmp (key, *(ptr + mid)) == 0) {
			flag = 1;
			break;
		} else if (strcmp (key, *(ptr + mid)) > 0) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	} 
	if (flag == 1) {
		printf ("found \n");
	} else {
		printf ("not found \n");
	}
*/
      return 0;
  }
                         
