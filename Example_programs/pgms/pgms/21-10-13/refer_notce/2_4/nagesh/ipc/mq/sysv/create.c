#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>


int main()
{

	int ret;
	key_t key = 85001;
	ret = msgget(key,IPC_CREAT);

	if(ret > 0)
	{
		printf("returns mesque identifier %d\n",ret);
	}

	else
	{
		perror("error in msgget\n");
	}

	return 0;

}


