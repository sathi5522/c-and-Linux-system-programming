#include<stdio.h>
#include<pthread.h>

struct a{
	int a;
	int b;
}obj;

void *threadfun(void *arg)
{
	
	obj.a = 10;
	sleep(3);
	obj.b = 20;
	return NULL;	
}

void *threadfun1(void *arg)
{
	printf("the a value %d\n",obj.a);
	sleep(1);
	printf("the b value %d\n",obj.b);
	return NULL;	
}
void *threadfun2(void *arg)
{
	
	sleep(5);
	printf("the a value %d\n",obj.a);

	printf("the b value %d\n",obj.b);
	return NULL;	
}

int main()
{
	pthread_t t1;
	pthread_t t2,t3;
	void *res;
	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_create(&t2,NULL,threadfun1,NULL);
	pthread_create(&t3,NULL,threadfun2,NULL);
	pthread_join(t1,&res);
	pthread_join(t2,&res);
	pthread_join(t3,&res);


	return 0;
}	

