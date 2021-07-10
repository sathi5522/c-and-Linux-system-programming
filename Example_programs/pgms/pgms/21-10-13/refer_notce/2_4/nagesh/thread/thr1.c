#include <stdio.h>
#include <pthread.h>
int glob = 1;

void * thread(void *p)
{
	int i = 0;
	int lim = *(int*)p;
	for(; i< lim; i++)
	{
		glob = glob + 1;
	}
	

}


int main()
{
	int ret,i = 100000000;	
	pthread_t th1,th2;
	
	ret = pthread_create(&th1,NULL,thread,&i);
	
	if(ret != 0)
	perror("pthread_create");

//	sleep(1);

	ret = pthread_create(&th2,NULL,thread,&i);
	
	if(ret != 0)
	perror("pthread_create");

	sleep(1);
	printf("%d\n",glob);
	pthread_exit(NULL);
	sleep(1);	
//	printf("glob = %d",glob);

	return 0;
}
