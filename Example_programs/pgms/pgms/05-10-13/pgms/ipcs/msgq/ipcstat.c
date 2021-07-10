#include<stdio.h>
#include<sys/types.h>
#include<sys/ipc.h>
#include<sys/msg.h>

int main()
{
        int q;
	struct msqid_ds buf;
        q =  msgctl(163840,IPC_STAT,&buf);
        if(q == -1)
                perror("error");

        printf("on success :%d\n",q);
	printf("current no of bytes in queue:%ld\n",buf.__msg_cbytes);
	printf("current no of msgs in queue:%d\n",buf.msg_qnum);

        return 0;
}

