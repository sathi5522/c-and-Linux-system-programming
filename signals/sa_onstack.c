#include<stdio.h>
#include<signal.h>
#include<string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdlib.h>

void sig_han(int signo,siginfo_t *obj,void *p)
{
	printf("the sighandler address : %p\n",obj->si_addr);
	exit(1);
}

void fun(int a)
{
	printf("the call value: %d\n",a);
	fun(a);
}

int main()
{
	char rbuf[5];
	struct sigaction act;
	stack_t sigstack;
	
	sigstack.ss_sp = malloc(SIGSTKSZ);
	sigstack.ss_size = SIGSTKSZ;
	sigstack.ss_flags = 0;

	memset(&act, 0, sizeof(act));
	act.sa_sigaction = sig_han;
	act.sa_flags = SA_ONSTACK | SA_SIGINFO;

	if(sigaltstack(&sigstack, NULL) == -1)
		perror("sigalt stack");

	if(sigaction(11, &act, NULL) == -1)
		perror("sigaction");
	printf("test \n");
	fun(100000);

	return 0;
}
