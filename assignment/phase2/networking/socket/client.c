#include <stdio.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <netdb.h>

#define MAX 100
int main ()
{
	int fd;
	int new_fd;
	char buff[MAX];
	memset (buff, '\0', sizeof (buff));

	struct sockaddr_in server_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons (4550);
	server_addr.sin_addr.s_addr = inet_addr ("192.168.0.107");
	
	fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == -1) {
		printf ("cannot open socket \n");
	}
	
	connect (fd, (struct sockaddr*) &server_addr, sizeof (server_addr));
	
	while (1) {
		memset (buff, '\0', sizeof (buff));
		fgets (buff, MAX, stdin);		
		int n = write (fd, buff, sizeof (buff));
		printf ("Send success \n");	
		memset (buff, '\0', sizeof (buff));
		n = read (fd, buff, sizeof (buff));
		printf ("Received from Server :%s \n", buff);
	}
	close (fd);
}
