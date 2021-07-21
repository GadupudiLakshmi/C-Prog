#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/stat.h>
#include <mqueue.h>

int main ()
{
	pid_t pid;
	pid = fork ();
	struct mq_attr attr;
    attr.mq_msgsize = 100;
    attr.mq_maxmsg = 5;
    char buff[attr.mq_msgsize];
    mqd_t mq_fd = mq_open ("/CREAT", O_CREAT | O_RDWR, 0666, &attr    );
	if (mq_fd == -1) {
 		 printf ("Cannot create queue \n");
    } else {
         printf ("Queue created \n");
	}
	if (pid > 0) {
		printf ("Parent process \n");
        int fd = open ("file.txt", O_RDONLY);
        if (fd == -1) {
            printf ("Cannot open \n");
        } else {
            int num = read (fd, buff, 100);
			if (mq_send (mq_fd, buff, num , 0)) {
                 printf ("Cannot send \n");
             } else {
                 printf ("Sent \n");
             }
		}
		wait (NULL);
	} else if (pid == 0) {
		printf ("Child process \n");
		int fd = open ("output.txt", O_CREAT | O_RDWR, 0666);
        if (fd == -1) {
            printf ("cannot create \n");
        } else {
            char buff [attr.mq_msgsize];
            int n = mq_receive (mq_fd, buff, attr.mq_msgsize, 0);
            printf ("%s \n", buff);
            n = write (fd, buff, n);
            if (n == -1) {
                printf ("cannot write \n");
            } else {
                printf ("write success \n");
            }
		}
	} else {
		printf ("no child \n");
	}
	
	return 0;
}
