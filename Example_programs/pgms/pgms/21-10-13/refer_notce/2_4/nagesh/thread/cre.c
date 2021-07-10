#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>


void *threadfun(void *p)
{

	printf("thread executing\n");
	printf("%d\n",*(int *)(p));
}



int main()
{
	int ret;
	pthread_t t1;

	int a =2;	
	ret = pthread_create(&t1,NULL,threadfun,&a);

	if(ret != 0)
	{
	 perror("pthread_create : ");
	 exit(1);
	
	}
	
	sleep(1);
	//ret = pthread_join(t1,NULL);

	return 0;



}

