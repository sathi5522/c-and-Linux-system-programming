#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>

void *thread2 (void *p)
{
	static int a;
	a = 11;
	pthread_exit(&a);


}


void * thread1(void *p)
{	

	static int b;
	pthread_t t2;
	int ret;
	void *ret_val=NULL ;

	ret = pthread_create(&t2,NULL,thread2,NULL);
	b =  strlen((char *)p);
	pthread_join(t2,&ret_val);
	printf("thread 2 return value is : %d\n",*(int *)(ret_val));
//	printf("%d\n",a);
	return &b;

}



int main()
{
	int ret;
	void *res;
	pthread_t t;
	

	ret = pthread_create(&t,NULL,thread1,"hello");
	if(ret != 0)
	{
		perror("pthread_create:");
		exit(1);

	}	


	pthread_join(t,&res);

	printf("%d\n",*(int *)res);

	pthread_exit(NULL);
	return 0;
		
}
