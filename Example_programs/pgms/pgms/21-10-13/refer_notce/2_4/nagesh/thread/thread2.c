#include <stdio.h>
#include <pthread.h>
int glob = 1;

void * thread(void *p)
{
	int i = 0;
	int lim = *(int*)p;
	for(; i< lim; i++)
	{
		__sync_fetch_and_add (&glob,1);
	}
	

}


int main()
{
	int ret,i = 100000000;	
	pthread_t th1,th2;
	
	ret = pthread_create(&th1,NULL,thread,&i);
	
	if(ret != 0)
	perror("pthread_create");



	ret = pthread_create(&th2,NULL,thread,&i);
	
	if(ret != 0)
	perror("pthread_create");

	pthread_join(th1, NULL);
	pthread_join(th2, NULL);
	printf("%d\n",glob);

	return 0;
}
