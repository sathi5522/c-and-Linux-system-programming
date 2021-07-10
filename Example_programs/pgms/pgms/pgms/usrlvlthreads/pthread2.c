#include<stdio.h>
#include<pthread.h>
#include<string.h>
static void *threadfun(void *arg)
{
	char *s = (char *)arg;
	static int a;
	printf("child1:%s\n",s);

	a = strlen(s);
	pthread_exit(&a);

}
static void *threadfun1(void *arg)
{
	
	pthread_t t1;
	void *res;
	//int *s = (int *)arg;
	pthread_create(&t1,NULL,threadfun,"hello world");
	pthread_join(t1,&res);
	printf("child2 %d\n",*(int *)res);
	pthread_exit(NULL);

}
int main()
{

	pthread_t t2;
	void *res;
	int ret;

	ret = pthread_create(&t2,NULL,threadfun1,NULL);
	pthread_join(t2,&res);
	printf("message from main\n");
	printf("pthread-join\n");
	
	return 0;
}
