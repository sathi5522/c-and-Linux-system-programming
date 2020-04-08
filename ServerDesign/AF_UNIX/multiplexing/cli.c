#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCK_NAME "/tmp/Demosock"
#define BUF_SIZE 128

int main()
{
	struct sockaddr_un addr;
    	int i;
    	int ret;
    	int data_sock;
    	char buf[BUF_SIZE];

	data_sock = socket(AF_UNIX, SOCK_STREAM, 0);

    	if (data_sock == -1) {
        	perror("socket");
        	exit(EXIT_FAILURE);
    	}

	memset(&addr, 0, sizeof(struct sockaddr_un));

	addr.sun_family = AF_UNIX;
    	strncpy(addr.sun_path, SOCK_NAME, sizeof(addr.sun_path) - 1);

    	ret = connect (data_sock, (const struct sockaddr *) &addr,
            sizeof(struct sockaddr_un));

    	if (ret == -1) {
        	fprintf(stderr, "The server is down.\n");
        	exit(EXIT_FAILURE);
    	}

	do{
        	printf("Enter number to send to server :\n");
        	scanf("%d", &i);
        	ret = write(data_sock, &i, sizeof(int));
        	if (ret == -1) {
            		perror("write");
            		break;
        	}
        	printf("No of bytes sent = %d, data sent = %d\n", ret, i);
    	} while(i);


    	memset(buf, 0, BUF_SIZE);
    	strncpy (buf, "RES", strlen("RES"));
    	buf[strlen(buf)] = '\0';
    	printf("buffer = %s\n", buf);

    	ret = write(data_sock, buf, strlen(buf));
    	if (ret == -1) {
        	perror("write");
        	exit(EXIT_FAILURE);
    	}

    	memset(buf, 0, BUF_SIZE);

    	ret = read(data_sock, buf, BUF_SIZE);
    	if (ret == -1) {
        	perror("read");
        	exit(EXIT_FAILURE);
    	}


    	buf[BUF_SIZE - 1] = 0;

    	printf("Result = %s\n", buf);

	close(data_sock);

	return 0;
}
