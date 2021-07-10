#include <stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>


	mqd_t mqid;

void * threadfun(void *p)
{
	char msg[7];
	
	ssize_t mrec;
	int pri = 30;
	mrec = mq_receive(mqid,msg,8496,&pri);
	if(mrec < 0)
	{
		perror("mq_receive");
	}	
	printf("data is %s\n",msg);



}

int main()
{
	int ret;
	pthread_t t1;
	mqid = mq_open("/file2.txt",O_RDWR);
	if(mqid < 0)
	{
		perror("mq_open:");
		exit(1);
	}
	printf("file opend sucessfully\n");
	


	struct sigevent  info;
	memset(&info,0,sizeof(info));

	
	info.sigev_notify = SIGEV_THREAD;
	info.sigev_notify_function = threadfun;
//	info.sigev_notify_attributes = NULL;
	
	ret = mq_notify(mqid,&info);
	if(ret < 0)
	{
		perror("mq_notify");
	}
	
	ret = pthread_create(&t1,NULL,threadfun,NULL);
	if(ret != 0)
	{
		perror("pthread_creat");
		exit(3);
	}
	
	//sleep(10);
	pthread_join(t1,NULL);
	return 0;


}
