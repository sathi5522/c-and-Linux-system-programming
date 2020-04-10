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
	sigset_t mask;
	
	printf("pid : %u\n", getpid());

	memset(&act, 0, sizeof(act));
	act.sa_sigaction = sig_han;

	if(sigaction(SIGALRM, &act, NULL) == -1)
		perror("sigaction");
	sigemptyset(&mask);
	sigaddset(&mask,SIGTERM);
	sigaddset(&mask,SIGINT);
	if(sigprocmask(SIG_BLOCK, &mask, NULL) < 0) {
		perror("sigprocmask");
		return 1;
	}
	alarm(5);
	getchar();
	printf("test \n");
	getchar();
	sigprocmask(SIG_UNBLOCK, &mask, NULL);

	return 0;
}
