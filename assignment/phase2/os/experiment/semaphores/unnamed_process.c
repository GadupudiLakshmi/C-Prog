#include <stdio.h>
#include <semaphore.h>
#include <unistd.h>
#include <sys/types.h>
#include <pthread.h>

//	int global = 0;
int main ()
{
	pid_t fd;
	sem_t sem;
	int global = 0;
	int shm = sem_init (&sem, 1, 1);
	int *shared;
	
	if (shm == -1) {
		printf ("cannot open \n");
	}
	pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;
	fd = fork ();
	
	if (fd > 0) {
		sem_wait (&sem);
		while (global < 10) {
			if (global % 2 == 0)
				printf ("globalP %d \n", global);
			global++;
			sleep (1);
		}
		sem_post (&sem);
	} else if (fd == 0) {
		sem_wait (&sem);
		while (global < 10) {
			if (global % 2 != 0) {
				printf ("globalC %d \n", global);
				sleep (1);
			}
		global++;
		}
		sem_post (&sem);
	} else {
		printf ("no child created \n");
	}

	return 0;
}
