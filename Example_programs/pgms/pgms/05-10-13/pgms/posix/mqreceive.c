#include<stdio.h>
#include<fcntl.h>           /* For O_* constants */
#include<sys/stat.h>        /* For mode constants */
#include<mqueue.h>
#include<string.h>
int main()
{
	mqd_t mq;
	int m;
	char buff[8096];
	mq = mq_open("/test_queue", O_RDONLY);
	m = mq_receive(mq,buff,sizeof(buff),NULL);
	if(m == -1)
		perror("error");
	printf("%d\n",m);
	printf("%s\n",buff);

	return 0;
}
