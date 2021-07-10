#include<stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>

int main()
{
        key_t key = 3000;
        int q;
        q = msgget(key,IPC_CREAT);

        if(q == -1)
                perror("errno ");

        printf("on success :%d\n",q);

        return 0;
}

