#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	int ret,pri = 20;
	mqd_t mqd;
	char msg[7];
	struct mq_attr attr;

	mqd = mq_open("/file2.txt",O_RDWR);
	if(mqd < 0)
	{
		perror("mq_open:");
		exit(1);
	
	}
	printf("mqd =%d\n",mqd);

	mq_getattr(mqd, &attr);
	printf("%u\n", attr.mq_maxmsg);

	ret = mq_receive(mqd,msg,8496,&pri);
	
	if(ret < 0)
	{
		perror("mq_receive");
		exit(2);
	}
	else{
		printf("data receivedfulley send\n");
	
	}

	ret = close(mqd);
	if(ret < 0)
	{
		perror("close :");
		exit(3);
	}
	
	printf("closed successfully\n");

	return 0;
}
