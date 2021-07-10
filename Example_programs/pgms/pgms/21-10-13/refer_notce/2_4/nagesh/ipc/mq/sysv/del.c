#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main()
{

	int ret;
	ret = msgctl(65538,IPC_RMID,NULL);
	if(ret == 0)
	{
		printf("it is successfully removed\n");
	}
	else{
		perror("msgctl");
	}

	return 0;
}
