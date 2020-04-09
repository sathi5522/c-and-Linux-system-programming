#include <stdio.h> 
#include <fcntl.h>           /* For O_* constants */ 
#include <sys/stat.h>        /* For mode constants */ 
#include <mqueue.h> 
#include <stdlib.h> 
#include <signal.h> 
#include <string.h> 
#include <sys/types.h> 
#include <unistd.h> 

/* Compilation and execution steps
	gcc signal_posix_msq.c -o signal_posix_msq -lrt
	./signal_posix_msq /msq1
	other terminal run 
	./sender /msq1
	other terminal run
	kill -SIGUSR1 signal_posix_msq(pid)
*/

mqd_t mqid; 

void handler(int x) 
{ 

	char msg[7]; 
	int pri;	// = 30; 
	ssize_t mrec; 

	mrec = mq_receive(mqid,msg,8496,&pri); 
	if(mrec < 0) 
	{ 
		perror("mq_receive"); 
		exit(1); 
	} 
	printf("data received is %s\n",msg); 


} 


int main(int argc, char **argv) 
{ 

	int ret; 
	
	if(argc <= 1) {
		printf("Please pass the filename\n");
		return -1;
	}

	signal(SIGUSR1,handler); 
	struct sigevent event; 
	memset(&event,0,sizeof(event)); 
	event.sigev_notify = SIGEV_SIGNAL; 
	event.sigev_signo = SIGUSR1; 

	mqid = mq_open(argv[1],O_RDWR); 
	if(mqid < 0) 
	{ 
		perror("mq_open:"); 
		exit(2); 
	} 

	printf("file opened\n"); 
	 
	ret = mq_notify(mqid,&event); 
	if(ret < 0) 
	{ 
		perror("mq_notify"); 
		exit(3); 
	} 
//	sleep(10); 
	while(1); 
	return 0; 


} 