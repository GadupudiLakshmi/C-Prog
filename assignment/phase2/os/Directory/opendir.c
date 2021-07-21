#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <string.h>

int main ()
{
	DIR *dr;
	struct dirent *dir;
	char *ch = NULL;
//	int stat;
	struct stat st;
	dr = opendir ("../experiment/MQueue");
	if (dr == NULL) {
		printf ("Cannot open directory \n");
	} else {
		printf ("directory opened \n");
		
		while ((dir = readdir (dr)) != NULL) {
			stat (dir->d_name, &st);
//			printf ("%ld \t", dir->d_ino);
//			printf ("%ld \t", dir->d_off);
//			printf ("%d \t", dir->d_reclen);
//			printf ("%c \t", dir->d_type);
			printf ("%s\t", dir->d_name);

			printf ("filesize: %ld \t", st.st_size);
			printf ("UID: %d \t", st.st_uid);
			printf ("GID: %d \t", st.st_gid);
			printf ("Total Size: %ld \n", st.st_size);
		}
//			char *ch = NULL;
//			ch = strchr (dir->d_name, '.');
//			if (ch != NULL) {
//				if (strcmp (ch, ".c") == 0) {
//					printf ("%s \n", dir->d_name);
//				}
//			}  
			
	}	
	return 0;
}
