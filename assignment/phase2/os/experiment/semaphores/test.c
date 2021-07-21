#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <pthread.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <semaphore.h>

sem_t sem;
int global;
void *thread1 (void *p) {
	sem_wait (&sem);
	for (int i = 0; i < 20; i++) {
		printf ("T1-%d \n", global);
		global++;
	}	
	sem_post (&sem);
}

void *thread2 (void *p) {
	sem_wait (&sem);
	for (int j = 0; j < 20; j++) {
		printf ("T2-%d \n", global);
		global++;
	}
	sem_post (&sem);
}

int main ()
{
	sem_init (&sem, 0, 1);
	pthread_t th1;
	pthread_t th2;
	int thread = pthread_create (&th1, NULL, thread1, NULL);
	thread = pthread_create (&th2, NULL, thread2, NULL);
	pthread_exit (NULL);
}
