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
	int new_fd;
	int client;
	char buff[MAX];
	memset (buff, '\0', sizeof (buff));

	struct sockaddr_in server_addr;
	struct sockaddr_in client_addr;

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons (4550);
	server_addr.sin_addr.s_addr = inet_addr ("192.168.0.105");
	
	fd = socket (AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (fd == -1) {
		printf ("Cannot open socket \n");
	}
	
	int n = bind (fd, (struct sockaddr*) &server_addr, sizeof (server_addr));
	if (n == -1) {
		printf ("assigning address to socket failed \n");
	}

	n = listen (fd, 5);
	if (n == -1) {
		printf ("Listen failed \n");
	}

	client = sizeof (client_addr);

	memset (buff, '\0', sizeof (buff));
	new_fd = accept (fd, (struct sockaddr*) &client_addr, &client);	
	if (new_fd == -1) {
		printf ("cannot open \n");
	}
	while (1) {
		memset (buff, '\0', sizeof (buff));
		n = read (new_fd, buff, sizeof (buff));
		if (read > 0) {
			printf ("received From client : %s \n", buff);
		}
		memset (buff, '\0', sizeof (buff));
		fgets (buff, MAX, stdin);
		n = write (new_fd, buff, sizeof (buff));
		if (n > 0) {
			printf ("Send Success \n");
		}
	}
	close (new_fd);	
	close (fd);
}
