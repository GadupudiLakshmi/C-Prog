#include <stdio.h>
#include <fcntl.h>		
#include <sys/stat.h>
#include <mqueue.h>
#include <unistd.h>

#define SIZE 20

int main ()
{
	int n;
	char buff[SIZE];
	struct mq_attr attr;
	char buff1[SIZE];
	char buff2[SIZE];
	
	attr.mq_maxmsg = 5;
	attr.mq_msgsize = 20;
	
	mqd_t mqdes = mq_open ("/OPEN", O_RDWR);
	
	if (mqdes == -1) {
		printf("Failed to open \n");
	}
	else { 
		printf("file opened \n");
	}
	int fd = open ("file.txt", O_RDONLY);
	if (fd == -1) {
		printf ("Cannot open file \n");
	}
	int num  = read (fd, buff, SIZE); // Reading content from file
	lseek (fd, 0, SEEK_SET);
	n = read (fd, buff1, num/2); // moving half of content to buff1
	n = read (fd, buff2, num/2); // another half to buff2
	
	if (mq_send (mqdes, buff1, n, 0)) // sending buff1 into queue with nopriority
		printf("Message queue Failed\n");
	else
		printf("Message loaded to queue\n");
	
	if (mq_send (mqdes, buff2, n, 0)) // sending buff2 into queue with no priority 
		printf ("Message queue Failed \n");
	else 
		printf ("Message loaded to queue \n");	

	close (fd); 
	
	if (mq_close(mqdes) == -1)  // closing queue
		printf(" Not closed\n");
	else
		printf("CLosed\n");
	
	return 0;
}
