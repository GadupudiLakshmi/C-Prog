#include <stdio.h>

int g_var1 = 10;
int g_var2 = 11;
//extern int ex;

void func (int );
int main ()
{
	int l_var1 = 20;
	int l_var2 = 30;
	if (l_var1 = l_var2) { 
	printf ("%d \n", l_var1);
	}
	printf ("%d \n", l_var2);
	printf ("%d \n", g_var1);
	printf ("%d \n", g_var2);
	func (g_var2);
	return 0;
}
	
