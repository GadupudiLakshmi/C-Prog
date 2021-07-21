#include <stdio.h>
#include <pthread.h>

unsigned long int value = 0;
//int status = 0;
pthread_mutex_t mut = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;

void *even()
{
	int even_init = 0;
	while( even_init < 5 ) {
		pthread_mutex_lock(&mut);
		if ( (value % 2) == 0 ) {
			printf("even value is %ld\n", value);
//			pthread_cond_broadcast(&cond);
		}
		pthread_mutex_unlock(&mut); 
		even_init++;
		pthread_cond_broadcast(&cond);
		pthread_cond_wait(&cond, &mut);
	}
}

void *odd()
{
	int odd_init = 0;
	while ( odd_init < 5) {
		pthread_mutex_lock(&mut);
		if ( (value % 2) != 0 ) {
			printf("odd value is %ld\n", value);
			pthread_cond_broadcast(&cond);
		} 
		pthread_mutex_unlock(&mut);
		odd_init++;
		pthread_cond_wait(&cond, &mut);
	}
}

void *random1()
{
	int init = 0;
	while ( init < 5 ) {
		pthread_mutex_lock(&mut);
		value = random();
		pthread_cond_broadcast(&cond);
		pthread_cond_wait(&cond, &mut);
		init++;
		pthread_cond_broadcast(&cond);
		pthread_mutex_unlock(&mut);
	}
	value = 0;
}
			
int main()
{
	pthread_t pid1;
	pthread_t pid2;
	pthread_t pid3;

	int pid_1;
	int pid_2;
	int pid_3;
	
	pid_1 = pthread_create(&pid1, NULL, random1, NULL);
	pid_2 = pthread_create(&pid2, NULL, even, NULL);
	pid_3 = pthread_create(&pid3, NULL, odd, NULL);
	
	pthread_exit(NULL);
