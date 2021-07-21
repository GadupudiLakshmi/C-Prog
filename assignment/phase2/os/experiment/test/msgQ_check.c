#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>

int main ()
{
	struct mq_attr attr;
	attr.mq_maxmsg = 2;
	attr.mq_msgsize = 20;
	
	mqd_t mq_desc = mq_open ("/OPEN", O_CREAT, 0666, &attr);
	if (mq_desc == -1) {
		printf ("Failed \n");
	} else {
		printf ("Created queue \n");
	}
	if (mq_close (mq_desc) == -1) {
		printf ("failed to close \n");
	} else {
		printf ("Closed \n");
	}
	return 0;
}
