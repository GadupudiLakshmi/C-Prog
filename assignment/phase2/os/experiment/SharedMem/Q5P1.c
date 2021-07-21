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

	printf ("%d\n", getpid ());

	fd = shm_open ("/SHARED", O_CREAT | O_RDWR, 0666);

	if (fd == -1) {
		printf ("Cannot create \n");
	} else {
		printf ("created \n");
	}

	if (ftruncate (fd, sizeof (st)) == -1) {
		printf ("Filed \n");
	}

	addr = mmap (NULL, sizeof (st), PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED) {
		printf ("mmap failed \n");
	}

	printf ("%p \n", addr);
	printf ("%d \n", addr->id);
	return 0;
}
