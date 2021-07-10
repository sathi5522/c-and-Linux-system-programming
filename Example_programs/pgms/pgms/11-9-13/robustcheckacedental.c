#include<stdio.h>
#include<pthread.h>
pthread_mutex_t mutex;

void *threadfun1(void *arg)
{

        printf("thread 1 started\n");
        pthread_mutex_lock(&mutex);
        sleep(4);
        printf("thread1 acquired mutex\n");
        pthread_mutex_unlock(&mutex);
        printf("thread 1 released mutex object\n");
        return NULL;
}

void *threadfun2(void *arg)
{
        sleep(1);
        printf("thread 2 started \n");
        if(!pthread_mutex_unlock(&mutex))
                printf("error reporting on unauthorized unlock\n");
        pthread_mutex_lock(&mutex);
        printf("thread 2 acquired mutex\n");
        pthread_mutex_unlock(&mutex);
        printf("thread 2 release mutex object\n");
        return NULL;
}


int main()
{
        pthread_t t1, t2;
        void *res;
	pthread_mutexattr_t attr;
	pthread_mutexattr_init(&attr);
	pthread_mutexattr_setrobust_np((&attr, PTHREAD_MUTEX_ROBUST_NP));
	pthread_mutex_init(&mutex, &attr);// dynamically assigning 

	pthread_create(&t1,NULL,threadfun1,NULL);
        pthread_create(&t2,NULL,threadfun2,NULL);

        pthread_join(t1, &res);
        pthread_join(t2, &res);

        return 0;
}

