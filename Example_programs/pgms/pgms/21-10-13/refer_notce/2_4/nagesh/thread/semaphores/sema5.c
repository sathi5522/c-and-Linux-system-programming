#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
struct msg {
	int a;
	int b;
	}obj;

pthread_mutex_t  sem;




void* thread1(void *p)
{
//	sem_post(&sem);
	pthread_mutex_lock(&sem);
	obj.a = 10;
	sleep(2);
	obj.b = 20;
	pthread_mutex_unlock(&sem);		


}

void* thread2(void *p)
{
	int ret;
	sleep(1);
	ret = 	pthread_mutex_unlock(&sem);
	if(ret != 0)
	{
		perror("pthread_unlock:");
	}

	pthread_mutex_lock(&sem);
	printf("a = %d\n",obj.a);
	printf("b = %d\n",obj.b);
	pthread_mutex_unlock(&sem);

	
}



int main()
{
	int ret;
	pthread_t th1,th2;

	pthread_mutex_init(&sem,NULL);
	ret = pthread_create(&th1,NULL,thread1,NULL);
	if(ret != 0 )
	{
		perror("pthread_Create:");
		exit(1);
	}


	ret = pthread_create(&th2,NULL,thread2,NULL);
	if(ret != 0)
	{
		perror("pthread_create2:");
		exit(2);
	}


	pthread_join(th1,NULL);
	pthread_join(th2,NULL);	

	
	return 0;
}
