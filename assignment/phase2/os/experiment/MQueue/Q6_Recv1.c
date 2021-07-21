#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <mqueue.h>

int main ()
{
	struct mq_attr attr;
 	mqd_t mq_fd = mq_open ("/CREAT", O_RDWR);
	
	if (mq_fd == -1) {
		printf ("Cannot open \n");
	} else {
		printf ("Opened \n");
	}

	if (mq_getattr (mq_fd, &attr)) {
		printf ("Cannot get \n");
	} else {
		
		char buff [attr.mq_msgsize];
		if (mq_receive (mq_fd, buff, attr.mq_msgsize, 0)) {
			printf ("%s \n", buff);
		} else {
			printf ("Cannot get \n");
		}
	}
	if (mq_close (mq_fd)) {
		printf ("Cannot close\n");
	} else {
		printf ("Close \n");
	}
	return 0;
}
