#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>

#define SOCK_NAME "/tmp/Demosock"
#define BUF_SIZE 128

#define MAX_CLIENT_SUPPORTED    32

/*An array of File descriptors which the server process
 * is maintaining in order to talk with the connected clients.
 * Master skt FD is also a member of this array*/
int monitored_fd_set[MAX_CLIENT_SUPPORTED];

/*Each connected client's intermediate result is 
 * maintained in this client array.*/
int client_result[MAX_CLIENT_SUPPORTED] = {0};

/*Remove all the FDs, if any, from the the array*/
static void
intitiaze_monitor_fd_set(){

	int i = 0;
	for(; i < MAX_CLIENT_SUPPORTED; i++)
		monitored_fd_set[i] = -1;
}

/*Add a new FD to the monitored_fd_set array*/
static void
add_to_monitored_fd_set(int skt_fd){

	int i = 0;
	for(; i < MAX_CLIENT_SUPPORTED; i++){

		if(monitored_fd_set[i] != -1)
			continue;
		monitored_fd_set[i] = skt_fd;
		break;
	}
}

/*Remove the FD from monitored_fd_set array*/
static void
remove_from_monitored_fd_set(int skt_fd){

	int i = 0;
	for(; i < MAX_CLIENT_SUPPORTED; i++){

		if(monitored_fd_set[i] != skt_fd)
			continue;

		monitored_fd_set[i] = -1;
		break;
	}
}

/* Clone all the FDs in monitored_fd_set array into 
 * fd_set Data structure*/
static void
refresh_fd_set(fd_set *fd_set_ptr){

	FD_ZERO(fd_set_ptr);
	int i = 0;
	for(; i < MAX_CLIENT_SUPPORTED; i++){
		if(monitored_fd_set[i] != -1){
			FD_SET(monitored_fd_set[i], fd_set_ptr);
		}
	}
}

/*Get the numerical max value among all FDs which server
 * is monitoring*/

static int
get_max_fd(){

	int i = 0;
	int max = -1;

	for(; i < MAX_CLIENT_SUPPORTED; i++){
		if(monitored_fd_set[i] > max)
			max = monitored_fd_set[i];
	}

	return max;
}


int main()
{
	struct sockaddr_un addr;
	int con_sock;
	int ret;
	int data_sock;
	int result;
	char buf[BUF_SIZE];
	int data;
	fd_set readfds;
	int comm_socket_fd, i;
	intitiaze_monitor_fd_set();
	add_to_monitored_fd_set(0);

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

	/*Add master socket to Monitored set of FDs*/
	add_to_monitored_fd_set(con_sock);

	for(;;) {
		refresh_fd_set(&readfds); /*Copy the entire monitored FDs to readfds*/
		printf(" Waiting on accept() call\n");

		/* Call the select system call, server process blocks here. 
		 * Linux OS keeps this process blocked untill the connection initiation request Or 
		 * data requests arrives on any of the file Drscriptors in the 'readfds' set*/

		select(get_max_fd() + 1, &readfds, NULL, NULL, NULL);
		if(FD_ISSET(con_sock, &readfds)){
			data_sock = accept(con_sock, NULL, NULL);

			if (data_sock == -1) {
				perror("accept");
				exit(EXIT_FAILURE);
			}

			printf("Connection accepted from client\n");
			add_to_monitored_fd_set(data_sock);
		}
		else {
			i = 0, comm_socket_fd = -1;
			for(; i < MAX_CLIENT_SUPPORTED; i++){

				if(FD_ISSET(monitored_fd_set[i], &readfds)){
					comm_socket_fd = monitored_fd_set[i];

					memset(buf, 0, BUF_SIZE);
					printf("Waiting for data from the client\n");
					ret = read(comm_socket_fd, buf, BUF_SIZE);

					if (ret == -1) {
						perror("read");
						exit(EXIT_FAILURE);
					}
					memcpy(&data, buf, sizeof(int));
					if(data == 0) {
						/* Send result. */
						memset(buf, 0, BUF_SIZE);
						sprintf(buf, "Result = %d", client_result[i]);

						printf("sending final result back to client\n");
						ret = write(comm_socket_fd, buf, BUF_SIZE);
						if (ret == -1) {
							perror("write");
							exit(EXIT_FAILURE);
						}

						/* Close socket. */
						close(comm_socket_fd);
						client_result[i] = 0;
						remove_from_monitored_fd_set(comm_socket_fd);
						continue; /*go to select() and block*/
					}
					client_result[i] += data;
				}
			}
		}
	}
	close(con_sock);
	remove_from_monitored_fd_set(con_sock);
	printf("connection closed..\n");

	unlink(SOCK_NAME);
	return 0;
}
