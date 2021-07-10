#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include "header.h"

int main()
{

	int mqid,mctl,i=5;
	ssize_t mrcv;
	struct msqid_ds info;
	mqid = msgget(KEY,IPC_NOWAIT);
	if(mqid < 0)
	{
		perror("msgget:");
		exit(1);
	}
	printf("mqid is received\n");


	mctl = msgctl(mqid,IPC_STAT,&info);
	if(mctl < 0)
	{
		perror("msgctl:");
		exit(2);
	}
	printf("info receiced\n");

//	struct msgbuf  rec[info.msg_qnum];
	struct msgbuf rec;
	int j = info.msg_qnum;//+1;
	while(j)
	{
	
		
		mrcv = msgrcv(mqid,&rec,sizeof(rec.data),i--,IPC_NOWAIT);
		if(mrcv < 0)
		{	
		perror("msgrcv");
		exit(3);
		}

		printf("data received is %s\n",rec.data);
		j -= 1;	
						
	};

		return 0;

}
