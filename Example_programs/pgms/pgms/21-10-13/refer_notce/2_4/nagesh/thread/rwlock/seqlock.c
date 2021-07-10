#include <stdio.h>
#include <pthread.h>
#include <stdlib.h>
struct msg {
	int a;
	int b;
	
	}obj;


struct cond{
	pthread_mutex_t mutex;
	int glob;
}cond_obj;


int check;

int getstatus()
{
	return cond_obj.glob;
}


void* threadfun1(void *p)
{

	pthread_rwlock_wrlock(&cond_obj.rwlock);
	
	obj.a  = 20;
	obj.b  = 30;
	cond_obj.glob++;
	check++;
	pthread_rwlock_unlock(&cond_obj.rwlock);

}




void* threadfun2(void *p)
{

        pthread_rwlock_wrlock(&cond_obj.rwlock);
        
        obj.a  = 40;
        obj.b  = 50;
        cond_obj.glob++;
	check++;
        pthread_rwlock_unlock(&cond_obj.rwlock);

}




void* threadfun3(void *p)
{
	int old,new;
	while(check == 0);
        do{
        old = getstatus();
        printf("obj.a = %d\n",obj.a);
        printf("obj.b = %d\n",obj.b);
        new = getstatus();
	}while(old != new);
                
}







int main()
{

	int ret;
	pthread_t t1,t2,t3;
	
	ret = pthread_create(&t1,NULL,threadfun1,NULL);
	if(ret != 0)
	{
		printf("pthread_create1 is failure\n");	
		exit(1);
	
	}
	
	ret = pthread_create(&t2,NULL,threadfun2,NULL);
	if(ret != 0)
	{
		printf("pthread_create1 is failure\n");	
		exit(2);
	
	}

	
	ret = pthread_create(&t3,NULL,threadfun3,NULL);
	if(ret != 0)
	{
		printf("pthread_create1 is failure\n");	
		exit(3);
	
	}

	pthread_join(t1,NULL);
	pthread_join(t2,NULL);
	pthread_join(t2,NULL);

	return 0;

	
}

