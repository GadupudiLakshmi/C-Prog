#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <unistd.h>
#include "header.h"

/*struct student{
	int age;
	char *name;
	int emp_id;
};*/
int main()
{
	int sock_fd;
	struct sockaddr_in server, client;
	int new_fd;
	char buff_send[100];
	char buff_receive[100];
	int len;
	int n;
	struct student st;

	server.sin_family = AF_INET;
	server.sin_port = htons(3000);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	sock_fd = socket( AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if ( sock_fd == -1 ) {
		printf(" socket creation failed\n");
		exit(1);
	}
	

	bind(sock_fd, (struct sockaddr *)&server, sizeof(server));
	
	listen(sock_fd, 5);
	
	len = sizeof(client);

	new_fd = accept(sock_fd, (struct sockaddr *)&client, &len);
		
	if ( new_fd == -1 ) {
		printf(" connection establishement failed\n");
		exit(1);
	} else {
		printf(" connetion established\n");
	}
	n = recv( new_fd, &st, sizeof(st),0);

	printf("%d\n",st.age);
	printf("%s\n",st.name);
	printf("%d\n",st.id);
//	__fpurge(stdin);
	printf("enter the age:");
	scanf("%d",&st.age);
	printf("enter the id:");
	scanf("%d",&st.id);
	__fpurge(stdin);
	printf("enter name:");
	fgets(st.name, 10, stdin);
	send(new_fd, &st, sizeof(st), 0);
	close(new_fd);
	close(sock_fd);
	return 0;
}
