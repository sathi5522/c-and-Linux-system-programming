#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include "header.h"
glob_t glob;
struct msg{
	int a;
	int b;
	}obj;


void * thread2(void *q)
{
	lock(&glob);
	printf("t1 : %d\n",glob);
	printf("%d\n",obj.a);
	printf("%d\n",obj.b);
	unlock(&glob);
}

void * thread1(void *p)
{


	lock(&glob);
	printf("t2 :%d\n",glob);
	obj.a = 20;
	sleep(5);
	obj.b = 30;
	unlock(&glob);

}


int main()
{
	int ret;
	pthread_t th1,th2;

	ret = pthread_create(&th1,NULL,thread1,NULL);
	
	if(ret != 0)
	{
		perror("pthread_creat1: ");
		exit(1);
	}

	
	ret = pthread_create(&th2,NULL,thread2,NULL);
	
	if(ret != 0)
	{
		perror("pthread_create2");
		exit(2);
	}
	
	pthread_exit(NULL);

}
