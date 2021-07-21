#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <mqueue.h>

int main ()
{
	int n;
	char buff[20];
		
	int fd = open ("file2.txt", O_APPEND);
	if (fd == -1) {
		printf ("Cannot open \n");
	}
//	lseek (fd, 0, SEEK_END);

	mqd_t mq_desc = mq_open ("/OPEN", O_RDWR); // open queue

	if (mq_desc == -1) {
		printf ("Failed \n");
	} else {
		printf ("Created queue \n");
	}

	n = mq_receive (mq_desc, buff, 20, 0); // reveive from queue

	if (n == -1) {
		printf ("failed to receive \n");
	} else {
		printf ("received \n");
	}
	
	if (write (fd, buff, n) == -1) {
		printf ("Cannot write into file \n");
	} // write received data into file
	close (fd);

	write (1, buff, n);

	if (mq_close (mq_desc) == -1) {
		printf ("failed to close \n");
	} else {
		printf ("Closed \n");
	}
	return 0;
}
