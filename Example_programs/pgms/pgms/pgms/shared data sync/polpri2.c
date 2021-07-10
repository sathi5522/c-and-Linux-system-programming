#include<stdio.h>
#include<pthread.h>
pthread_t tid,tid1;
pthread_attr_t attr1,attr2;
struct sched_param param;
struct sched_param param1;
void *res,*res1;

void *thread(void *p)
{
	int policy,policy1;



	tid = pthread_self();
	tid1 = pthread_self();

	pthread_getattr_np(tid,&attr1);
	pthread_getattr_np(tid1,&attr2);

	pthread_attr_getschedpolicy(&attr1,&policy);
	printf("policy %d\n",policy);
	pthread_attr_getschedpolicy(&attr2,&policy1);
	printf("policy %d\n",policy1);

	pthread_attr_getschedparam(&attr1,&param);
	printf("priority %d\n",param.sched_priority);
	pthread_attr_getschedparam(&attr2,&param1);
	printf("priority %d\n",param1.sched_priority);
	return NULL;
}

int main()
{


	param.sched_priority = 60;

	pthread_attr_init(&attr1);

	pthread_attr_setschedpolicy(&attr1,SCHED_RR);


	pthread_attr_setinheritsched(&attr1,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedparam(&attr1,&param);
	pthread_create(&tid,&attr1,thread,NULL);

	pthread_join(tid,&res);
	param1.sched_priority = 70;

	pthread_attr_init(&attr2);

	pthread_attr_setschedpolicy(&attr2,SCHED_FIFO);


	pthread_attr_setinheritsched(&attr2,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedparam(&attr2,&param1);
	pthread_create(&tid1,&attr2,thread,NULL);

	pthread_join(tid1,&res1);
	
	return 0;
}
