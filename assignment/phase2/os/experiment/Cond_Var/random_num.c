#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int global;
int num;

void *random (void *ptr)
{	
	int i = 5;
	while (i) {
		pthread_mutex_lock (&mutex);
		global = rand ();
		printf ("value %d\n", global);
			num++;
		i--;
		pthread_cond_broadcast (&cond);
		pthread_cond_wait (&cond, &mutex);
		pthread_mutex_unlock (&mutex);
	}
	num = 0;
	pthread_cond_broadcast (&cond);
}

void *even (void *ptr)
{
	pthread_mutex_lock (&mutex);
	if (num == 0) {
		printf ("Even wait \n");
		pthread_cond_wait (&cond, &mutex);
	}
//	printf ("Even else enter \n");
	while (num) {
		while ((global % 2) != 0) {
			pthread_cond_wait (&cond, &mutex);
		}
		printf ("Even Thread %d \n", global);
		pthread_cond_broadcast (&cond);
		pthread_cond_wait (&cond, &mutex);
	}
	pthread_mutex_unlock (&mutex);
}

void *odd (void *ptr)
{
	pthread_mutex_lock (&mutex);
	if (num == 0) {
		printf ("Odd wait \n");
		pthread_cond_wait (&cond, &mutex);
	} 
//	printf ("Odd else \n");
	int temp = 0;
	while (num) {
		while (global % 2 == 0) {
			pthread_cond_wait (&cond, &mutex);
		}	
		pthread_cond_broadcast (&cond);
		printf ("odd Thread %d \n", global);
		pthread_cond_wait (&cond, &mutex);
	}
	pthread_mutex_unlock (&mutex);
}

int main ()
{
	pthread_t th1;
	pthread_t th2;
	pthread_t th3;
	int thread = pthread_create (&th1, NULL, random, NULL);

	if (thread == 0) {
		printf ("thread1 created \n");
	} else {
		printf ("Thread1 not created\n");
	}
	thread = pthread_create (&th2, NULL, even, NULL);
	if (thread == 0) {
		printf ("thread2 created\n");
	} else {
		printf ("thread2 not created \n");
	}
	thread = pthread_create (&th3, NULL, odd, NULL);
	if (thread == 0){
		printf ("thread3 created \n");
	} else {
		printf ("thread3 not created \n");
	}
	pthread_exit (NULL);
}
