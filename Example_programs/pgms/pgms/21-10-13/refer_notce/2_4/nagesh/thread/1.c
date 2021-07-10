#include <stdio.h>
#include <pthread.h>
#include<string.h>

struct msg {
		char buf[20];
		int len;
	};



void * threadfun(void *p)
{
	//struct msg *q;
	//q = *p;
	printf("%d\n",*(struct msg*)p->len);
	

}


int main()
{
	int ret;	
	pthread_t t;
	struct msg obj ;
	strcpy("hello",obj.buf);
	obj.len = strlen(obj.buf);

	ret = pthread_create(&t,NULL,threadfun,&obj);
	
	pthread_join(t,NULL);
	return 0;
	



}
