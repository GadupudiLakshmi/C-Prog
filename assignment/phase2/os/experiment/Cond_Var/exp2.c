#include <stdio.h>
#include <pthread.h>

pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
int global;
int num1;
int num;
void *even (void *ptr)
{
	pthread_mutex_lock (&mutex);
	if (num == 0) {
		printf ("Even wait \n");
		pthread_cond_wait (&cond, &mutex);
	} else {
		printf ("Even else enter \n");
		int temp = 0;
		while ((global % 2) != 0) {
			printf ("even enter \n");
			printf ("Even wait2\n");
			pthread_cond_wait (&cond, &mutex);
			pthread_cond_broadcast (&cond);
		}
		printf ("Even %d \n", global);
		pthread_cond_broadcast (&cond);
		}
	pthread_mutex_unlock (&mutex);
}

void *odd (void *ptr)
{
	pthread_mutex_lock (&mutex);
	if (num1 == 0) {
		printf ("Odd wait \n");
	} else {
		printf ("Odd else \n");
		int temp = 0;
		while (global % 2 == 0) {
			printf ("odd wait1\n");
			pthread_cond_wait (&cond, &mutex);
			pthread_cond_broadcast (&cond);
		}	
		pthread_cond_signal (&cond);
		printf ("odd %d \n", global);
		}
	pthread_mutex_unlock (&mutex);
}
int main ()
{
	pthread_t th1;
	pthread_t th2;
	int thread = pthread_create (&th1, NULL, even, NULL);
	thread = pthread_create (&th2, NULL, odd, NULL);
	while (!(num1 && num)) {
		pthread_mutex_lock (&mutex);
		global = rand ();
		printf ("%d \n", global);
		if (global % 2 == 0) {
			printf ("Even \n");
			num++;
		} else {
			printf ("Odd \n");
			num1++;
		}
		pthread_cond_broadcast (&cond);
		pthread_cond_wait (&cond, &mutex);
		pthread_mutex_unlock (&mutex);
	}
	pthread_cond_broadcast (&cond);
	num1 = 0;
	num = 0;
	pthread_exit (NULL);
}
