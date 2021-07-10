#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
#include<errno.h>
//#include<sched.h>

pthread_mutex_t mutex;
void recover(void) 
{
	pthread_mutex_consistent_np(&mutex);
	pthread_mutex_unlock(&mutex);
}
void *threadfun(void *arg)
{
	printf("thread1 started\n");
	pthread_mutex_lock(&mutex);
	printf("thread1 after locking\n");
	sleep(5);
	printf("test\n");

	pthread_exit(NULL);
	return NULL;	
}

void *threadfun1(void *arg)
{
	int ret;
	sleep(1);
	printf("thread2 started\n");
	ret = pthread_mutex_lock(&mutex);
	if(ret == EOWNERDEAD) {
		printf("the owner dead :%ld\n",pthread_self());
		recover();
	}
	printf("thread2 after locking\n");
	pthread_mutex_unlock(&mutex);

	return NULL;	
}

int main()
{
	pthread_t t1;
	pthread_t t2;
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_setrobust_np(&attr,PTHREAD_MUTEX_ROBUST_NP);
	pthread_mutex_init(&mutex,&attr);
	pthread_create(&t1,NULL,threadfun,NULL);
	pthread_create(&t2,NULL,threadfun1,NULL);

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);


	return 0;
}	

