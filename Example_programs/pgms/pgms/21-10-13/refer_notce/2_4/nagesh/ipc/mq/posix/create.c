#include <stdio.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <mqueue.h>
#include <stdio.h>
#include <stdlib.h>




int main()
{
	struct mq_attr attr;
	mqd_t mqd;
	
	memset(&attr,0,sizeof(attr));
	attr.mq_maxmsg = 10;
	attr.mq_msgsize=50;

	mqd = mq_open("/file2.txt",O_CREAT|O_RDWR,00777,&attr);
	if(mqd < 0)
	{
		perror("mq_open:");
		exit(1);
	}

	else{
		printf("creating is successfully\n descriptor is%d\n",mqd);
		
	}
	
	return 0;

}


