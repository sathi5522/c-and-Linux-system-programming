#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include "header.h"
int main()
{

//	key_t key = 85000;
	
	int ret;
	ret = msgget(KEY,IPC_CREAT);
	if(ret < 0)
	{
		perror("msgget:");
	}

	printf("msgQ identifier : %d",ret);

	return 0;

}



