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
	int ret;
	struct msgbuf obj;

	ret = msgrcv(98306,&obj,10,2,IPC_NOWAIT);
	if(ret < 0)
	{
		perror("msgrcv:");
		exit(1);
	}		
	else
	{
		printf("msg received successfully\n");
	}	

		
	printf("%s\n",obj.msg);
	
	return 0;


}
