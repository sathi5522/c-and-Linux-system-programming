#include<stdio.h>
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
	int con_sock;
	int ret;
	int data_sock;
	int result;
	char buf[BUF_SIZE];
	int data;

	unlink(SOCK_NAME);

	con_sock = socket(AF_UNIX,SOCK_STREAM,0);

	if (con_sock == -1) {
		perror("socket");
		exit(EXIT_FAILURE);
	}

	printf("Master socket created\n");
	
	memset(&addr, 0, sizeof(struct sockaddr_un));

	addr.sun_family = AF_UNIX;
	memcpy(addr.sun_path, SOCK_NAME, strlen(SOCK_NAME));
	
	ret = bind(con_sock, (const struct sockaddr *) &addr, sizeof(struct sockaddr_un));
	
	if (ret == -1) {
		perror("bind");
		exit(EXIT_FAILURE);
	}

	printf("bind call succeed\n");

	ret = listen(con_sock, 20);

	if (ret == -1) {
		perror("listen");
		exit(EXIT_FAILURE);
	}

	for(;;) {
		printf(" Waiting on accept() call\n");
		
		data_sock = accept(con_sock, NULL, NULL);

		if (data_sock == -1) {
			perror("accept");
			exit(EXIT_FAILURE);
		}

		printf("Connection accepted from client\n");

		result = 0;
		for(;;) {
			memset(buf, 0, BUF_SIZE);
			printf("Waiting for data from the client\n");
			ret = read(data_sock, buf, BUF_SIZE);

            		if (ret == -1) {
                		perror("read");
                		exit(EXIT_FAILURE);
            		}
			memcpy(&data, buf, sizeof(int));
            		if(data == 0) 
				break;
            		result += data;
		}
		memset(buf, 0, BUF_SIZE);
        	sprintf(buf, "Result = %d", result);

        	printf("sending final result back to client\n");
        	ret = write(data_sock, buf, BUF_SIZE);

        	if (ret == -1) {
            		perror("write");
            		exit(EXIT_FAILURE);
        	}
		close(data_sock);
	}
	close(con_sock);
    	printf("connection closed..\n");

	unlink(SOCK_NAME);
	return 0;
}
