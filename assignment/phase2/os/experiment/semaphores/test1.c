#include <stdio.h>
#include <semaphore.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <string.h>
#include <fcntl.h>

int main ()
{
	sem_t *sem;
	int fd;
	char *addr;
	char buff[10] = "Lakshmi";

	sem = sem_open ("/NAMED", O_CREAT, 0666, 1);
	if (sem == SEM_FAILED) {
		printf ("semaphore not created \n");
	} else {
		fd = shm_open ("/SHARED", O_CREAT | O_RDWR, 0666);
		if (fd == -1) {
			printf ("Shared mem not created \n");
		} else {
			sem_wait (sem);
			printf ("opened \n");
			ftruncate (fd, strlen (buff));
			addr = mmap (NULL, strlen (buff), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
			if (addr == MAP_FAILED) {
				printf ("mmap failed \n");
			} else {
				memcpy (addr, buff, strlen (buff));
			}
			getchar ();
			sem_post (sem);
		}
	}
	return 0;
}	
