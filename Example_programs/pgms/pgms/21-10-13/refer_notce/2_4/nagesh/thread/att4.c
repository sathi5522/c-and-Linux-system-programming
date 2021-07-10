#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
void * threadfun1(void *p)
{
//      sleep(2);
        int ret;
        pthread_t tid;
        int policy;
        struct sched_param pri;

        pthread_attr_t attr;
        pthread_attr_init(&attr);
        tid = pthread_self();
        ret = pthread_getattr_np(tid,&attr);
        pthread_getschedparam(tid,&policy,&pri);
//      pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
//      pthread_attr_getschedpolicy(&attr,&policy);     
//      pthread_attr_getschedparam(&attr,&pri);
        printf("policy %d\n",policy);
        printf("priority %d\n",pri.sched_priority);



}




void * threadfun(void *p)
{
//	sleep(2);
	int ret;
	pthread_t tid;
	int policy;
	struct sched_param pri;
	
	pthread_attr_t attr;
	pthread_attr_init(&attr);
	tid = pthread_self();
	ret = pthread_getattr_np(tid,&attr);
	pthread_getschedparam(tid,&policy,&pri);		
//	pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
//	pthread_attr_getschedpolicy(&attr,&policy);	
//	pthread_attr_getschedparam(&attr,&pri);
	printf("policy %d\n",policy);
	printf("priority %d\n",pri.sched_priority);



}




int main()
{
	
	int ret;
	struct sched_param a = {10};	

	struct sched_param b = {20};	
	pthread_t t,t2;
	
	pthread_attr_t attr,attr2;

	pthread_attr_init(&attr);
	pthread_attr_init(&attr2);

	
	pthread_attr_setinheritsched(&attr2,PTHREAD_EXPLICIT_SCHED);
	pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
//	pthread_attr_setschedpolicy(&attr,2);
//	pthread_attr_setschedparam(&attr,&a); 
	ret = pthread_create(&t,&attr,threadfun,NULL);
	pthread_setschedparam(t,1,&a);	
	ret = pthread_create(&t2,&attr,threadfun1,NULL);
	pthread_setschedparam(t2,2,&b);	
	if(ret != 0)
	{
		perror("pthread_create:");
		exit(1);
	}	
	
	sleep(1);


//	pthread_attr_setinheritsched(&attr,PTHREAD_EXPLICIT_SCHED);
//	pthread_attr_setschedpolicy(&attr,2);
//	pthread_attr_setschedparam(&attr,&a);i

	pthread_join(t,NULL);

	return 0;


}

