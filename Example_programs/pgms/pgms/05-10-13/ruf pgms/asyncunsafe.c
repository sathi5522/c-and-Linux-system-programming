#include<stdio.h>
#include<pthread.h>
#include <semaphore.h>
#include<signal.h>

sem_t flag;
void *threadfun(void *arg)
{
        sem_wait(&flag);

	getchar();   
 
        sem_post(&flag);
        return NULL;
}

void sig_hand(int signo)
{
	printf("handler\n");
	threadfun(NULL);
}

int main()
{
        pthread_t t1;
        void *res;
	struct sigaction act;

        sem_init(&flag, 0, 1);
	memset(&act, 0, sizeof(act));
	act.sa_handler = sig_hand;
	sigaction(2, &act, NULL);

	pthread_create(&t1,NULL,threadfun,NULL);
        
	threadfun(NULL);
	printf("main\n");
	
	getchar();
	
	threadfun(NULL);
	printf("main\n");
	
	pthread_join(t1,&res);

	return 0;
}
