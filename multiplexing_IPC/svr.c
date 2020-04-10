#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <sys/un.h>
#include <unistd.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <errno.h>

#define SOCK_NAME_UN "/tmp/Demosock_un"
#define BUF_SIZE 128
#define PORT 8000
#define MAX_CLIENT_SUPPORTED    32

#define MAX_MESSAGES 10
#define MAX_MSG_SIZE 256
#define MSG_BUFFER_SIZE     (MAX_MSG_SIZE + 10)
#define QUEUE_PERMISSIONS   0660

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


int main(int argc, char *argv[])
{
	struct sockaddr_un addr_un;
	struct sockaddr_in addr_nw;
	int con_sock_un, con_sock_nw;
	int ret,ret_un,ret_nw;
	int data_sock_un, data_sock_nw;
	int result_un, result_nw;
	char buf[BUF_SIZE];
	int data;
	fd_set readfds;
	int comm_socket_fd,i;
	int msgq_fd = 0;
	char buffer[MSG_BUFFER_SIZE];

	if(argc <= 1){
        	printf("provide a reciepient msgQ name : format </msgq-name>\n");
        	return 0;
    	}

	intitiaze_monitor_fd_set();
	add_to_monitored_fd_set(0);

	unlink(SOCK_NAME_UN);

	con_sock_un = socket(AF_UNIX,SOCK_STREAM,0);

	if (con_sock_un == -1) {
		perror("socket_un");
		exit(EXIT_FAILURE);
	}

	printf("Master Unix socket created\n");

	con_sock_nw = socket(AF_INET,SOCK_STREAM,0);

	if (con_sock_nw == -1) {
		perror("socket_un");
		exit(EXIT_FAILURE);
	}

	printf("Master Network socket created\n");

	memset(&addr_un, 0, sizeof(struct sockaddr_un));

	addr_un.sun_family = AF_UNIX;
	memcpy(addr_un.sun_path, SOCK_NAME_UN, strlen(SOCK_NAME_UN));

	ret_un = bind(con_sock_un, (const struct sockaddr *) &addr_un, sizeof(struct sockaddr_un));

	if (ret_un == -1) {
		perror("bind_un");
		exit(EXIT_FAILURE);
	}

	printf("bind Unix call succeed\n");

	memset(&addr_nw, 0, sizeof(struct sockaddr_in));

	addr_nw.sin_family = AF_INET;
	addr_nw.sin_addr.s_addr = htonl(INADDR_ANY);
	addr_nw.sin_port = htons(PORT);

	ret_nw = bind(con_sock_nw, (const struct sockaddr *) &addr_nw, sizeof(struct sockaddr_in));

	if (ret_nw == -1) {
		perror("bind_nw");
		exit(EXIT_FAILURE);
	}

	printf("bind Network call succeed\n");

	ret_un = listen(con_sock_un, 10);

	if (ret_un == -1) {
		perror("listen_un");
		exit(EXIT_FAILURE);
	}

	ret_nw = listen(con_sock_nw, 10);

	if (ret_nw == -1) {
		perror("listen_nw");
		exit(EXIT_FAILURE);
	}

	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_maxmsg = MAX_MESSAGES;
	attr.mq_msgsize = MAX_MSG_SIZE;
	attr.mq_curmsgs = 0;

	if ((msgq_fd  = mq_open (argv[1], O_RDONLY | O_CREAT, QUEUE_PERMISSIONS, &attr)) == -1) {
		printf ("Client: mq_open failed, errno = %d", errno);
		exit (1);
	}

	/*Add master socket to Monitored set of FDs*/
	add_to_monitored_fd_set(con_sock_un);
	add_to_monitored_fd_set(con_sock_nw);
	add_to_monitored_fd_set(msgq_fd);

	for(;;) {
		refresh_fd_set(&readfds); /*Copy the entire monitored FDs to readfds*/
		printf(" Waiting on accept() call\n");

		/* Call the select system call, server process blocks here. 
		 * Linux OS keeps this process blocked untill the connection initiation request Or 
		 * data requests arrives on any of the file Drscriptors in the 'readfds' set*/

		select(get_max_fd() + 1, &readfds, NULL, NULL, NULL);
		if(FD_ISSET(con_sock_un, &readfds)){
			data_sock_un = accept(con_sock_un, NULL, NULL);

			if (data_sock_un == -1) {
				perror("accept");
				exit(EXIT_FAILURE);
			}

			printf("Unix Connection accepted from client\n");
			add_to_monitored_fd_set(data_sock_un);
		}
		else if(FD_ISSET(con_sock_nw, &readfds)){
			data_sock_nw = accept(con_sock_nw, NULL, NULL);

			if (data_sock_nw == -1) {
				perror("accept_nw");
				exit(EXIT_FAILURE);
			}

			printf("Network Connection accepted from client\n");
			add_to_monitored_fd_set(data_sock_nw);
		}
		else if(FD_ISSET(msgq_fd, &readfds)){
			printf("Msg recvd msgQ %s\n", argv[1]);

			memset(buffer, 0, MSG_BUFFER_SIZE);
			if (mq_receive (msgq_fd, buffer, MSG_BUFFER_SIZE, NULL) == -1) {
				printf ("mq_receive error, errno = %d\n", errno);
				exit (1);
			}
			printf("Msg recieved from Queue = %s\n", buffer);
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
	close(con_sock_un);
	close(con_sock_nw);
	remove_from_monitored_fd_set(con_sock_un);
	remove_from_monitored_fd_set(con_sock_nw);
	printf("connection closed..\n");

	unlink(SOCK_NAME_UN);
	return 0;
}
