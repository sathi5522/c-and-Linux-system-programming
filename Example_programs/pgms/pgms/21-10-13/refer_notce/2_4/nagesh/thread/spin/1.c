#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

pthread_spinlock_t spin = PTHREAD_PROCESS_SHARED;

struct msg {
		int a;
		int b;
	}obj;


void* threadfun1(void *p)
{

	pthread_spin_lock(&spin);
	obj.a = 20;
	obj.b = 30;
	pthread_spin_unlock(&spin);
	

}

void* threadfun2(void *p)
{


	pthread_spin_lock(&spin);
	printf("obj.a = %d\n",obj.a);
	printf("obj.b = %d\n",obj.b);
	pthread_spin_unlock(&spin);


}


int main()
{

	int ret;
	pthread_t t1,t2;
	
	ret = pthread_create(&t1,NULL,threadfun1,NULL);
	if(ret != 0)
	{
		printf("pthread_Create2 is failed\n");
		exit(1);

	}

	ret = pthread_create(&t2,NULL,threadfun2,NULL);
	if(ret != 0)
	{
		printf("pthread_create2 is failed");
		exit(2);
	}


	pthread_join(t1,NULL);
	pthread_join(t2,NULL);

	return 0;
}
