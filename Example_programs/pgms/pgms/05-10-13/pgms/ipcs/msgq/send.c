#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>
#define key 2000
typedef struct {
	long type;
	char name[22];
}mm; 
int main()
{
	int q,i;
	mm m1,m2;
	m1.type = 10;
	strcpy(m1.name,"satheesh");
	m2.type = 20;
	strcpy(m2.name,"sathi");
	
	i = msgsnd(163840,&m1,sizeof(m1.name),IPC_NOWAIT);
		perror("send error");
	printf("onsuccess :%d\n",i);
	i = msgsnd(163840,&m2,sizeof(m2.name),IPC_NOWAIT);
		perror("send error");

	printf("onsuccess :%d\n",i);
	return 0;	
}
