#include<stdio.h>
#include<pthread.h>
void *thread(void *p)
{
	int policy;
	struct sched_param param;
	pthread_attr_t attr;
	pthread_t tid;
	tid = pthread_self();
	pthread_getattr_np(tid,&attr);
	pthread_attr_getschedpolicy(attr,&policy);
	printf("policy %d\n",policy);
	pthread_getschedparam(&attr,&param);
	printf("priority %d\n",param.sched_priority);
}

int main()
{
	pthread_t tid;
	pthread_attr_t attr;
	pthread_create(&tid,&attr,thread,NULL);
	pthread_join(tid,NULL);
	
	return 0;
}
