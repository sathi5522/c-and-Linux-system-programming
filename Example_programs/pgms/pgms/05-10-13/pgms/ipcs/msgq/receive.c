#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>
#include<string.h>

typedef struct {
	long type;
	char name[22];
}mm; 
int main()
{
	int q,i;
	mm m1,m2;
	
	i = msgrcv(163840,&m1,sizeof(m1.name),0,IPC_NOWAIT);
	printf("%s\n",m1.name);
	 i = msgrcv(163840,&m2,sizeof(m2.name),0,IPC_NOWAIT);
	printf("%s\n",m2.name);

	return 0;	
}
