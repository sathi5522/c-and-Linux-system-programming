#include<stdio.h>
#include<signal.h>
#include<unistd.h>


void sig_hand(int signum)
{

	printf("signal handler function\n");
	return;
}

int main()
{
	
	siginfo_t info;
	sigset_t set;
	struct timespec time;

	sigemptyset(&set);
	
	sigaddset(&set, SIGALRM);
	sigaddset(&set, SIGINT);

	sigprocmask(SIG_BLOCK, &set, NULL);

	time.tv_sec = 20;
	time.tv_nsec =0;
	printf("%d\n", getpid());

	sigtimedwait(&set, &info, &time);

	printf("%d signal has invoked and executing process\n", info.si_signo);

	return 0;
}

