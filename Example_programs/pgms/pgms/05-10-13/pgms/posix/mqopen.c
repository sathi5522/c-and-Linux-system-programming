#include<stdio.h>
#include<fcntl.h>           /* For O_* constants */
#include<sys/stat.h>        /* For mode constants */
#include<mqueue.h>

int main()
{
	mqd_t mq;
	struct mq_attr attr;
	attr.mq_flags = 0;
    	attr.mq_maxmsg = 10;
    	attr.mq_msgsize = 8096;
    	attr.mq_curmsgs = 0;
	mq = mq_open("/test_queue", O_CREAT | O_RDWR, 0644, &attr);
	if(mq == -1)
		perror("error");
	printf("%d\n",mq);

	return 0;
}
