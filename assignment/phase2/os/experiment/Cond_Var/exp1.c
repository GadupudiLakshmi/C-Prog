#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int global = 1;

void *threadOne (void *ptr)
{
	pthread_mutex_lock (&mutex);
	while (global != 1) {
		pthread_cond_wait (&cond, &mutex);
	}
	printf ("threadOne %d \n", global++);
	pthread_cond_signal (&cond);
	pthread_mutex_unlock (&mutex);
}

void *threadTwo (void *ptr)
{
	pthread_mutex_lock (&mutex);
	while (global != 2) {
		pthread_cond_wait (&cond, &mutex);
	}
	pthread_cond_signal (&cond);
	printf ("threadTwo %d \n", global++);
	pthread_mutex_unlock (&mutex);
}

void *threadThre (void *ptr)
{
	pthread_mutex_lock (&mutex);
	while (global != 3) {
		pthread_cond_wait (&cond, &mutex);
	}
	pthread_cond_signal (&cond);
	printf ("threadThree %d \n", global);
	pthread_mutex_unlock (&mutex);
}

int main ()
{
	pthread_t th1;
	pthread_t th2;
	pthread_t th3;
	int thread = pthread_create (&th1, NULL, threadOne, NULL);
	thread = pthread_create (&th2, NULL, threadTwo, NULL);
	thread = pthread_create (&th3, NULL, threadThre, NULL);
	
	pthread_exit (NULL);
}
