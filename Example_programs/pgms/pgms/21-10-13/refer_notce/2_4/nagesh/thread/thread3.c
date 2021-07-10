#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
int glob ;

struct msg{
	int a;
	int b;
	}obj;


void * thread2(void *q)
{

	while(glob != 0);
	glob =1;
	printf("%d\n",obj.a);
	printf("%d\n",obj.b);
	glob = 0;
}

void * thread1(void *p)
{

	while(glob != 0);
	glob =1;
	obj.a = 20;
	sleep(5);
	obj.b = 30;
	glob = 0;

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
