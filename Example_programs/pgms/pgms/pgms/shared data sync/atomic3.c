#include<stdio.h>
#include<pthread.h>

struct a{
	int a;
	int b;
}obj;
int flag;
void *threadfun(void *arg)
{
	while(flag !=0);
	__sync_fetch_and_add (&flag,1);
	obj.a = 10;
	obj.b = 20;
	__sync_fetch_and_sub (&flag,1);
	return NULL;	
}

void *threadfun1(void *arg)
{
	while(flag != 0);
	__sync_fetch_and_add (&flag,1);
	printf("the a value %d\n",obj.a);
	printf("the b value %d\n",obj.b);
	__sync_fetch_and_sub (&flag,1);
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

