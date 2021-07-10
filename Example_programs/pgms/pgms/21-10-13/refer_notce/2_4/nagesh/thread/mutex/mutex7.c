#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
pthread_mutex_t glob;

struct msg {
	int a;
	int b;
	}obj;


void fun()
{
	int ret;
	ret =pthread_mutex_lock(&glob);
	if(ret != 0)
	{
		printf("thread is lock is not opend");
		exit(1);

	}


	printf("******lock opend******\n");
	pthread_mutex_unlock(&glob);
	
}



void* thread1(void *p)
{

	pthread_mutex_lock(&glob);
	obj.a = 10;
	fun();
	sleep(2);
	obj.b = 20;
	pthread_mutex_unlock(&glob);
	

}

void* thread2(void *p)
{

	pthread_mutex_lock(&glob);
	
	printf("obj.a  = %d\n",obj.a);
	printf("obj.b  = %d\n",obj.b);

	pthread_mutex_unlock(&glob);


}





int main()
{

	
	pthread_mutexattr_t attr;
	pthread_mutex_init(&glob,NULL);
	pthread_mutexattr_settype(&attr,PTHREAD_MUTEX_RECURSIVE);
	pthread_mutex_init(&glob,&attr);

	int ret;
	pthread_t t1,t2;
	
	ret = pthread_create(&t1,NULL,thread1,NULL);
	if(ret != 0)
	{
		printf("pthread_create1 failed");
		exit(1);
	}




	ret = pthread_create(&t2,NULL,thread2,NULL);
	if(ret != 0)
	{
		printf("pthread_create2 failed");
		exit(2);
	}


	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
}
