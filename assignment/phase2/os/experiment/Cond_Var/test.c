#include <stdio.h>
#include <pthread.h>

int global;
int num;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *thread1 (void *ptr)
{
	for (int i = 0; i < num; i++) {
		pthread_mutex_lock (&mutex);
		global += 5;
		printf ("update \n");
		pthread_cond_signal (&cond);
		pthread_cond_wait (&cond, &mutex);
		pthread_mutex_unlock (&mutex);
	}
}

void *thread2 (void *ptr)
{
	
	pthread_mutex_lock (&mutex);
	while (global < 10) {
		num++;
		printf ("up %d\n", global);
		printf ("need update \n");
		pthread_cond_wait (&cond, &mutex);
		pthread_cond_signal (&cond);
	}
		pthread_cond_signal (&cond);
	printf ("global %d\n", global);
	
	pthread_mutex_unlock (&mutex);
}

int main ()
{
	pthread_t th1;
	pthread_t th2;
//	pthread_attr_t attr;
//	pthread_attr_init (&attr);	
	int tr = pthread_create (&th1, NULL, thread2, NULL);
	tr = pthread_create (&th1, NULL, thread1, NULL);
	pthread_exit (NULL);
}
