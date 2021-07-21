#include <stdio.h>
#include <string.h>

int main (int argc, char *argv[])
{
	FILE *fd;
	char *ptr = NULL;
	ptr = strchr (argv[1], '.');
	printf ("%s \n", ptr);
	if (strchr (argv[1], '.') == NULL) {
		printf ("not found \n");
	} else {
		if (strcmp (ptr, ".txt") == 0) {
			printf ("found \n");
			fd = fopen (argv[1], "r");
			if (fd == NULL) {
				printf ("cannot open \n");
			}
			rewind (fd);
			char c;
			while ((c = fgetc (fd)) != EOF) {
				printf ("%c", c);
			}
		} else {
			printf ("cannot open \n");
		}
	}
	return 0;
}

	
	
