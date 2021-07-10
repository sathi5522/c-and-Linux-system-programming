#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


struct msg {

	int a;
	int b;
	}obj;

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;


void * threadfun1(void *p)
{

	pthread_rwlock_wrlock(&rwlock);
	obj.a = 10;
	obj.b = 20;
	pthread_rwlock_unlock(&rwlock);


}

void * threadfun2(void *p)
{

        pthread_rwlock_rdlock(&rwlock);
        
        printf("2obj.a = %d\n",obj.a);
	sleep(3);  
        printf("2obj.b = %d\n",obj.b);
        pthread_rwlock_unlock(&rwlock);


}

void * threadfun3(void *p)
{

        pthread_rwlock_rdlock(&rwlock);
        
        printf("3obj.a = %d\n",obj.a);
        printf("3obj.b = %d\n",obj.b);
        pthread_rwlock_unlock(&rwlock);


}






int main()
{
	int ret;
	pthread_t t1,t2,t3;

	ret = pthread_create(&t1,NULL,threadfun1,NULL);
	if(ret != 0)
	{
		printf("pthread_Create1 fails");
		exit(1);
	}

	ret = pthread_create(&t2,NULL,threadfun2,NULL);
	if(ret != 0)
	{
		printf("pthread_Create2 fails");
		exit(2);
	}

	ret = pthread_create(&t3,NULL,threadfun3,NULL);
	if(ret != 0)
	{
		printf("pthread_Create2 fails");
		exit(2);
	}

	
	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t3,NULL);


	return 0;




}
