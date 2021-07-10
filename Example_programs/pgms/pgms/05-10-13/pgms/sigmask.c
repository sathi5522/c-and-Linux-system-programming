#include<stdio.h>
#include<signal.h>
#include<string.h>
void sig_han(int signo)
{
	printf("the sighandler :%d \n",signo);
	sleep(5);
	printf("the sighandler returned\n");
//larm(5);
	
}
int main()
{
	struct sigaction act;
	sigset_t sigmask;
	int r;

	printf("pid : %u\n", getpid());
	r = sigemptyset(&sigmask);
	printf("%d\n",r);
	
	r = sigaddset(&sigmask,4);
	printf("%d\n",r);
	
	r = sigaddset(&sigmask,3);
	printf("%d\n",r);
	
	memset(&act,0,sizeof(act));
	act.sa_sigaction = sig_han;
	act.sa_mask = sigmask;	

	printf("%x\n",sigmask);
	printf("%x\n",act.sa_mask);
	
	if(sigaction(SIGINT,&act,NULL) == -1)
		perror("sigaction");
//alarm(5);
	printf("test\n");
	for(;;);
//		printf("the test action\n");
	return 0;
}
