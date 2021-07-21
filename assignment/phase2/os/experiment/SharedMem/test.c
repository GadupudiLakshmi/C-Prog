#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
int main ()
{
	int fd;
	char *addr;
	char buff[10] = "Lakshmi";
	printf ("%d\n", getpid ());

	fd = shm_open ("/OPEN", O_CREAT | O_RDWR, 0666);
	if (fd == -1) {
		printf ("Cannot create \n");
	} else {
		printf ("created \n");
	}
	if (ftruncate (fd, strlen (buff)) == -1) {
		printf ("Filed \n");
	}
	addr = mmap (NULL, strlen (buff), PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED) {
		printf ("mmap failed \n");
	}
	printf ("%p \n", addr);
	memcpy (addr, buff, strlen (buff));
	getchar ();
	return 0;
}
