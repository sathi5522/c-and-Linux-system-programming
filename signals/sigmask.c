#include<stdio.h>
#include<signal.h>
#include<string.h>
#include <unistd.h>

void sig_han(int signo,siginfo_t *obj,void *p)
{
	printf("the sighandler : %d\n",signo);
	sleep(5);
	printf("exit handler\n");
}

int main()
{
	struct sigaction act;
	sigset_t sigmask;
	
	printf("pid : %u\n", getpid());
	sigemptyset(&sigmask);
	sigaddset(&sigmask,4);
	sigaddset(&sigmask,3);

	memset(&act, 0, sizeof(act));
	act.sa_sigaction = sig_han;
	act.sa_mask = sigmask;

	if(sigaction(2, &act, NULL) == -1)
		perror("sigaction");
	printf("test \n");
	for(;;);

	return 0;
}
