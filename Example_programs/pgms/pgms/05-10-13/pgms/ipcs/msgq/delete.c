#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
	int q;
	q=msgget(2000,IPC_CREAT);
		perror("error");
	q =  msgctl(q,IPC_RMID,NULL);
	if(q == -1)
		perror("error");

	printf("on success :%d\n",q);

	return 0;	
}
