#include<stdio.h>
#include<pthread.h>
int flag;
struct a{
	int a;
	int b;
}obj;
void *threadfun(void *arg)
{
	lock();
	obj.a = 10;
	obj.b = 20;
	unlock();
	return NULL;	
}

void *threadfun1(void *arg)
{
	lock();
	printf("the a value %d\n",obj.a);
	printf("the b value %d\n",obj.b);
	unlock();
	return NULL;	
}

int main()
{
	pthread_t t1;
	pthread_t t2;
	void *res;
	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_create(&t2,NULL,threadfun1,NULL);
	pthread_join(t1,&res);
	pthread_join(t2,&res);


	return 0;
}	

