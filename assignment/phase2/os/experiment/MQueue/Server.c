#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <mqueue.h>
#include "struct.h"
int main ()
{
	struct student st;
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

	printf ("enter name \n");
	fgets (st.name, 10, stdin);
	printf ("enter number \n");
	scanf ("%d", &st.id);
	printf ("enter marks \n");
	scanf ("%d", &st.marks);
	

	while (1) {
	
//		int n = read (0, buff, attr.mq_msgsize);
		if (mq_send (mq_fd, &st, sizeof (st) , 0)) {
			printf ("Cannot send \n");
		} else {
			printf ("Sent \n");
			if (buff[0] == '\n') {
				break;
			}
			char buff1[attr.mq_msgsize];
			if (mq_receive (mq_fd, buff1, attr.mq_msgsize, 0)) {
			if (buff1[0] == '\n') {
				break;
			} 
			printf ("%s \n", buff1);
		} else {
			printf ("cannot get\n");
		}
		}
		 
	}
	if (mq_close (mq_fd)) {
		printf ("Cannot close \n");
	} else {
		printf ("Closed \n");
	}
	
	
	
	return 0;
}
	
	
