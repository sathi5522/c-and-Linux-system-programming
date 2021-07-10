#include<stdio.h>
#include<pthread.h>
pthread_t tid;
pthread_attr_t attr;
struct sched_param param;
void *res;

void *thread(void *p)
{
	int policy;



	tid = pthread_self();

	pthread_getattr_np(tid,&attr);

	pthread_attr_getschedpolicy(&attr,&policy);
	printf("policy %d\n",policy);

	pthread_attr_getschedparam(&attr,&param);
	printf("priority %d\n",param.sched_priority);
	return NULL;
}

int main()
{


	param.sched_priority = 60;

	pthread_attr_init(&attr);

	pthread_attr_setschedpolicy(&attr,SCHED_RR);


	pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setschedparam(&attr,&param);
	pthread_create(&tid,&attr,thread,NULL);

	pthread_join(tid,&res);
	
	return 0;
}
