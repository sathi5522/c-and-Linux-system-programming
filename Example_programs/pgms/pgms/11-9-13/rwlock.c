#include<stdio.h>
#include<pthread.h>
#include<semaphore.h>
struct glo {
	int a;
	int b;
}ob;

pthread_rwlock_t rwlock = PTHREAD_RWLOCK_INITIALIZER;

static void*writefunc1(void *arg)

{

	if(pthread_rwlock_wrlock(&rwlock)!=0)
	{
	printf("error writing data\n");
	}
	else
	{
	printf("accessing the data t1\n");
	ob.a = 10;
//	sleep(2);
	ob.b = 20;
//	sleep(2);
//	pthread_exit(NULL);

	printf("releasing the data t1\n");
	sleep(1);
	pthread_exit(NULL);
	}
	return NULL;
}

static void *readfunc2(void *arg)

{	sleep(1);
	if(pthread_rwlock_rdlock(&rwlock)!=0)
	{
	printf("error reading data:%ld\n",pthread_self());
	}
	else
	{
	//pthread_rwlock_rdlock(&rwlock);
//	pthread_mutex_lock(&mu);
	printf("accesing the data t2\n");
	printf("a value is %d\n",ob.a);
	printf("b value is %d\n",ob.b);
	printf("releasing the data t2\n");
//	pthread_mutex_unlock(&mu);
	sleep(2);
	pthread_exit(NULL);
	}
	return NULL;

}
static void *readfunc3(void *arg)

{	sleep(5);
	//pthread_rwlock_rdlock(&rwlock);
        printf("a value is %d\n",ob.a+1);
        printf("b value is %d\n",ob.b+5);

	pthread_exit(NULL);
        return NULL;
}


int main()

{
//	pthread_mutex_init(&mu,NULL);
	pthread_t t1,t2,t3;
	int ret;
	ret = pthread_create(&t1,NULL,writefunc1,NULL);
	ret = pthread_create(&t2,NULL,readfunc2,NULL);
	ret = pthread_create(&t3,NULL,readfunc3,NULL);
	ret = pthread_join(t1,NULL);
	ret = pthread_join(t2,NULL);
	ret = pthread_join(t3,NULL);

	return 0;
}
