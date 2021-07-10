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
	struct msgbuf buf , *shmaddr;
	
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
	 
	sem = sem_open("hello",O_CREAT,0777,1);
	if(sem < 0)
	{
		printf("sem:");
		exit(2);
	}
	
	
	shmaddr =  shmat(ret1,NULL,NULL);
	
	sem_wait(sem);
	
	shmaddr->number = 20;
	ret = strcpy(shmaddr->name,"nagesh");
	if(ret < 0)
	{
		perror("strcpy");
		exit(3);
	}

	printf("data successfully send");

	sem_post(sem);	
	
	return 0;

}
