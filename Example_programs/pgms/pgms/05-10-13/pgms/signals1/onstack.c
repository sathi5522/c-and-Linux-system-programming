#include<stdio.h>
#include<signal.h>
#include<string.h>
#include<stdlib.h>
void sig_han(int signo,siginfo_t *obj,void *p)
{
	printf("the sighandler :%d \n",obj->si_signo);
}
int sig_stack(stack_t *sigstack1,stack_t *p)
{
	printf("the stack is :%d\n",sigstack1->ss_size);
}
void fun(int a)
{
	printf("the call value :%d\n",a);
	fun(++a);
}
int main()
{

	struct sigaction act;
	stack_t  sigstack;
	sigstack.ss_sp = malloc(SIGSTKSZ);
	 if (sigstack.ss_sp == NULL)
		perror("handler");
	sigstack.ss_size =SIGSTKSZ;
	sigstack.ss_flags = 0;
	memset(&act,0,sizeof(act));
	act.sa_sigaction = sig_han;
	act.sa_flags = SA_ONSTACK;	
	if(sigaltstack(&sigstack,NULL) == -1)
		perror("sigaltstack");
	if(sigaction(11,&act,NULL) == -1)
		perror("sigaction");

	printf("test\n");
	getchar();
	fun(1);
	return 0;
}
