#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
struct msg {
	int a;
	int b;
	}obj;
sem_t sem;

//sem_init(&sem,0,0);


void* thread1(void *p)
{
	sem_wait(&sem);
//	sem_post(&sem);
	obj.a = 10;
	sleep(2);
	obj.b = 20;
	sem_post(&sem);		
//	sem_wait(&sem);	

}

void* thread2(void *p)
{

	sem_wait(&sem);
//	sem_post(&sem);
	printf("a = %d\n",obj.a);
	printf("b = %d\n",obj.b);
	sem_post(&sem);

//	sem_wait(&sem);
}



int main()
{
	int ret;
	pthread_t th1,th2;

	sem_init(&sem,0,1);
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
