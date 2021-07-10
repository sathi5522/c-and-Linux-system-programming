#include<stdio.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <mqueue.h>

int main()
{
	int mq;
	mq = mq_unlink("/test_queue");
	if(mq == -1)
		perror("error");
	printf("%d\n",mq);

	return 0;
}
