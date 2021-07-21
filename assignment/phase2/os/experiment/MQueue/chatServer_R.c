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
		while (1) {
			if (mq_receive (mq_fd, buff, attr.mq_msgsize, 0)) {
				if (buff[0] == '\n') {
					break;
				}
				printf ("%s \n", buff);
				int n = read (0, buff, attr.mq_msgsize);
				if (mq_send (mq_fd, buff, n, 0)) {
					printf ("Cannot send \n");
				} else {
					printf ("Sent \n");
					if (buff[0] == '\n') {
						break;
					}
				} 
			} else {
				printf ("Cannot get \n");
			}
		}
	}
	if (mq_close (mq_fd)) {
		printf ("Cannot close\n");
	} else {
		printf ("Close \n");
	}
	if (mq_unlink ("/CREAT")) {
		printf ("cannot delete \n");
	} else {
		printf ("Deleted queue \n");
	}
	return 0;
}
