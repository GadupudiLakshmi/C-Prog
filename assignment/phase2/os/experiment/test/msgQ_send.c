#include <stdio.h>
#include <fcntl.h>		//for O_* constants
#include <sys/stat.h>	//for mode constants
#include <mqueue.h>
#include <unistd.h>

#define SIZE 20

int main ()
{
	int n;
	char buff[SIZE];
	struct mq_attr attr;
	
	attr.mq_maxmsg = 5;
	attr.mq_msgsize = 20;
	
	mqd_t mqdes = mq_open ("/OPEN", O_RDWR);
	
	if (mqdes == -1)
		printf("Failed\n");
	else 
		printf("Passed\n");
	
	printf("Enter a value\n");
	n = read(0, buff, SIZE);
	
	if (mq_send (mqdes, buff, n, 0))
		printf("Message queue Failed\n");
	else
		printf("Message loaded to queue\n");

	
	if (mq_close(mqdes) == -1)
		printf(" Not closed\n");
	else
		printf("CLosed\n");
	
	return 0;
}
