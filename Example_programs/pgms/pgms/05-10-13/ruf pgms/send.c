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
	m1.no = 10;
	strcpy(m1.buf,"thakur");
	strcpy(m2.buf,"chetan");
	m2.no = 20;
/*	for(i = 65; i<75;i++)
	{
		m1.buf[i] = i;
	}
	
	for(i = 97; i<100;i++)
        {
                m2.buf[i] = i;
        }*/
	ret = msgsnd(qid,&m1,sizeof(m1),IPC_NOWAIT);
	ret = msgsnd(qid,&m2,sizeof(m2),IPC_NOWAIT);
	
	if(!ret)
	{
		perror("msgsnd");
		exit(1);
	}
	printf("msg send successfull:\n");
	return 0;
}

