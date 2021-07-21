#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/mman.h>
#include <string.h>
#include <semaphore.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <pthread.h>

int main ()
{
	sem_t *sem;
	int fd;
	char *addr;
	struct stat sb;

	sem = sem_open ("/NAMED", O_RDWR);
	if (sem == SEM_FAILED) {
		printf ("semaphore cannot open \n");
	} else {
		fd = shm_open ("/SHARED", O_RDWR, 0666);
		if (fd == -1) {
			printf ("Cannot open \n");
		} else {
			sem_wait (sem);
			printf ("opened \n");
			if (fstat (fd, &sb) == -1) {
				printf ("failed to read \n");
			} else {
				addr = mmap (NULL, sb.st_size, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
				if (addr == MAP_FAILED) {
					printf ("mmap failed \n");
				} else {
					write (1, addr, sb.st_size);
				}
				getchar ();
			sem_post (sem);
			}
		}
	}
	return 0;
}
