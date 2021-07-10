#include<stdio.h>
#include<signal.h>
#include<string.h>
void sig_han(int signo)
{
	printf("the sighandler :%d \n",signo);
	printf("the pid :%d\n",getpid());
}
int main()
{
	struct sigaction act;
	memset(&act,0,sizeof(act));
	act.sa_handler = sig_han;	
	sigaction(2,&act,NULL);
	printf("test\n");
	getchar();	
	return 0;
}
