#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include<string.h>
#define key 1010

typedef struct{
	long no;
	char buf[100];		
}msg;


int main()

{
	int ret,qid,i;
	qid = msgget(key,IPC_CREAT);
	msg m1,m2;
	ret = msgrcv(qid,&m1,sizeof(m1),10,IPC_NOWAIT);
	printf("%s\n",m1.buf);
	ret = msgrcv(qid,&m2,sizeof(m2),20,IPC_NOWAIT);
        printf("%s\n",m2.buf);

	if(!ret)
	{
		perror("msgrcv");
		exit(1);
	}
	printf("msg rcv successfull:\n");
	return 0;
}

