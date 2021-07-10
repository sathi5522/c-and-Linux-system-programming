#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
int avial;
pthread_mutex_t sem = PTHREAD_MUTEX_INITIALIZER;
pthread_cond_t cond = PTHREAD_COND_INITIALIZER;
struct msg {

	int a;
	int b;
	}obj;

void* threadfun1(void *p)
{
	pthread_mutex_lock(&sem);
	obj.a = 20;
	sleep(2);
	obj.b = 30;
	__sync_fetch_and_add(&avial,1);
	
	pthread_mutex_unlock(&sem);
	pthread_cond_signal(&cond);
	
}



void* threadfun2(void *p)
{

	if(avial != 1)
	{
		pthread_cond_wait(&cond,&sem);
	}
		
	printf("obj.a = %d\n",obj.a);
	printf("obj.b = %d\n",obj.b);


}


int main()
{
	
	int ret;
	pthread_t t1,t2;
	
	ret = pthread_create(&t1,NULL,threadfun1,NULL);
	if(ret != 0)
	{
		printf("pthread_creat1 is failed\n");
		exit(1);
	
	}


	ret = pthread_create(&t2,NULL,threadfun2,NULL);
	if(ret != 0)
	{
		printf("pthread_creat1 is failed\n");
		exit(1);
	
	}


	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	
	return 0;
}




