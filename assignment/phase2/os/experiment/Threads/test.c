#include <stdio.h>
#include <pthread.h>

void *thread1 (void *p) {
	printf ("thread \n");
//	printf ("%s", p);
	return (int *) p;
}
void *thread2 (void *p) {
	printf ("thread2 \n");
	return (int *) p;
}		
void *thread3 (void *p) {
	printf ("thread3 \n");
	return (int *) p;
}

int main ()
{
	int thread;
	pthread_t T1;
	pthread_t T2;
	pthread_t T3;
	thread = pthread_create (&T1, NULL, thread1, 1);
	thread = pthread_create (&T2, NULL, thread2, 2);
	thread = pthread_create (&T3, NULL, thread3, 3);
	
	if (thread != 0) {
		printf ("thread not created \n");
	} else {
		printf ("created \n");
	}
	
	void *res;
	pthread_join (T1, &res);
	printf ("%d \n", (int*) res);
	pthread_join (T2, &res);
	printf ("%d \n", (int*) res);
	pthread_join (T3, &res);
	printf ("%d \n", (int*) res);
	pthread_exit (NULL);
	return 0;
}
