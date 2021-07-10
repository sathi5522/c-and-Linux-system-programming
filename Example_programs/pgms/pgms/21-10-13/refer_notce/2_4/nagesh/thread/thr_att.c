#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>

void * threadfun(void *p)
{

	int ret;
	pthread_t tid;
	int policy;
	pthread_attr_t attr;
	tid = pthread_self();
	ret = pthread_getattr_np(tid,&attr);
	pthread_attr_getschedpolicy(&attr,&policy);	
	printf("%d\n",policy);

}




int main()
{
	
	int ret;

	pthread_t t;
	
	pthread_attr_t attr;

	pthread_attr_init(&attr);
	
	ret = pthread_create(&t,&attr,threadfun,NULL);

	if(ret != 0)
	{
		printf("pthread_create:");
		exit(1);
	}	


	pthread_join(t,NULL);

	return 0;


}

