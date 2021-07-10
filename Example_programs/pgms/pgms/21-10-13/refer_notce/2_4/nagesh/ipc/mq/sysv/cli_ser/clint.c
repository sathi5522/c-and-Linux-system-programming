#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include "header.h"
int main()
{

	int ret;
	ssize_t mret;		
	ret = msgget(KEY,IPC_CREAT);
	if(ret < 0)
	{
		perror("msgget:");
		exit(1);

	}
	printf("msgque is opend\n");

//	struct msgbuf mqid = {ret,"get information"};


	
	struct msgbuf data1 = {1,"student1"};
	struct msgbuf data2 = {2,"student2"};
	struct msgbuf data3 = {3,"student3"};
	struct msgbuf data4 = {4,"student4"};
	struct msgbuf data5 = {5,"student5"};

	mret = msgsnd(ret,&data1,sizeof(data1.data),IPC_NOWAIT);	
	if(mret < 0)
	{
		perror("msgsnd1:");
		exit(2);
	}
	printf("data1 is send\n");
	

	mret = msgsnd(ret,&data2,sizeof(data2.data),IPC_NOWAIT);	
	if(mret < 0)
	{
		perror("msgsnd2:");
		exit(3);
	}
	printf("data2 is send\n");
	

	mret = msgsnd(ret,&data3,sizeof(data3.data),IPC_NOWAIT);	
	if(mret < 0)
	{
		perror("msgsnd3:");
		exit(4);
	}
	printf("data3 is send\n");
	

	mret = msgsnd(ret,&data4,sizeof(data4.data),IPC_NOWAIT);	
	if(mret < 0)
	{
		perror("msgsnd4:");
		exit(5);
	}
	printf("data4 is send\n");
	

	mret = msgsnd(ret,&data5,sizeof(data5.data),IPC_NOWAIT);	
	if(mret < 0)
	{
		perror("msgsnd1:");
		exit(6);
	}
	printf("data5 is send\n");
	

	
	return 0;

}
