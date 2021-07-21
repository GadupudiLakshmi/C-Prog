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

	read (0, addr->name, 10);
	scanf ("%d", &(addr->id));
	scanf ("%d", &(addr->marks));

	return 0;
}
