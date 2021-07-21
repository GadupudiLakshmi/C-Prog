#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>

#define MAX 100
int main ()
{
	int fd;
	int n;
	char buff[MAX];
	memset (buff, '\0', sizeof (buff));
	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;
	
	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons (4545);
	server_addr.sin_addr.s_addr = inet_addr ("192.168.0.105");

	fd = socket (AF_INET, SOCK_DGRAM, IPPROTO_UDP);
	if (fd == -1) {
		printf ("Socket not created \n");
	} else {	
		memset (buff, '\0', sizeof (buff));
		fgets (buff, MAX, stdin);
		n = sendto (fd, buff, sizeof (buff), MSG_CONFIRM, (struct sockaddr*) &server_addr, sizeof (server_addr));
		if (n > 0) {
			printf ("Send success \n");
		}
		int server = sizeof (server_addr);
		n = recvfrom (fd, buff, sizeof (buff), MSG_CMSG_CLOEXEC, (struct sockaddr*) &server_addr, &server);
		if (n > 0) {
			printf ("received %s \n", buff);
		}
	}
	close (fd);
	return 0;
}
	
