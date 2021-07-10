#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
struct msgbuf{
		long mtype;
		char msg[10];
	};


int main()
{

	struct msgbuf obj = {2,"nagesh"};
	int ret;
	
	ret = msgsnd(98306,&obj,10,IPC_NOWAIT);
	if(ret < 0)
	{
		perror("msgsnd:");
		exit(1);
	}
	else{
		printf("msgbuf is successfully send\n");
	}	
	

	return 0;
}
