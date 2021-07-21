#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
#include "struct.h"

int main ()
{
	int fd;
	struct student *addr;
	struct student st;
	struct stat sb;
	printf ("%d \n", getpid ());
	fd = shm_open ("/SHARED", O_RDWR, 0666);
	if (fd == -1) {
		printf ("Cannot create \n");
	} else {
		printf ("created \n");
	}

	if (fstat (fd, &sb) == -1) {
		printf ("Failed \n");
	}

	addr = mmap (NULL, sb.st_size, PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED) {
		printf ("mmap failed \n");
	}
	printf ("%p \n", addr);
	addr = &st;

//	write (1, addr->name, 10);
	printf ("%s \n", st.name);
	printf ("\n");
	printf ("%d \n", (st.id));
	printf ("%d \n", addr->marks);
	return 0;
}
