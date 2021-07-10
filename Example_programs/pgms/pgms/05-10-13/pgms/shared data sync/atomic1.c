#include<stdio.h>
#include<pthread.h>
int gbl;

void *threadfun(void *arg)
{
	int *j1=(int *)arg;
	int j;
	for(j = 0;j<*j1;j++) {
	 	__sync_fetch_and_add (&gbl,1);
		 
	}
}


int main()
{
	pthread_t t1;
	pthread_t t2;
	int loc = 100000;
	void *res;
	pthread_create(&t1,NULL,threadfun,&loc);
	pthread_create(&t2,NULL,threadfun,&loc);
	pthread_join(t1,&res);
	pthread_join(t2,&res);

	printf("global value %d \n",gbl);

	return 0;
}	

