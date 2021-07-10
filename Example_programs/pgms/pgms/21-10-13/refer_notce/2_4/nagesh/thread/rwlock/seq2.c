#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <semaphore.h>
struct msg {
		int a;
		int b;
	}obj;

struct cond{
		int check;
		sem_t sem;
	}con;

int getstatus()
{

	return con.check;

}

void* threadfun1(void *p)
{
	sem_wait(&con.sem);
	obj.a = 20;
	obj.b = 30;
	 __sync_fetch_and_add(&con.check,1);
	sem_post(&con.sem);


}


void* threadfun2(void *p)
{

	sem_wait(&con.sem);
	obj.a = 40;
	obj.b = 50;
	 __sync_fetch_and_add(&con.check,1);
	sem_post(&con.sem);

}


void* threadfun3(void *p)
{
	int new,old;
		
	do{
		old = getstatus();
		printf("obj.a = %d\n",obj.a);
		printf("obj.b = %d\n",obj.b);
		new = getstatus();
		
	}while(new != old);

	
} 





int main()
{
	int ret;
	pthread_t t1,t2,t3;
	sem_init(&con.sem,0,1);

	ret = pthread_create(&t1,NULL,threadfun1,NULL);
	if(ret != 0)
	{
		printf("pthread_create1 is  failure\n");
		exit(1);
	}



	ret = pthread_create(&t2,NULL,threadfun2,NULL);
	if(ret != 0)
	{
		printf("pthread_Create2 is failure\n");
		exit(2);
	}

	
	ret = pthread_create(&t3,NULL,threadfun3,NULL);
	if(ret != 0)
	{
		printf("pthread_Create3 is failure\n");
		exit(3);
	}

	
	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);

	return 0;

}
