#include <stdio.h> 
#include <fcntl.h>           /* For O_* constants */ 
#include <sys/stat.h>        /* For mode constants */ 
#include <mqueue.h> 
#include <stdlib.h> 
#include <string.h> 
#include <pthread.h>

/* compilation and execution steps
	gcc thread_posix_msq.c -o thread_posix_msq -lrt -lpthread
	./thread_posix_msq /msq1
	other terminal
	./sender /mq1
*/

mqd_t mqid; 

void *threadfun(void *p) 
{
	printf("threadfun created\n"); 
	char msg[256]; 

	ssize_t mrec; 
	int pri = ((union sigval *)p)->sival_int; 
	mrec = mq_receive(mqid,msg,8496,&pri); 
	if(mrec < 0) 
	{ 
		perror("mq_receive"); 
	}	 
	printf("data is %s\n",msg); 

	pthread_exit(NULL); 

} 

int main(int argc, char *argv[]) 
{ 
	int ret; 

	pthread_t t1; 

	if(argc <= 1) {
		printf("Please pass the filename\n");
		return -1;
	}

	/*To set msgQ attributes*/
	struct mq_attr attr;
	attr.mq_flags = 0;
	attr.mq_maxmsg = 10;
	attr.mq_msgsize = 4096;
	attr.mq_curmsgs = 0;

	if ((mqid  = mq_open (argv[1], O_RDONLY | O_CREAT, 0660, &attr)) == -1) {
		printf ("Client: mq_open failed");
		exit (1);
	}


	/*mqid = mq_open(argv[1],O_RDWR); 
	  if(mqid < 0) 
	  { 
	  perror("mq_open:"); 
	  exit(1); 
	  } */
	printf("file opend sucessfully\n"); 



	struct sigevent  info; 
	memset(&info,0,sizeof(info)); 


	info.sigev_notify = SIGEV_THREAD; 
	info.sigev_value.sival_int = 30; 
	info.sigev_notify_function = (void *)threadfun; 
	//	info.sigev_notify_attributes = NULL; 

	ret = mq_notify(mqid,&info); 
	if(ret < 0) 
	{ 
		perror("mq_notify"); 
		exit(2); 
	} 

	ret = pthread_create(&t1,NULL,threadfun,&(info.sigev_value)); 
	if(ret != 0) 
	{ 
		perror("pthread_creat"); 
		exit(3); 
	} 

	//sleep(10); 
	pthread_join(t1,NULL);
	mq_close(mqid); 
	return 0; 


} 

