#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include "header.h"


int main()
{
	int sock_fd;
	struct sockaddr_in server;
	char buff_send[100];
	char buff_recev[100];
	int n;
	int len;
	struct student *st;

	server.sin_family = AF_INET;
	server.sin_port = htons(3000);
	server.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	sock_fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if ( sock_fd == -1 ) {
		printf(" socket creation on client is failed\n");
		exit(1);
	}
	
	connect(sock_fd, (struct sockaddr *)&server, sizeof(server));
	st = (struct student *)malloc(sizeof(struct student));	
//	st->name = (char *)malloc(sizeof(char )*10);
	printf("enter age\n");
	scanf("%d",&st->age);
	 printf("enter empid\n");
        scanf("%d",&st->id);
	__fpurge(stdin);
	printf("enter name");
	fgets(st->name, 10, stdin);
	len = sizeof(server);
	send(sock_fd, st, sizeof(struct student), 0);
	
	n = recv(sock_fd, st, sizeof(struct student),0);
	
	printf("age:%d\n",st->age);
	printf("name:%s\n",st->name);
	printf("id%d",st->id);
//	printf("the response form server :%s\n", buff_recev);
	close(sock_fd);
	
}
