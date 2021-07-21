#include <stdio.h>
#include <pthread.h>

int i = 0;
int j = 0;
pthread_t T1;
pthread_t T2;
pthread_t T3;
pthread_mutex_t mtx = PTHREAD_MUTEX_INITIALIZER;

void *thread1 (void *p) {
	
	pthread_mutex_lock (&mtx);
	j++;
	i = j;
	printf ("thread1 %d \n", i);
//	printf ("thread1 hai \n");
//	printf ("thread1 hello \n");
//	printf ("thread1 lakshmi \n");
	pthread_mutex_unlock (&mtx);
}
void *thread2 (void *p) {
	
//	pthread_join (T1, NULL);
	pthread_mutex_lock (&mtx);
	i++;
	j = i;
	printf ("thread2 %d \n", j);
//	printf ("thread2 hai \n");
//	printf ("thread2 hello \n");
//	printf ("thread2 Lakshmi \n");
	pthread_mutex_unlock (&mtx);
	
}		
void *thread3 (void *p) {
//	pthread_join (T2, NULL);
	pthread_mutex_lock (&mtx);	
	i++;
	printf ("thread3 %d \n", i);
	pthread_mutex_unlock (&mtx);
}

int main ()
{
	int thread;
//	pthread_t T1;
//	pthread_t T2;
//	pthread_t T3;
	thread = pthread_create (&T1, NULL, thread1, NULL);
	thread = pthread_create (&T2, NULL, thread2, NULL);
	thread = pthread_create (&T3, NULL, thread3, NULL);
	
	if (thread != 0) {
		printf ("thread not created \n");
	} else {
		printf ("created \n");
	}
	pthread_join (T1, NULL);
	pthread_join (T2, NULL);
	pthread_join (T3, NULL);

//	pthread_exit (NULL);
	return 0;
}
