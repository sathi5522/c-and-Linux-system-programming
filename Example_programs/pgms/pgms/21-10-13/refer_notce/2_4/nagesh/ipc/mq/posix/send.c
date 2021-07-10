#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>
#include <string.h>
int main()
{

	int ret;
	mqd_t mqd;
	char msg[] = "nagesh";
	mqd = mq_open("/file2.txt",O_RDWR);
	if(mqd < 0)
	{
		perror("mq_open:");
		exit(1);
	
	}
	else{
		printf("mqd =%d\n",mqd);
	}
	ret = mq_send(mqd,msg,strlen(msg),20);
	
	if(ret < 0)
	{
		perror("mq_send");
		exit(2);
	}

	printf("data successfulley send\n");
	
	



	return 0;
}
