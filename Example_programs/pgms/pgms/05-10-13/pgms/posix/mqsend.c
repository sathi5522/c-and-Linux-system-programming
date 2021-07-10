#include<stdio.h>
#include<fcntl.h>           /* For O_* constants */
#include<sys/stat.h>        /* For mode constants */
#include<mqueue.h>
#include<string.h>
int main()
{
	mqd_t mq;
	int m;
	char buf[30] = "hello world";
	mq = mq_open("/test_queue", O_WRONLY);
	m = mq_send(mq,buf,strlen(buf),0);
	if(m == -1)
		perror("error");
	printf("%d\n",m);

	return 0;
}
