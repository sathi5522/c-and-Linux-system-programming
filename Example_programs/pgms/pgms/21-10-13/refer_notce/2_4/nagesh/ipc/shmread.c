#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/shm.h>
#define KEY 85000

int main()
{


	int id,*q = NULL,ret;
	void *p = NULL;
	unsigned int size = getpagesize();
	id = shmget(KEY,size,IPC_CREAT);
	if(id < 0){
		
		perror("shmget");
		exit(1);
	}
	
	p = shmat(id,NULL,0);
	if(p==NULL){
		perror("shmat");
		exit(2);
	}
	
	q=p;
	
	printf("%d\n",*q);

	ret = shmdt(p);
	if(ret < 0){

		perror("shmdt");
		exit(3);
	}

	printf("data is successully received");
	
	return 0;
}
