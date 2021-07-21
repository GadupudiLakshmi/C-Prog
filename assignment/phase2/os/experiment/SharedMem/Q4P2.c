#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>
int main ()
{
	int fd;
	int *addr;
	struct stat sb;
	printf ("%d \n", getpid ());
	fd = shm_open ("/OPEN",  O_CREAT | O_RDWR, 0666);
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
	printf ("lskj\n");
	printf ("befor %d \n", *addr);
	*addr = 200;	
	printf ("%d \n", *addr);
	return 0;
}
