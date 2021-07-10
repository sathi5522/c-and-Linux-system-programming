#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
#include <string.h>
struct msg {

	char buf[20];
	int len;
	};

void *threadfun(void *p)
{
      
	printf("buf : %s",(*(struct msg *)p).buf);
	printf("%d\n", ((struct msg *)p)->len);
}



int main()
{
	int ret;
	void *r;
	pthread_t t1;
	struct msg a;
	strcpy(a.buf,"nagesh");
	a.len = strlen(a.buf);
	ret = pthread_create(&t1,NULL,threadfun,&a);

	if(ret != 0)
	{
	 perror("pthread_create : ");
	 exit(1);
	
	}
	
//	sleep(1);
	ret = pthread_join(t1,NULL);

	
	return 0;


}

