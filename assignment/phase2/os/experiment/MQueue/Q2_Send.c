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
	
		int fd = open ("file.txt", O_RDONLY);
 		if (fd == -1) {
			printf ("Cannot open \n");
		} else {
			int num = read (fd, buff, 100);
			lseek (fd, 0, SEEK_SET);
			char buff1[num/2];
			int n = read (fd, buff1, num/2);

			if (mq_send (mq_fd, buff1, n , 0)) {
				printf ("Cannot send \n");
			} else {
				printf ("Sent \n");
			} 

			n = read (fd, buff1, num/2);
			write (1, buff1, n);
			if (mq_send (mq_fd, buff1, n, 0)) {
				printf ("Cannot send \n");
			} else {
				printf ("Sent \n");
			}
	
			if (mq_close (mq_fd)) {
				printf ("Cannot close \n");
			} else {
				printf ("Closed \n");
			}
	
		}
	}
	
	return 0;
}
	
	
