#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <errno.h>
#include <err.h>

void* fun(void *p)
{

	printf("thread function");
}

int main()
{

	int ret;
	pthread_t t1;

	ret = pthread_create(&t1,NULL,fun,NULL);
	if(ret != 0 )
	{
		perror("pthread_Creat:");
		//exit(1);
	}


	 ret = pthread_detach(t1);
	if(ret != 0)
	{
		printf("pthread_detach");
		//exit(2);
	}			
	
	sleep(2);

	ret = pthread_join(t1,NULL);
//	if(ret == EINVAL)
//	printf("fail");
	if(ret != 0)
	{

		perror("pthread_join");
		exit(3);
	}
	sleep(2);
	return 0;




}
