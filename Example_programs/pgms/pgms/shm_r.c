#include <stdio.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <fcntl.h>           /* For O_* constants */
#include <sys/stat.h>        /* For mode constants */
#include <semaphore.h>
struct msgbuf {
	
	long number;
	char name[20];
	
	};

int main()
{
	struct msgbuf buf;
	sem_t *sem;
	unsigned int size,ret1,ret;
	size = getpagesize();

	key_t key;
	key = ftok("creat",1);
	
	ret1 = shmget(key,size,IPC_CREAT);
	if(ret1 < 0)
	{
		perror("shmget:");
		exit(1);
	}
	 
	sem = sem_open("hello",O_CREAT);
	if(sem < 0)
	{
		printf("sem:");
		exit(2);
	}
	
	sem_wait(sem);
	
	ret = msgrcv(ret1,&buf,sizeof(buf.name),2,IPC_NOWAIT);
	if(ret < 0)
	{
		perror("msgsnd");
		exit(3);
	
	}
			
	printf("data received successfully\n");
	printf("%s",buf.name);
	sem_post(sem);	
	
	return 0;

}
