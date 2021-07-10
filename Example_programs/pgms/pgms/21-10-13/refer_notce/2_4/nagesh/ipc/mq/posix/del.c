#include <stdio.h>
#include <mqueue.h>
#include <stdlib.h>

int main()
{

	int ret;
	ret = mq_unlink("/file2.txt");
	if(ret < 0)
	{
		perror("unlink:");
		exit(1);
	}
	else
	{	
		printf("successfully file is deleted");
		
	}

	return 0;

}

