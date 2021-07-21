#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <mqueue.h>

int main ()
{
	struct mq_attr attr;
	attr.mq_msgsize = 20;
	attr.mq_maxmsg = 5;
	char buff[attr.mq_msgsize];
	mqd_t mq_fd = mq_open ("/CREAT", O_CREAT | O_RDWR, 0666, &attr);
	if (mq_fd == -1) {
		printf ("Cannot create queue \n");
	} else {
		printf ("Queue created \n");
	}
	
	if (mq_getattr (mq_fd, &attr)) {
		printf (" cannot get \n");
	} 

		int n = read (0, buff, attr.mq_msgsize);
		if (mq_send (mq_fd, buff, n , 1)) {
			printf ("Cannot send \n");
		} else {
			printf ("Sent \n");
		}

		n = read (0, buff, attr.mq_msgsize);
		if (mq_send (mq_fd, buff, n, 2)) {
			printf ("Cannot send \n");
		} else {
			printf ("send\n");
		}
		 
	if (mq_close (mq_fd)) {
		printf ("Cannot close \n");
	} else {
		printf ("Closed \n");
	}
	
	
	
	return 0;
}
	
	
