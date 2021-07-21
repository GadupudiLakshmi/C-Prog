#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>

#define SHMSEGSIZE sizeof(int)

int main(void){

   pid_t pid;
   int shmID;
   int *shared_mem;
   int n = 5;
   /* initializing shared memory */
   shmID  = shmget(IPC_PRIVATE, SHMSEGSIZE, IPC_CREAT | 0644);
   shared_mem  = (int *)shmat(shmID, 0, 0);
   *shared_mem = 0;

   /* initializing semaphore */
   sem_t sem;
   int pshared = 1; // !=0 for processes, =0 for threads
   int value = 1; // number of processes at a time
   sem_init(&sem, pshared, value); // initialize the semaphore

   pid = fork();

   if(pid>(pid_t)0){ // parent
       sem_wait(&sem);
//		sleep (1);
		while (n) {
       		*shared_mem += 1;
       		printf("P: %d\n", *shared_mem);
		    sleep(1);
			n--;
		}
       sem_post(&sem);
       exit(EXIT_SUCCESS);
   } // parent

   if(pid==(pid_t)0){ // child
       sem_wait(&sem);
//      sleep(1);
		while (n) {
       		*shared_mem += 1;
       		printf("C: %d\n", *shared_mem);
		     sleep(2);
			n--;
		}
       sem_post(&sem);
       exit(EXIT_SUCCESS);
   } // child

   /* fork() failed */
   printf("Failed to fork().");
   exit(EXIT_FAILURE);
}
