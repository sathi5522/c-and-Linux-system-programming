#include<stdio.h>
#include<pthread.h>
#include<string.h>
struct msg {
	char buf[20];
	int len;
};
static void *threadfun(void *arg)
{
	struct msg *s1 = (struct msg *)arg;
	printf("%s\n",s1->buf);
	printf("%d\n",s1->len);
	pthread_exit(NULL);
}
int main()
{
	pthread_t t1;
	void *res;
	int ret;
	struct msg s = {"hello",5};
	ret = pthread_create(&t1,NULL,threadfun,&s);
	printf("message from main\n");
	ret = pthread_join(t1,&res);
	printf("pthread-join\n");
	
	return 0;
}
