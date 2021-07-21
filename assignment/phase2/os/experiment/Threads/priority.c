#include <stdio.h>
#include <pthread.h>


pthread_attr_t attr1;
pthread_attr_t attr2;
pthread_attr_t attr3;

struct sched_param param;
void *thread1 (void *P) {
	if (pthread_attr_getschedparam (&attr1, &param) == 0) {
		printf ("thread1-%d \n", param.sched_priority);
	}
//	for (int i = 0; i < 20; i++) {
		printf ("T1 \n");
//	}
} 

void *thread2 (void *p) {
	if (pthread_attr_getschedparam (&attr2, &param) == 0) {
		printf ("thread2-%d \n", param.sched_priority);
	}
//	for (int i = 0; i < 20; i++) {
		printf ("T2 \n");
//	}
}

void *thread3 (void *p) {
	if (pthread_attr_getschedparam (&attr3, &param) == 0) {
		printf ("thread3-%d \n", param.sched_priority);
	}
//	for (int i = 0; i < 20; i++) {
		printf ("T3 \n");
//	}
}

int main ()
{
	int th;
	pthread_t T1;
	pthread_t T2;
	pthread_t T3;	

	// thread1
	pthread_attr_init (&attr1);
	int check = pthread_attr_setschedpolicy (&attr1, SCHED_FIFO);
	if (check == 0) {
		printf ("success \n");
	}
	param.sched_priority = 3;
	check = pthread_attr_setschedparam (&attr1, &param);
	if (check == 0) {
		printf ("success \n");
	}
		
	check = pthread_attr_setinheritsched (&attr1, PTHREAD_EXPLICIT_SCHED);
	if (check == 0) {
		printf ("success \n");
	}

	// creating thread1
	th = pthread_create (&T1, &attr1, thread1, NULL);
	if (th) {
		printf ("thread creation failed \n");
	}

	// thread2
	pthread_attr_init (&attr2);
	check = pthread_attr_setschedpolicy (&attr2, SCHED_FIFO);
	if (check == 0) {
		printf ("success \n");
	}
	param.sched_priority = 2;
	check = pthread_attr_setschedparam (&attr2, &param);
	if (check == 0) {
		printf ("success \n");
	}
		
	check = pthread_attr_setinheritsched (&attr2, PTHREAD_EXPLICIT_SCHED);
	if (check == 0) {
		printf ("success \n");
	}

	// creating thread2
	th = pthread_create (&T2, &attr2, thread2, NULL);
	if (th) {
		printf ("thread creation failed \n");
	}
	
	// thread3
	pthread_attr_init (&attr3);
	check = pthread_attr_setschedpolicy (&attr3, SCHED_FIFO);
	if (check == 0) {
		printf ("success \n");
	}
	param.sched_priority = 1;
	check = pthread_attr_setschedparam (&attr3, &param);
	if (check == 0) {
		printf ("success \n");
	}
		
	check = pthread_attr_setinheritsched (&attr3, PTHREAD_EXPLICIT_SCHED);
	if (check == 0) {
		printf ("success \n");
	}
	// creating thread3
	th = pthread_create (&T3, &attr3, thread3, NULL);
	if (th) {
		printf ("thread creation failed \n");
	}


	pthread_exit (NULL);
}
