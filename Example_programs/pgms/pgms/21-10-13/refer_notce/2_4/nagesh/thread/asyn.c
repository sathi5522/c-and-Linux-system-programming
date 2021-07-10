#include <stdio.h>
#include <signal.h>
#include <semaphore.h>
sem_t sem;

void fun(void)
{
	
	sem_wait(&sem);	
	printf("funtion starts");
//	sleep(5);
	getchar();
	printf("funtion ends\n");
	sem_post(&sem);
}



void sighand(int x)
{

	printf("signal handler is executing\n");
	fun();
	printf("signal handler is ending\n");


}
int main()
{

	sem_init(&sem,0,1);
	
//	sighandler_t sighand;
	signal(SIGINT,sighand);
	
	fun();
	
	return 0;

}
