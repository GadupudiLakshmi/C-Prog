#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/mman.h>
#include <string.h>

int global;
int main ()
{
	int fd;
	char *addr;
//	char buff[10] = "Lakshmi";
	printf ("%d\n", getpid ());

	fd = shm_open ("/OPEN",  O_CREAT | O_RDWR, 0666);
	if (fd == -1) {
		printf ("Cannot create \n");
	} else {
		printf ("created \n");
	}
	if (ftruncate (fd, sizeof (int)) == -1) {
		printf ("Filed \n");
	}
	addr = mmap (NULL, sizeof (int), PROT_READ | PROT_WRITE , MAP_SHARED, fd, 0);
	if (addr == MAP_FAILED) {
		printf ("mmap failed \n");
	}
	printf ("%p \n", addr);
	global = 0;
	memcpy (addr, &global, sizeof (int));
	printf ("before %d \n", *addr);
	close (fd);

//	getchar ();
//	if (shm_unlink ("/OPEN")) {
//		printf ("Failed \n");
//	}
	return 0;
}
