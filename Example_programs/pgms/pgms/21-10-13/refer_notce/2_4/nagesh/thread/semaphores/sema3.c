#include <stdio.h>
#include <semaphore.h>
#include <pthread.h>
#include <stdlib.h>
struct msg {
	int a;
	int b;
	}obj;
sem_t sem;




void* thread1(void *p)
{
//	sem_post(&sem);
	sem_wait(&sem);
	obj.a = 10;
	pthread_exit(NULL);
	obj.b = 20;
	sem_post(&sem);		


}

void* thread2(void *p)
{

	sem_wait(&sem);

	printf("a = %d\n",obj.a);
//	sleep(2);
	printf("b = %d\n",obj.b);
	sem_post(&sem);

	
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
